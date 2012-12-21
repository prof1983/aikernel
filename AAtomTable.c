/* AAtomTable
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/AtomTable.cc
 */

#include "AtomTable.h"

/*
#include <set>

#include <stdlib.h>
#include <pthread.h>
#include <boost/bind.hpp>

#include <opencog/atomspace/AtomSpaceDefinitions.h>
#include <opencog/atomspace/ClassServer.h>
#include <opencog/atomspace/HandleMap.h>
#include <opencog/atomspace/Link.h>
#include <opencog/atomspace/Node.h>
#include <opencog/atomspace/StatisticsMonitor.h>
#include <opencog/atomspace/TLB.h>
#include <opencog/util/Config.h>
#include <opencog/util/exceptions.h>
#include <opencog/util/Logger.h>
*/


typedef std::vector<Handle> AHandleVector;
typedef std::vector<HandleEntry*> AHnadleEntryVector;


//#define DPRINTF printf
//#define tableId (0) // Hack around some DPRINTF statements that want an old tableID member variable
//#define DPRINTF(...)

//using namespace opencog;

Handle
afunc AAtomTable_Add(AAtomTable AtomTable, Atom *atom, bool dont_defer_incoming_links)
{
    if (atom->getAtomTable() != NULL) {
        // Atom is already inserted
        return atom->getHandle();
    }
    Handle existingHandle = Handle::UNDEFINED;
    Node * nnn = dynamic_cast<Node *>(atom);
    Link * lll = dynamic_cast<Link *>(atom);
    // Check if the node or link handle already exists in the indexers
    if (nnn) {
        existingHandle = getHandle(nnn);
    } else if (lll) {
        existingHandle = getHandle(lll);
    }

    if (TLB::isValidHandle(existingHandle)) {
        DPRINTF("Merging existing Atom with the Atom being added ...\n");
        merge(existingHandle, atom->getTruthValue());
        delete atom;
        return existingHandle;
    }

    // New atom, its Handle will be stored in the AtomTable
    // Increment the size of the table
    size++;

    // Adds to the hash_set
    DPRINTF("Inserting atom %p intoAtomTable (type=%d)\n", atom, atom->getType());
    atomSet.insert(atom);
    DPRINTF("AtomTable::add atomSet->insert(%p) => size = %zu\n", atom, atomSet.size());

    // Checks for null outgoing set members.
    if (lll) {
        const std::vector<Handle>& ogs = lll->getOutgoingSet();
        size_t arity = ogs.size();
        for (int i = arity - 1; i >= 0; i--) {
            if (TLB::isInvalidHandle(ogs[i])) {
                throw RuntimeException(TRACE_INFO,
                           "AtomTable - Attempting to insert link with "
                           "invalid outgoing members");
            }
        }
    }

    // Its possible that the atom is already in the TLB --
    // e.g. if it was fetched from persistent storage; this
    // was done to preserve handle consistency.
    Handle handle = atom->handle;
    if (TLB::isInvalidHandle(handle)) handle = TLB::addAtom(atom);

    nodeIndex.insertAtom(atom);
    linkIndex.insertAtom(atom);
    typeIndex.insertAtom(atom);
    targetTypeIndex.insertAtom(atom);
    importanceIndex.insertAtom(atom);
    predicateIndex.insertAtom(atom);

    // Updates incoming set of all targets.
    atom->setAtomTable(this);
    if (dont_defer_incoming_links && (lll != NULL)) {
        for (int i = 0; i < lll->getArity(); i++) {
            lll->getOutgoingAtom(i)->addIncomingHandle(handle);
        }
    }

    if (useDSA) {
        StatisticsMonitor::getInstance()->add(atom);
    }

    DPRINTF("Atom added: %ld => %s\n", handle.value(), atom->toString().c_str());

    return handle;
}

void
afunc AAtomTable_AddPredicateIndex(AAtomTable AtomTable, Handle h, PredicateEvaluator *pe)
{
    AtomTable->PredicateIndex.addPredicateIndex(h,pe);
}

