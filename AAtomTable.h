/* AAtomTable
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/AtomTable.h
 */

#ifndef AAtomTable_H
#define AAtomTable_H

#include "ABase"

/*
#include <iostream>
#include <vector>

#include <boost/signal.hpp>

#include <opencog/atomspace/TLB.h>
#include <opencog/atomspace/TruthValue.h>
#include <opencog/atomspace/AttentionValue.h>
#include <opencog/atomspace/FixedIntegerIndex.h>
#include <opencog/atomspace/HandleEntry.h>
#include <opencog/atomspace/HandleIterator.h>
#include <opencog/atomspace/ImportanceIndex.h>
#include <opencog/atomspace/Link.h>
#include <opencog/atomspace/LinkIndex.h>
#include <opencog/atomspace/Node.h>
#include <opencog/atomspace/NodeIndex.h>
#include <opencog/atomspace/PredicateEvaluator.h>
#include <opencog/atomspace/PredicateIndex.h>
*/

#include "AAtomTypeIndex.h"

/*
#include <opencog/atomspace/TargetTypeIndex.h>
#include <opencog/atomspace/types.h>
#include <opencog/util/Logger.h>
#include <opencog/util/RandGen.h>
#include <opencog/util/exceptions.h>
#include <opencog/util/platform.h>
*/

/*
struct atom_ptr_hash : public std::unary_function<const Atom*, std::size_t>
{
    std::size_t operator()(const Atom* const& __x) const;
};

struct atom_ptr_equal_to : public std::binary_function<const Atom*, const Atom*, bool>
{
    bool operator()(const Atom* const& __x, const Atom* const& __y) const;
};
*/

typedef AInt AtomHashSet;
//typedef boost::unordered_set<const Atom*, atom_ptr_hash, atom_ptr_equal_to> AtomHashSet;

//class SavingLoading;

typedef AInt AHandleIteratorVector;
//typedef std::vector<HandleIterator*> AHandleIteratorVector;

/** This class provides mechanisms to store atoms and keep indices for
 *  efficient lookups. It implements the local storage data structure of
 *  OpenCog. It contains methods to add and remove atoms, as well as to
 *  retrieve specific sets according to different criteria.
 */
typedef struct {
    // --- private ---

    int size;

    /** Lookup table ... XXX is this really needed? The various indexes
     *  below should be enough, maybe? This should probably be eliminated if possible.
     */
    AtomHashSet atomSet;

    /** Indicates whether DynamicStatisticsAgent should be used
     *  for atoms inserted in this table or not.
     */
    ABoolean useDSA;

    /** Indexes for quick retreival of certain kinds of atoms. */
    ATypeIndex typeIndex;
    NodeIndex nodeIndex;
    LinkIndex linkIndex;
    ImportanceIndex importanceIndex;
    TargetTypeIndex targetTypeIndex;
    PredicateIndex predicateIndex;

    /** iterators, used in an (incomplete) attempt at thread-safety. */
    AHandleIteratorVector iterators;

    #ifdef HAVE_LIBPTHREAD
    pthread_mutex_t iteratorsLock;
    #endif

    /** Signal connection used to keep track of atom type addition in the ClassServer */
    boost::signals::connection addedTypeConnection;

} AtomTable_Type;

typedef AtomTable_Type* AtomTable;

// --- class AtomTable ---
/*
friend class ImportanceUpdatingAgent;
friend class SavingLoading;
friend class AtomSpace;
friend class AtomSpaceImpl;
friend class HandleIterator;
friend class ::AtomTableUTest;
*/

// --- private ---

void
afunc AAtomTable_LockIterators(AAtomTable AtomTable);

void
afunc AAtomTable_UnlockIterators(AAtomTable AtomTable);

/** Handler of the 'type added' signal from ClassServer */
void
afunc AAtomTable_TypeAdded(AAtomTable AtomTable, Type);

bool
afunc AAtomTable_Decayed(Handle h);

// Warning, this should only be called by decayShortTermImportance
void
afunc AAtomTable_ClearIndexesAndRemoveAtoms(AAtomTable AtomTable, HandleEntry* extractedHandles);

/** Extracts atoms from the table. Table will not contain the
 *  extracted atoms anymore, but they will not be deleted.
 *  Instead, they are returned by this method.
 *
 *  Note: The caller is responsible for releasing the memory of
 *  both the returned list and the refered Atoms inside it.
 *
 *  @param The atom to be extracted.
 *  @param Recursive-removal flag; if set, the links in the
 *      incoming set will also be extracted.
 *  @return A list with the Handles of all extracted Atoms.
 */
