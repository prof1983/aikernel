/* AAtom
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/Atom.h
 */

#ifndef AAtom_H
#define AAtom_H

#include "AAtomHandle.h"
#include "AAtomTable.h"

//#include <string>
//#include <opencog/atomspace/TruthValue.h>
//#include <opencog/atomspace/atom_types.h>

#include "AAtomTypes.h"

//#include <opencog/atomspace/HandleEntry.h>
//#include <opencog/atomspace/ImportanceIndex.h>
//#include <opencog/atomspace/AttentionValue.h>
//#include <opencog/atomspace/AtomSpaceDefinitions.h>
//#include <opencog/util/exceptions.h>

//class AtomUTest;
//class AtomTable;
//class HandleEntry;

/** Atoms are the basic implementational unit in the system that
 *  represents nodes and links. In terms of inheritance, nodes and
 *  links are specialization of atoms, that is, they inherit all
 *  properties from atoms.
 */
typedef struct {
    // --- protected ---
    AAtomHandle handle;
    AAtomTable AtomTable;
    /* Linked-list that dynamically changes when new links point to this atom. */
    HandleEntry* Incoming;
    Type type;
    char Flags;
    TruthValue* truthValue;
} AAtom_Type;

typedef AAtom_Type* AAtom;

// --- class Atom : public AttentionValueHolder ---

//friend class SavingLoading;

//friend class AtomTable;
typedef AtomTable_Type* AAtomTable;

//friend class AtomSpace;
//friend class ImportanceIndex;
//friend class NMXmlParser;
//friend class TLB;
//friend class Node;
//friend class Link;
//friend class ::AtomUTest;

// --- private ---

/** Called by constructors to init this object */
void
func AAtom_Init(AAtom Atom; Type, const TruthValue&,
    const AttentionValue& av = AttentionValue::DEFAULT_AV());

/** Sets the AtomTable in which this Atom is inserted. */
void
func AAtom_SetAtomTable(AAtom Atom, AtomTable *);

/** Returns the AtomTable in which this Atom is inserted. */
AtomTable*
AAtom_GetAtomTable(AAtom Atom);
//const { return atomTable; }

// --- protected ---

/** Constructor for this class.
 *  @param The type of the atom.
 *  @param Outgoing set of the atom, that is, the set of atoms this
 *      atom references. It must be an empty vector if the atom is a node.
 *  @param The truthValue of the atom. note: This is not cloned as
 *      in setTruthValue.
 */
AAtom
AAtom_New(Type, const TruthValue& = TruthValue::NULL_TV(),
        const AttentionValue& = AttentionValue::DEFAULT_AV());

// ---

/** Adds a new entry to this atom's incoming set.
 *  @param The handle of the atom to be included.
 */
void
AAtom_AddIncomingHandle(AAtom Atom, Handle);

/** Removes an entry from this atom's incoming set.
 *  @param The handle of the atom to be excluded.
 */
void
AAtom_RemoveIncomingHandle(AAtom Atom, Handle);
//throw (RuntimeException);

// --- public ---

/** Returns the type of the atom.
 *  @return The type of the atom.
 */
inline
Type
AAtom_GetType(AAtom Atom);
//const { return type; }

/** Returns the handle of the atom.
 *  @return The handle of the atom.
 */
inline
Handle
AAtom_GetHandle(AAtom Atom);
//const { return handle; }

/** Returns a pointer to a linked-list containing the atoms that are members of this one's incoming set.
 *  @return A pointer to a linked-list containing the atoms that are members of this one's incoming set.
 */
inline
HandleEntry*
AAtom_GetIncomingSet(AAtom Atom);
//const { return incoming; }

/** Returns the AttentionValue object of the atom.
 *  @return The const reference to the AttentionValue object of the atom.
 */
const
AttentionValue&
AAtom_GetAttentionValue(AAtom Atom);
//const;

/* Sets the AttentionValue object of the atom. */
void
AAtom_SetAttentionValue(AAtom Atom, const AttentionValue&);
//throw (RuntimeException);

/** Returns the TruthValue object of the atom.
 *  @return The const referent to the TruthValue object of the atom.
 */
const
TruthValue&
AAtom_getTruthValue(AAtom Atom);
//const;

/* Sets the TruthValue object of the atom. */
void
AAtom_SetTruthValue(AAtom Atom, const TruthValue&);

/** Returns whether this atom is marked for removal.
 *  @return Whether this atom is marked for removal.
 */
bool
AAtom_IsMarkedForRemoval(AAtom Atom);
//const { return (flags & MARKED_FOR_REMOVAL) != 0; }

/** Returns an atom flag.
 *  A byte represents all flags. Each bit is one of them.
 *  @param An int indicating which of the flags will be returned.
 *  @return A boolean indicating if that flag is set or not.
 */
bool
AAtom_GetFlag(AAtom Atom, int);
//const;

/** Changes the value of the given flag.
 *  @param An int indicating which of the flags will be set.
 *  @param A boolean indicating the new value of the flag.
 */
void
AAtom_SetFlag(AAtom Atom, int, bool);

/* Marks the atom for removal. */
void
AAtom_MarkForRemoval(AAtom Atom);

/* Unsets removal flag. */
void
AAtom_UnsetRemovalFlag(AAtom Atom);

/** Returns a string representation of the node.
 *  @return A string representation of the node.
 */
//virtual std::string toString(void) const = 0;
//virtual std::string toShortString(void) const = 0;

/** Returns whether two atoms are equal.
 *  @return true if the atoms are equal, false otherwise.
 */
//virtual bool operator==(const Atom&) const = 0;
bool
func AAtom_Equal(AAtom Atom1, AAtom Atom2);

/** Returns the hashCode of the Atom.
 *  @return an unsigned integer value as the hashCode of the Atom.
 */
//virtual
size_t
AAtom_HashCode(AAtom Atom, void);
//const = 0;

//virtual
AAtom
AAtom_Clone(AAtom Atom);
//const = 0;

#endif // AAtom_H