AError
afunc AAtomTable_Free(AAtomTable AtomTable)
{
    //disconnect signals
    AtomTable->addedTypeConnection.disconnect();

    // remove all atoms from AtomTable
    AtomHashSet::iterator it = atomSet.begin();

    while (it != atomSet.end()) {
        //DPRINTF("Removing atom %s (atomSet size = %zu)\n", (*it)->toString().c_str(), atomSet.size());
        remove((*it)->getHandle(), true);
        it = atomSet.begin();
    }
    atomSet.clear();

    return 0;
}

inline
Atom*
func AAtomTable_GetAtom(AAtomTable AtomTable, const Handle& h)
{
    Atom* atom;

    if (h == Handle::UNDEFINED) return NULL;
    atom = TLB::getAtom(h);
    if (atom)
        // if the atom isn't linked to this AtomTable
        // then blank pointer
        if (this != atom->getAtomTable()) atom = NULL;
    return atom;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, bool subclass = false)
{
    return AtomTable->TypeIndex.getHandleSet(type, subclass);
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, Type targetType,
    bool subclass = false, bool targetSubclass = false)
{
    HandleEntry* set;

    set = AAtomTable->TargetTypeIndex.getHandleSet(targetType,targetSubclass);
    return HandleEntry::filterSet(set, type, subclass);
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* name,
    Type type = ATOM, bool subclass = true)
{
    HandleEntry* set;

    if (name == NULL || *name == 0)
    {
        set = typeIndex.getHandleSet(type, subclass);
        return HandleEntry::filterSet(set, "");
    }
    return nodeIndex.getHandleSet(type, name, subclass);
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, AttentionValue::sti_t lowerBound,
    AttentionValue::sti_t upperBound = 32767)
{
    return AtomTable->ImportanceIndex.getHandleSet(lowerBound, upperBound);
}

inline
Node*
afunc AAtomTable_GetNode(AAtomTable AtomTable, const Handle& h)
{
    return dynamic_cast<Node*>(AAtomTable_GetAtom(AtomTable, h));
}

inline
Link*
afunc AAtomTable_GetLink(AAtomTable AtomTable, const Handle& h)
{
    return dynamic_cast<Link*>(AAtomTable_GetAtom(AtomTable, h));
}

PredicateEvaluator*
afunc AAtomTable_GetPredicateEvaluator(AAtomTable AtomTable, Handle h)
{
    return AtomTable->PredicateIndex.getPredicateEvaluator(h);
}

HandleEntry*
afunc AAtomTable_GetPredicateHandleSet(AAtomTable AtomTable, int index)
{
    return AtomTable->PredicateIndex.getHandleSet(index);
}

HandleEntry*
afunc AAtomTable_FindHandlesByGPN(AAtomTable AtomTable, Handle h,
    VersionHandle vh = NULL_VERSION_HANDLE)
{
    return AtomTable->PredicateIndex.findHandlesByGPN(h, vh);
}

bool
afunc AAtomTable_Holds(AAtomTable AtomTable, const Handle& h)
{
    Atom* a;

    a = AtomTable_GetAtom(h);
    if (NULL == a) return false;
    return true;
}

bool
afunc AAtomTable_IsCleared(AAtomTable AtomTable)
{
    unsigned int i;

    if (AtomTable->size != 0) {
        //DPRINTF("AtomTable::size is not 0\n");
        return false;
    }

    if (AtomTable->AtomSet.size() != 0) {
        //DPRINTF("AtomTable[%d]::atomSet is not empty. size =%zu\n", tableId, atomSet.size());
        return false;
    }

    // if (nameIndex.size() != 0) return false;
    if (AtomTable->TypeIndex.size() != 0) return false;
    if (AtomTable->ImportanceIndex.size() != 0) return false;
    if (AtomTable->TargetTypeIndex.size() != 0) return false;
    if (AtomTable->PredicateIndex.size() != 0) return false;

    for (i = 0; i < iterators.size(); i++) {
        if (iterators[i]->hasNext()) {
            //DPRINTF("iterators[%d] is not empty\n", i);
            return false;
        }
    }
    return true;
}