HandleEntry*
afunc AAtomTable_Extract(AAtomTable AtomTable, Handle, bool recursive = false);

/** Removes the previously extracted Handles (using the extract
 *  method) from this table.
 *  @param The list of the Handles previously extracted.
 *
 *  NOTE: This method also frees the memory of both list
 *  and Atom objects corresponding to the Handles inside the list.
 *  XXX Huh ??? What if there are other things referenceing these
 *  atoms/handles?
 */
void
afunc AAtomTable_RemoveExtractedHandles(AAtomTable AtomTable, HandleEntry* extractedHandles);

// JUST FOR TESTS:
bool
afunc AAtomTable_IsCleared(AAtomTable AtomTable);

/**
 * Overrides and declares copy constructor and equals operator as private
 * for avoiding large object copying by mistake.
 */
//AtomTable& operator=(const AtomTable&);
//AtomTable(const AtomTable&);

// --- public ---

/** Constructor and destructor for this class. */
AAtomTable
afunc AAtomTable_New(bool dsa = true);

AAtomTable
afunc AAtomTable_Free(AAtomTable AtomTable);

/** Prints atoms of this AtomTable to the given output stream.
 *  @param output  the output stream where the atoms will be printed
 *  @param type  the type of atoms that should be printed
 *  @param subclass  if true, matches all atoms whose type is
 *      subclass of the given type. If false, matches only atoms of the exact type.
 */
void
afunc AAtomTable_Print(AAtomTable AtomTable, std::ostream& output = std::cout,
    Type type = ATOM, bool subclass = true);

/** Prints atoms of this AtomTable though the given logger
 *  @param logger the logger used to print the atoms
 *  @param type  the type of atoms that should be printed
 *  @param subclass  if true, matches all atoms whose type is
 *      subclass of the given type. If false, matches only atoms of the exact type.
 */
void
afunc AAtomTable_Log(AAtomTable AtomTable, Logger& l = logger(), Type t = ATOM, bool subclass = true);

/** Return the number of atoms contained in a table. */
AInt
afunc AAtomTable_GetSize(AAtomTable AtomTable);

/** Registers an iterator. Iterators must be registered because when
 *  using a multi-threaded configuration, the contents of an active
 *  iterator may become invalid due to the removal of atoms. All
 *  registered iterators are then properly notified. This method is
 *  automatically called every time a new iterator is created.
 *
 *  @param The iterator to be registered.
 */
void
afunc AAtomTable_RegisterIterator(AAtomTable AtomTable, HandleIterator*);

/** Unregisters an iterator. This method is automatically called every
 *  time a new iterator is deleted.
 *
 *  @param The iterator to be unregistered.
 */
void
afunc AAtomTable_UnregisterIterator(AAtomTable AtomTable, HandleIterator*);

/** Creates a new handle iterator that iterates on all atoms of the atom table.
 *
 *  @return The newly created iterator.
 */
HandleIterator*
afunc AAtomTable_GetHandleIterator(AAtomTable AtomTable);

/** Creates a new handle iterator that iterates on atoms of a specific
 *  type, and optionally in its subclasses as well.
 *
 *  @param The type of atom to be iterated.
 *  @param Whether subclasses of the given type are to be iterated as well.
 *  @param VersionHandle for filtering the resulting atoms by context.
 *      NULL_VERSION_HANDLE indicates no filtering
 *  @return The newly created iterator.
 */
HandleIterator*
afunc AAtomTable_GetHandleIterator(AAtomTable AtomTable, Type, bool subclass = false,
    VersionHandle vh = NULL_VERSION_HANDLE);

/** Makes a set from a index head. It receives a linked-list and an
 *  index. The received linked-list is the tail of the newly created
 *  list, where its head is created by iterating the received index
 *  head until the end.
 *
 *  @param The tail linked-list.
 *  @param The first element of the index linked-list that will be
 *      placed in the beginning of the newly created linked-list.
 *  @param Which index is to be followed.
 *  @return The concatenation of the parameter list with the list
 *      created by following given index head.
 */
HandleEntry*
afunc AAtomTable_MakeSet(AAtomTable AtomTable, HandleEntry*, Handle, int);