AAtomTable
afunc AAtomTable_New(bool dsa)
{
    AAtomTable Res;

    // --- Code ---

    Res := GetMem(sizeof(AAtomTable_Type));
    Res->useDSA = dsa;
    Res->size = 0;
    // This allows one to tune how often the unordered map resizes itself.
    //atomSet.max_load_factor(100.0f);
    Res->nodeIndex.connectAtomTable(Res);

    #ifdef HAVE_LIBPTHREAD
    pthread_mutex_init(&iteratorsLock, NULL);
    #endif

    //connect signals
    Res->addedTypeConnection =
        classserver().addTypeSignal().connect(boost::bind(&AtomTable::typeAdded, Res, _1));

    return Res;
}

/*
AtomTable& AtomTable::operator=(const AtomTable& other)
{
    throw opencog::RuntimeException(TRACE_INFO,
            "AtomTable - Cannot copy an object of this class");
}
*/

/*
AtomTable::AtomTable(const AtomTable& other)
{
    throw opencog::RuntimeException(TRACE_INFO,
            "AtomTable - Cannot copy an object of this class");
}
*/

void
afunc AAtomTable_RegisterIterator(AAtomTable AtomTable, HandleIterator* iterator)
{
    AAtomTable_LockIterators(AtomTable);
    AtomTable->Iterators.push_back(iterator);
    AAtomTable_UnlockIterators(AtomTable);
}

Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const char* name, Type t)
{
    return AtomTable->NodeIndex.getHandle(t, name);
}

Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const Node* n)
{
    return AtomTable->getHandle(n->getName().c_str(), n->getType());
}

Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, Type t, const HandleSeq &seq)
{
    return AtomTable->linkIndex.getHandle(t, seq);
}

Handle
afunc AAtomTable_GetHandle(AAtomTable AtomTable, const Link* l)
{
    return AtomHandle->getHandle(l->getType(), l->getOutgoingSet());
}