/** Adds a new predicate index to this atom table given the Handle of
 *  the PredicateNode.
 *  @param The handle of the predicate node, whose name is the id of the predicate.
 *  @param The evaluator used to check if such predicate is true for a given handle.
 *  Throws exception if:
 *      - the given Handle is not in the AtomTable
 *      - there is already an index for this predicate id/Handle
 *      - the predicate index table is full.
 *  NOTE: Does not apply the new predicate index to the atoms
 *  inserted previously in the AtomTable.
 */
void
afunc AAtomTable_AddPredicateIndex(AAtomTable AtomTable, Handle h, PredicateEvaluator *pe);

/** Returns the Predicate evaluator for a given
 *  GroundedPredicateNode Handle, if it is being used as a
 *  lookup index. Otherwise, returns NULL.
 */
PredicateEvaluator*
afunc AAtomTable_GetPredicateEvaluator(AAtomTable AtomTable, Handle h);

/** Returns a list of handles that matches the GroundedPredicateNode
 *  with the given name (id).
 *  @param the id of the predicate node.
 *  @param VersionHandle for filtering the resulting atoms by
 *      context. NULL_VERSION_HANDLE indicates no filtering
 */
HandleEntry*
afunc AAtomTable_FindHandlesByGPN(AAtomTable AtomTable, const char*,
    VersionHandle = NULL_VERSION_HANDLE);

/** Returns a list of handles that matches the GroundedPredicateNode
 *  with the given Handle.
 *  @param the Handle of the predicate node.
 *  @param VersionHandle for filtering the resulting atoms by
 *      context. NULL_VERSION_HANDLE indicates no filtering
 */
HandleEntry*
afunc AAtomTable_FindHandlesByGPN(AAtomTable AtomTable, Handle h,
    VersionHandle vh = NULL_VERSION_HANDLE);

/** Returns the exact atom for the given name and type.
 *  Note: Type must inherit from NODE. Otherwise, it returns
 *  Handle::UNDEFINED.
 *
 *  @param The name of the desired atom.
 *  @param The type of the desired atom.
 *  @return The handle of the desired atom if found.
 */
Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const char* name, Type t);

/** Returns the exact atom for the given name and type.
 *  Note: Type must inherit from NODE. Otherwise, it returns
 *  Handle::UNDEFINED.
 *
 *  @param The name of the desired atom.
 *  @param The type of the desired atom.
 *  @return The handle of the desired atom if found.
 */
Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const Node* n);

/** Returns the exact atom for the given name and type.
 *  Note: Type must inherit from NODE. Otherwise, it returns
 *  Handle::UNDEFINED.
 *
 *  @param The name of the desired atom.
 *  @param The type of the desired atom.
 *  @return The handle of the desired atom if found.
 */
Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, Type t, const HandleSeq &seq);

/** Returns the exact atom for the given name and type.
 *  Note: Type must inherit from NODE. Otherwise, it returns
 *  Handle::UNDEFINED.
 *
 *  @param The name of the desired atom.
 *  @param The type of the desired atom.
 *  @return The handle of the desired atom if found.
 */
Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const Link* l);