HandleEntry*
afunc AAtomTable_FindHandlesByGPN(AAtomTable AtomTable, const char* gpnNodeName, VersionHandle vh)
{
    Handle gpnHandle;
    HandleEntry* Res;

    //DPRINTF("AtomTable::findHandlesByGPN(%s)\n", gpnNodeName);
    // Get the GroundPredicateNode with such name
    gpnHandle = getHandle(gpnNodeName, GROUNDED_PREDICATE_NODE);
    Res = findHandlesByGPN(gpnHandle);
    Res = HandleEntry::filterSet(Res, vh);
    return Res;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Handle handle, Type type, bool subclass)
{
    HandleEntry* set;

    set = TLB::getAtom(handle)->getIncomingSet();
    if (set != NULL) set = set->clone();
    set = HandleEntry::filterSet(set, type, subclass);
    return set;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const AHandleVector& handles, Type* types,
    bool* subclasses, Arity arity, Type type, bool subclass)
{
    bool hasAllHandles;
    Handle h;
    HandleEntry* result;
    int countdown;

    // --- Code ---

    // Check if it is the special case of looking for an specific atom
    if (AtomTable->classserver().isA(type, LINK) && (arity == 0 || !handles.empty()))
    {
        //DPRINTF("special case\n");
        hasAllHandles = true;
        for (int i = 0; hasAllHandles && i < arity; i++) {
            hasAllHandles = TLB::isValidHandle(handles[i]);
        }
        //DPRINTF("hasAllHandles = %d, subclass = %d\n", hasAllHandles, subclass);
        if (hasAllHandles && !subclass) {
            //DPRINTF("building link for lookup: type = %d, handles.size() = %zu\n", type, handles.size());
            Link link(type, handles); // local var on stack, avoid malloc
            AtomHashSet::const_iterator it = atomSet.find(&link);
            h = Handle::UNDEFINED;
            if (it != atomSet.end()) {
                h = (*it)->getHandle();
            }
            result = NULL;
            if (TLB::isValidHandle(h)) {
                result = new HandleEntry(h);
            }
            //DPRINTF("Returning HandleSet by using atom hash_set!\n");
            return result;
        }
    }

    if (classserver().isA(type, LINK) && (arity == 0)) {
        result = getHandleSet(type, subclass);
        result = HandleEntry::filterSet(result, arity);
        return result;
    }

    AHandleEntryVector sets(arity, NULL);

    countdown = 0;

    // builds a set for each element in the outgoing set. Empty sets are
    // counted to be removed a posteriori
    for (int i = 0; i < arity; i++) {
        if ((!handles.empty()) && TLB::isValidHandle(handles[i])) {
            sets[i] = TLB::getAtom(handles[i])->getIncomingSet()->clone();
            sets[i] = HandleEntry::filterSet(sets[i], handles[i], i, arity);
            // Also filter links that do not belong to this table
            //sets[i] = HandleEntry::filterSet(sets[i], tableId);
            if (sets[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    delete sets[j];
                }
                return NULL;
            }
        } else if ((types != NULL) && (types[i] != NOTYPE)) {
            bool sub = subclasses == NULL ? false : subclasses[i];
            sets[i] = getHandleSet(type, types[i], subclass, sub);
            // Also filter links that do not belong to this table
            //sets[i] = HandleEntry::filterSet(sets[i], tableId);
            if (sets[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    delete sets[j];
                }
                return NULL;
            }
        } else {
            countdown++;
        }
    }

    int newLength = arity;
    // if the empty set counter is not zero, removes them by shrinking the
    // list of sets
    if (countdown > 0) {
        DPRINTF("newset allocated size = %d\n", (arity - countdown));
        // TODO: Perhaps it's better to simply erase the NULL entries of the sets
        std::vector<HandleEntry*> newset;
        for (int i = 0; i < arity; i++) {
            if (sets[i] != NULL) {
                newset.push_back(sets[i]);
            }
        }
        sets = newset;
    }
    DPRINTF("newLength = %d\n", newLength);

    if ((type != ATOM) || (!subclass)) {
        for (int i = 0; i < newLength; i++) {
            // filters by type and subclass in order to remove unwanted elements.
            // This is done before the intersection method to reduce the number of
            // elements being passed (intersection uses qsort, which is n log n)
            sets[i] = HandleEntry::filterSet(sets[i], type, subclass);
        }
    }

    // computes the intersection of all non-empty sets
    HandleEntry* set = HandleEntry::intersection(sets);
    // TODO: Why not move this filtering to the begining... Pehaps it will filter more before the intersection (which seems to be the most expensive operation)
    // filters the answer set for every type in the array of target types
    if (types != NULL) {
        for (int i = 0; i < arity; i++) {
            if (types[i] != NOTYPE) {
                bool sub = subclasses == NULL ? false : subclasses[i];
                set = HandleEntry::filterSet(set, types[i], sub, i, arity);
            }
        }
    }

    return set;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* targetName, Type targetType, Type type, bool subclass)
{
    Handle handle;
    HandleEntry* result;

    // --- Code ---

    // Gets the exact atom with the given name and type, in any AtomTable.
    handle = AAtomTable_GetHandle(AtomTable, targetName, targetType);

    result = NULL;
    // then, if the atom returend is valid, the list with the given target name
    // and types will be returned.
    if (TLB::isValidHandle(handle)) {
        result = AAtomTable_GetHandleSet(AtomTable, handle, type, subclass);
    }
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char** names, Type* types,
    bool* subclasses, Arity arity, Type type, bool subclass)
{
    int countdown;
    int i;
    bool sub;

    HandleEntryVector sets(arity, NULL);

    countdown = 0;
    // A list for each array of names is built. Then, it's filtered by
    // the name (to avoid hash conflicts) and by the correspondent type
    // in the array of types.
    for (i = 0; i < arity; i++) {
        //DPRINTF("getHandleSet: arity %d\n", i);
        sub = subclasses == NULL ? false : subclasses[i];
        if ((names != NULL) && (names[i] != NULL)) {
            if ((types != NULL) && (types[i] != NOTYPE)) {
                sets[i] = getHandleSet(names[i], types[i], type, subclass);
                if (sub) {
                    // If subclasses are accepted, the subclasses are
                    // returned in the array types.
                    std::vector<Type> subTypes;

                    classserver().getChildrenRecursive(types[i],
                                           std::back_inserter(subTypes));

                    // For all subclasses found, a set is concatenated
                    // to the answer set
                    for (unsigned int j = 0; j < subTypes.size(); j++) {
                        HandleEntry *subSet = getHandleSet(names[i],
                                          subTypes[j], type, subclass);
                        sets[i] = HandleEntry::concatenation(sets[i], subSet);
                    }
                }
                sets[i] = HandleEntry::filterSet(sets[i], names[i],
                                           types[i], sub, i, arity);
            } else {
                for (int j = 0; j < i; j++) {
                    delete sets[j];
                }
                throw RuntimeException(TRACE_INFO,
                    "Cannot make this search using only target name!\n");
            }
        } else if ((types != NULL) && (types[i] != NOTYPE)) {
            sets[i] = getHandleSet(type, types[i], subclass, sub);
            sets[i] = HandleEntry::filterSet(sets[i], types[i], sub, i, arity);
        } else {
            countdown++;
        }
    }

    // If the empty set counter is not zero, removes them by shrinking
    // the list of sets
    if (countdown > 0) {
        DPRINTF("newset allocated size = %d\n", (arity - countdown));
        // TODO: Perhaps it's better to simply erase the NULL entries of the sets
        std::vector<HandleEntry*> newset;
        for (int i = 0; i < arity; i++) {
            if (sets[i] != NULL) {
                newset.push_back(sets[i]);
            }
        }
        sets = newset;
    }

    // The intersection is made for all non-empty sets, and then is
    // filtered by the optional specified type. Also, if subclasses are
    // not accepted, it will not pass the filter.
    DPRINTF("AtomTable::getHandleSet: about to call intersection\n");
    HandleEntry* set = HandleEntry::intersection(sets);
    return  set;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type* types, bool* subclasses, Arity arity, Type type, bool subclass)
{
    return AAtomTable_GetHandleSet(AtomTable, (const char**) NULL, types, subclasses, arity, type, subclass);
}

void
afunc AAtomTable_Merge(AAtomTable AtomTable, Handle h, const TruthValue& tvn)
{
    Atom* atom;

    if (TLB::isValidHandle(h)) {
        atom = TLB::getAtom(h);
        // Merge the TVs
        if (!tvn.isNullTv()) {
            const TruthValue& currentTV = atom->getTruthValue();
            if (currentTV.isNullTv()) {
                atom->setTruthValue(tvn);
            } else {
                TruthValue* mergedTV = currentTV.merge(tvn);
                atom->setTruthValue(*mergedTV);
                delete mergedTV;
            }
        }
        if (logger().isFineEnabled())
            logger().fine("Atom merged: %d => %s", h.value(), atom->toString().c_str());
    }
}

AInt
afunc AAtomTable_GetSize(AAtomTable AtomTable)
{
    return AtomTable->Size;
}

void
afunc AAtomTable_Log(AAtomTable AtomTable, Logger& logger, Type type, bool subclass)
{
    AtomHashSet::const_iterator it;
    for (it = atomSet.begin(); it != atomSet.end(); ++it) {
        const Atom* atom = *it;
        bool matched = (subclass && classserver().isA(atom->getType(), type)) || type == atom->getType();
        if (matched)
            logger.debug("%d: %s", atom->getHandle().value(),
                    atom->toString().c_str());
    }
}

void
afunc AAtomTable_Print(AAtomTable AtomTable, std::ostream& output, Type type, bool subclass) const
{
    AtomHashSet::const_iterator it;
    for (it = atomSet.begin(); it != atomSet.end(); ++it) {
        const Atom* atom = *it;
        bool matched = (subclass && classserver().isA(atom->getType(), type)) || type == atom->getType();
        if (matched) output << atom->getHandle() << ": " << atom->toString() << std::endl;
    }
}