/** Returns the set of atoms of a given type (subclasses optionally).
 *
 *  @param The desired type.
 *  @param Whether type subclasses should be considered.
 *  @return The set of atoms of a given type (subclasses optionally).
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, bool subclass = false);

/** Returns the set of atoms of a given type which have atoms of a
 *  given target type in their outgoing set (subclasses optionally).
 *
 *  @param The desired type.
 *  @param The desired target type.
 *  @param Whether type subclasses should be considered.
 *  @param Whether target type subclasses should be considered.
 *  @return The set of atoms of a given type and target type (subclasses optionally).
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, Type targetType,
    bool subclass = false, bool targetSubclass = false);

/** Returns the set of atoms with a given target handle in their
 *  outgoing set (atom type and its subclasses optionally).
 *
 *  @param The handle that must be in the outgoing set of the atom.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type with the given handle in their outgoing set.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Handle h, Type type = ATOM,
    bool subclass = true);

/** Returns the set of atoms with the given target handles and types
 *  (order is considered) in their outgoing sets, where the type and
 *  subclasses of the atoms are optional.
 *
 *  @param An array of handles to match the outgoing sets of the
 *      searched atoms. This array can be empty (or each of its
 *      elements can be null), if the handle value does not
 *      matter or if it does not apply to the specific search.
 *      Note that if this array is not empty, it must contain
 *      "arity" elements.
 *  @param  An array of target types to match the types of the atoms
 *      in the outgoing set of searched atoms.
 *  @param  An array of boolean values indicating whether each of the
 *      above types must also consider subclasses. This array can
 *      be null, which means that subclasses will not be considered.
 *      Note that if this array is not null, it must contains
 *      "arity" elements.
 *  @param The length of the outgoing set of the atoms being searched.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type with the matching
 *      criteria in their outgoing set.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const std::vector<Handle>&,
    Type*, bool*, Arity, Type type = ATOM, bool subclass = true);

/** Returns the set of atoms of a given name (atom type and subclasses optionally).
 *
 *  @param The desired name of the atoms.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type and name.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* name,
    Type type = ATOM, bool subclass = true);

/** Returns the set of atoms whose outgoing set contains at least one
 *  atom with the given name and type (atom type and subclasses optionally).
 *
 *  @param The name of the atom in the outgoing set of the searched atoms.
 *  @param The type of the atom in the outgoing set of the searched atoms.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type and name whose outgoing
 *      set contains at least one atom of the given type and name.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char*, Type,
    Type type = ATOM, bool subclass = true);

/** Returns the set of atoms with the given target names and/or types
 *  (order is considered) in their outgoing sets, where the type
 *  and subclasses arguments of the searched atoms are optional.
 *
 *  @param An array of names to match the outgoing sets of the searched
 *      atoms. This array (or each of its elements) can be null, if
 *      the names do not matter or if do not apply to the specific search.
 *      Note that if this array is not null, it must contain "arity" elements.
 *  @param An array of target types to match the types of the atoms in
 *      the outgoing set of searched atoms. If array of names is not null,
 *      this parameter *cannot* be null as well. Besides, if an element in a
 *      specific position in the array of names is not null, the corresponding
 *      type element in this array *cannot* be NOTYPE as well.
 *  @param An array of boolean values indicating whether each of the
 *      above types must also consider subclasses. This array can be null,
 *      what means that subclasses will not be considered. Not that if this
 *      array is not null, it must contains "arity" elements.
 *  @param The length of the outgoing set of the atoms being searched.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type with the matching
 *      criteria in their outgoing set.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char**, Type*, bool*, Arity,
    Type type = ATOM, bool subclass = true);

/** Returns the set of atoms with the given target names and/or types
 *  (order is considered) in their outgoing sets, where the type
 *  and subclasses arguments of the searched atoms are optional.
 *
 *  @param An array of target types to match the types of the atoms in
 *      the outgoing set of searched atoms. This parameter (as well as any of
 *      its elements can be NOTYPE), what means that the type doesnt matter.
 *      Not that if this array is not null, it must contains "arity" elements.
 *  @param An array of boolean values indicating whether each of the
 *      above types must also consider subclasses. This array can be null,
 *      what means that subclasses will not be considered. Not that if this
 *      array is not null, it must contains "arity" elements.
 *  @param The length of the outgoing set of the atoms being searched.
 *  @param The optional type of the atom.
 *  @param Whether atom type subclasses should be considered.
 *  @return The set of atoms of the given type with the matching
 *      criteria in their outgoing set.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type*, bool*, Arity,
    Type type = ATOM, bool subclass = true);

/** Returns the set of atoms within the given importance range.
 *
 *  @param Importance range lower bound (inclusive).
 *  @param Importance range upper bound (inclusive).
 *  @return The set of atoms within the given importance range.
 */
HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, AttentionValue::sti_t lowerBound,
    AttentionValue::sti_t upperBound = 32767)
{
    return importanceIndex.getHandleSet(lowerBound, upperBound);
}

HandleEntry*
afunc AAtomTable_GetPredicateHandleSet(AAtomTable AtomTable, int index);

/** Updates the importance index for the given atom. According to the
 *  new importance of the atom, it may change importance bins.
 *
 *  @param The atom whose importance index will be updated.
 *  @param The old importance bin where the atom originally was.
 */
void
afunc AAtomTable_UpdateImportanceIndex(AAtomTable AtomTable, Atom* a, int bin);

/** Merge the existing atom with the given handle with the given truth value.
 *  If the handle is valid, emits atom merged signal.
 *  @param h Handle of the Atom to be merged
 *  @param tvn TruthValue to be merged to current atom's truth value.
 */
void
afunc AAtomTable_Merge(AAtomTable AtomTable, Handle h, const TruthValue& tvn);