HandleEntry*
afunc AAtomTable_Extract(AAtomTable AtomTable, Handle handle, bool recursive)
{
    HandleEntry* result;
    Atom* atom;

    // TODO: Check if this atom is really inserted in this AtomTable and get the
    // exact Atom object
    result = NULL;

    atom = TLB::getAtom(handle);
    if (!atom || atom->isMarkedForRemoval()) return result;
    atom->markForRemoval();

    // if recursive-flag is set, also extract all the links in the atom's
    // incoming set
    if (recursive) {
        // we need to make a copy of the incoming set because the 'incoming
        // set' container is actually a list, so the same link may appear twice
        // in an incoming set. Hopefully we'll eventually use the right
        // container
        std::set<Handle> is;
        for (HandleEntry* in = atom->getIncomingSet(); in != NULL; in = in->next)
            is.insert(in->handle);

        std::set<Handle>::iterator is_it;
        for (is_it = is.begin(); is_it != is.end(); ++is_it) {
            logger().debug("[AtomTable::extract] incoming set: %s", TLB::isValidHandle(*is_it) ? TLB::getAtom(*is_it)->toString().c_str() : "INVALID HANDLE");
            if (TLB::getAtom(*is_it)->isMarkedForRemoval() == false) {
                logger().debug("[AtomTable::extract] marked for removal is false");
                result = HandleEntry::concatenation(extract(*is_it, true), result);
            }
        }
    }
    if (atom->getIncomingSet())
    {
        Logger::Level save = logger().getBackTraceLevel();
        logger().setBackTraceLevel(Logger::NONE);
        logger().warn("AtomTable.extract(): "
           "attempting to extract atom with non-empty incoming set: %s\n",
           atom->toShortString().c_str());
        for (HandleEntry* it = atom->getIncomingSet();
             it != NULL; it = it->next)
        {
            logger().warn("\tincoming: %s\n",
                 TLB::getAtom(it->handle)->toShortString().c_str());
        }
        logger().setBackTraceLevel(save);
        logger().warn("AtomTable.extract(): stack trace for previous error follows");
        atom->unsetRemovalFlag();
        return result;
    }

    //decrements the size of the table
    size--;

    atomSet.erase(atom);

    // updates all global statistics regarding the removal of this atom
    if (useDSA) StatisticsMonitor::getInstance()->remove(atom);

    nodeIndex.removeAtom(atom);
    linkIndex.removeAtom(atom);
    typeIndex.removeAtom(atom);
    targetTypeIndex.removeAtom(atom);
    importanceIndex.removeAtom(atom);
    predicateIndex.removeAtom(atom);

    Link* link = dynamic_cast<Link*>(atom);
    if (link) {
        // Remove from incoming sets.
        for (int i = 0; i < link->getArity(); i++) {
            Atom* target = link->getOutgoingAtom(i);
            target->removeIncomingHandle(handle);
        }
    }

    return HandleEntry::concatenation(new HandleEntry(handle), result);
}

bool
afunc AAtomTable_Remove(AAtomTable AtomTable, Handle handle, bool recursive)
{
    HandleEntry* extractedHandles;

    extractedHandles = AAtomTable_Extract(AtomTable, handle, recursive);
    if (extractedHandles) {
        AAtomTable_RemoveExtractedHandles(AtomTable, extractedHandles);
        delete extractedHandles;
        return true;
    }
    return false;
}

void
afunc AAtomTable_RemoveExtractedHandles(AAtomTable AtomTable, HandleEntry* extractedHandles)
{
    HandleSeq hs;
    Atom* atom;

    if (extractedHandles == NULL) return;

    // We must to iterate from the end to the begining of the list of atoms so that
    // link's target atoms are not removed before the link
    // TODO: this is inefficient. if we alter extract to build the HandleEntry
    // list in reverse, then we can avoid initialising a temporary vector.
    hs = extractedHandles->toHandleVector();

    for (HandleSeq::reverse_iterator it = hs.rbegin(); it < hs.rend(); ++it) {
        atom = TLB::removeAtom(*it);
        if (logger().isFineEnabled())
            logger().fine("Atom removed: %d => %s", it->value(), atom->toString().c_str());
        delete atom;
    }
}

HandleEntry*
afunc AAtomTable_DecayShortTermImportance(AAtomTable AtomTable)
{
    return importanceIndex.decayShortTermImportance();
}

bool
afunc AAtomTable_Decayed(Handle h)
{
    Atom* a;

    a = TLB::getAtom(h);
    return a->getFlag(REMOVED_BY_DECAY);
}

void
afunc AAtomTable_ClearIndexesAndRemoveAtoms(AAtomTable AtomTable, HandleEntry* extractedHandles)
{
    Handle h;
    Atom* atom;
    Link* lll;

    if (extractedHandles == NULL) return;

    nodeIndex.remove(decayed);
    linkIndex.remove(decayed);
    typeIndex.remove(decayed);
    importanceIndex.remove(decayed);
    targetTypeIndex.remove(decayed);
    predicateIndex.remove(decayed);

    for (HandleEntry* curr = extractedHandles; curr != NULL; curr = curr->next) {
        h = curr->handle;
        atom = TLB::getAtom(h);
        //Extracts atom from hash_set
        atomSet.erase(atom);

        // update the AtomTable's size
        size--;

        if (useDSA)
            // updates all global statistics regarding the removal of this atom
            StatisticsMonitor::getInstance()->remove(atom);

        // remove from incoming sets
        lll = dynamic_cast<Link *>(atom);
        if (lll) {
            int arity = lll->getArity();
            for (int i = 0; i < arity; i++) {
                Atom *outgoing = lll->getOutgoingAtom(i);
                if (outgoing)
                    outgoing->removeIncomingHandle(h);
            }
        }
    }
}

void
afunc AAtomTable_LockIterators(AAtomTable AtomTable)
{
#ifdef HAVE_LIBPTHREAD
    pthread_mutex_lock(&iteratorsLock);
#endif
}

Handle
afunc AAtomTable_GetRandom(AAtomTable AtomTable, RandGen *rng)
{
    size_t b;
    size_t x;

    x = rng->randint(getSize());
    for (b = 0; b < atomSet.bucket_count(); b++) {
      if (x < atomSet.bucket_size(b)) {
        break;
      } else
        x -= atomSet.bucket_size(b);
    }
    boost::unordered_set<const Atom*>::const_local_iterator l = atomSet.begin(b);
    while (x > 0) {
      l++;
      assert(l!=atomSet.end(b));
      x--;
    }
    return (*l)->handle;
}

HandleIterator*
afunc AAtomTable_GetHandleIterator(AAtomTable AtomTable)
{
    return new HandleIterator(AtomTable, (Type)ATOM, true);
}

HandleIterator*
afunc AAtomTable_GetHandleIterator(AAtomTable AtomTable, Type type, bool subclass, VersionHandle vh)
{
    return new HandleIterator(AtomTable, type, subclass, vh);
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(Type =%d, bool=%d, AtomTableList=%d)\n", type, subclass, tableId);
    DPRINTF("About to call AtomTable::getHandleSet()\n");
    result = this->getHandleSet(type, subclass);
    DPRINTF("Got handles from AtomTable\n");
    result = HandleEntry::filterSet(result, vh);
    DPRINTF("Returning %p\n", result);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type type, Type targetType,
    bool subclass, bool targetSubclass, VersionHandle vh, VersionHandle targetVh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(Type type, Type targetType, bool subclass, bool targetSubclass, VersionHandle vh, VersionHandle targetVh, AtomTableList tableId)\n");
    result = this->getHandleSet(type, targetType, subclass, targetSubclass);
    result = HandleEntry::filterSet(result, vh);
    result = HandleEntry::filterSet(result, targetType, targetSubclass, targetVh);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Handle handle, Type type, bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(Handle handle, Type type, bool subclass, VersionHandle vh, AtomTableList tableId)\n");
    result = this->getHandleSet(handle, type, subclass);
    result = HandleEntry::filterSet(result, vh);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const AHandleVector& handles, Type* types,
    bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(const std::vector<Handle>& handles, Type* types, bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh, AtomTableList tableId)\n");
    result = AAtomTable_GetHandleSet(AtomTable, handles, types, subclasses, arity, type, subclass);
    result = HandleEntry::filterSet(result, vh);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* name, Type type,
    bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(const char* name, Type type, bool subclass, VersionHandle vh, AtomTableList tableId)\n");
    result = NULL;
    if (name == NULL) {
        result = AAtomTable_GetHandleSet(AtomTable, type, subclass, vh);
    } else {
        result = AAtomTable_GetHandleSet(AtomTable, name, type, subclass);
        result = HandleEntry::filterSet(result, vh);
    }
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char* targetName, Type targetType, Type type,
    bool subclass, VersionHandle vh, VersionHandle targetVh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(const char* targetName, Type targetType, Type type, bool subclass, VersionHandle vh, VersionHandle targetVh, AtomTableList tableId)\n");
    result = AAtomTable_GetHandleSet(AtomTable, targetName, targetType, type, subclass);
    result = HandleEntry::filterSet(result, vh);
    result = HandleEntry::filterSet(result, targetName, targetType, targetVh);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, const char** names, Type* types,
    bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(const char** names, Type* types, bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh, AtomTableList tableId)\n");
    result = AAtomTable_GetHandleSet(AtomTable, names, types, subclasses, arity, type, subclass);
    result = HandleEntry::filterSet(result, vh);
    return result;
}