/** Adds an atom to the table, checking for duplicates and merging
 *  when necessary. When an atom is added, the atom table takes over
 *  the memory management for that atom. In other words, no other
 *  code should ever attempt to delete the pointer that is passed
 *  into this method.
 *
 *  When adding atoms in bulk, it can be convenient to defer
 *  the setup of incoming links until a later stage.
 *
 *  @param The new atom to be added.
 *  @return The handle of the newly added atom.
 */
Handle
afunc AAtomTable_Add(AAtomTable AtomTable, Atom*, bool dont_defer_incoming_links = true);

/** Return true if the atom table holds this handle, else return false. */
bool
afunc AAtomTable_Holds(AAtomTable AtomTable, const Handle& h);

/** Get Atom object already in the AtomTable.
 *
 *  @param h Handle of the atom to retrieve.
 *  @return pointer to Atom object, NULL if no atom within this AtomTable is
 *      associated with handle.
 */
inline
Atom*
func AAtomTable_GetAtom(AAtomTable AtomTable, const Handle& h);

/** Get Node object already in the AtomTable.
 *
 *  @param h Handle of the node to retrieve.
 *  @return pointer to Node object, NULL if no atom within this AtomTable is
 *      associated with handle or if the atom is a link.
 */
inline
Node*
afunc AAtomTable_GetNode(AAtomTable AtomTable, const Handle& h);

/** Get Link object already in the AtomTable.
 *
 *  @param h Handle of the link to retrieve.
 *  @return pointer to Link object, NULL if no atom within this AtomTable is
 *      associated with handle or if the atom is a node.
 */
inline
Link*
afunc AAtomTable_GetLink(AAtomTable AtomTable, const Handle& h);

/** Removes atom from the table.
 *
 *  @param The atom to be removed.
 *  @param Recursive-removal flag; if set, the links in the incoming
 *      set will also be removed.
 *  @return True if the removal operation was successful. False, otherwise.
 */
bool
afunc AAtomTable_Remove(AAtomTable AtomTable, Handle, bool recursive = false);

/** Return a random atom in the AtomTable.
 *  @note Uses the atomSet buckets to provide reasonbly quick look-up.
 */
Handle
afunc AAtomTable_GetRandom(AAtomTable AtomTable, RandGen* rng);

/** Decays importance of all atoms in the table, reindexing
 *  importanceIndex accordingly and extracting the atoms that fall
 *  below the "LOWER_STI_VALUE" threshold.
 *  @return the list of the handles that should be removed.
 */
HandleEntry*
afunc AAtomTable_DecayShortTermImportance(AAtomTable AtomTable);

/** Returns whether DynamicsStatisticsAgent is to be used with this table or not. */
bool
afunc AAtomTable_UsesDSA(AAtomTable AtomTable);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, bool subclass, VersionHandle vh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, Type targetType, bool subclass,
    bool targetSubclass, VersionHandle vh, VersionHandle targetVh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Handle handle, Type type, bool subclass, VersionHandle vh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const AHandleVector& handles, Type* types,
    bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* name, Type type, bool subclass,
    VersionHandle vh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* targetName, Type targetType,
    Type type, bool subclass, VersionHandle vh, VersionHandle targetVh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char** names, Type* types, bool*
        subclasses, Arity arity, Type type, bool subclass, VersionHandle vh);

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type* types, bool* subclasses, Arity arity,
        Type type, bool subclass, VersionHandle vh);

/** Invoke the callback cb for *every* atom in the AtomTable
 *  This assumes that the callback does *not* modify the AtomTable,
 *  specifically, does not insert or remove atoms from the atom table.
template<class T>
inline bool foreach_atom(bool (T::*cb)(const Atom *), T *data) const
{
    AtomHashSet::const_iterator it;
    for (it = atomSet.begin(); it != atomSet.end(); it++) {
        const Atom* atom = *it;
        bool rc = (data->*cb)(atom);
        if (rc) return rc;
    }
    return false;
}
*/

/** For use by atom table persistence systems only. When bulk-adding
 *  atoms to the atom table, it is convenient to avoid resolving
 *  incoming pointers until all atoms have been added. However, the
 *  incoming set of an atom *must* be set up before the atom can be
 *  used. This routine will review the contents of the AtomTable,
 *  and set up all incoming sets of each atom.
 */
void
afunc AAtomTable_ScrubIncoming(AAtomTable AtomTable);

#endif // AAtomTable_H