HandleEntry*
afunc AAtomTable_GetHandleSet(AAtomTable AtomTable, Type* types, bool* subclasses, Arity arity, Type type,
    bool subclass, VersionHandle vh)
{
    HandleEntry* result;

    DPRINTF("AtomTable::getHandleSet(Type* types, bool* subclasses, Arity arity, Type type, bool subclass, VersionHandle vh, AtomTableList tableId\n");
    result = AAtomTable_GetHandleSet(AtomTable, types, subclasses, arity, type, subclass);
    result = HandleEntry::filterSet(result, vh);
    return result;
}

void
afunc AAtomTable_ScrubIncoming(AAtomTable AtomTable)
{
    AtomHashSet::const_iterator it;
    for (it = atomSet.begin(); it != atomSet.end(); ++it) {
        const Atom* atom = *it;
        Handle handle = atom->getHandle();

        // Updates incoming set of all targets.
        const Link * link = dynamic_cast<const Link *>(atom);
        if (link) {
            for (int i = 0; i < link->getArity(); i++) {
                Atom *oa = link->getOutgoingAtom(i);
                HandleEntry *he = oa->getIncomingSet();
                if (false == he->contains(handle)) {
                    oa->addIncomingHandle(handle);
                }
            }
        }
    }
}

void
afunc AAtomTable_TypeAdded(AAtomTable AtomTable, Type t)
{
    //resize all Type-based indexes
    nodeIndex.resize();
    linkIndex.resize();
    typeIndex.resize();
    targetTypeIndex.resize();
}

void
afunc AAtomTable_UnlockIterators(AAtomTable AtomTable)
{
#ifdef HAVE_LIBPTHREAD
    pthread_mutex_unlock(&iteratorsLock);
#endif
}

void
afunc AAtomTable_UpdateImportanceIndex(AAtomTable AtomTable, Atom* a, int bin)
{
    AtomTable->ImportanceIndex.updateImportance(a,bin);
}

AError
afunc AAtomTable_UnregisterIterator(AAtomTable AtomTable, HandleIterator* iterator)
{
    AAtomTable_LockIterators(AtomTable);

    std::vector<HandleIterator*>::iterator it = iterators.begin();
    while (it != iterators.end()) {
        if (*it == iterator) {
            iterators.erase(it);
            AAtomTable_UnlockIterators(AtomTable);
            return 0;
        } else {
            ++it;
        }
    }

    AAtomTable_UnlockIterators(AtomTable);
    //throw RuntimeException(TRACE_INFO, "could not unregister iterator");
    return -2;
}

bool
afunc AAtomTable_UsesDSA(AAtomTable AtomTable)
{
    return AtomTable->useDSA;
}

/*
std::size_t opencog::atom_ptr_hash::operator()(const Atom* const& x) const
{
    return x->hashCode();
}
*/

/*
bool opencog::atom_ptr_equal_to::operator()(const Atom* const& x,
                                            const Atom* const& y) const
{
    return *x == *y;
}
*/

