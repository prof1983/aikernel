/* AAtomSpace
 * Author Prof1983 <prof1983@ya.ru>
 * Created 24.12.2012
 * LastMod 24.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/AtomSpace.cc
 */

/*
#include "AtomSpace.h"

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <time.h>
#include <cstdlib>

#include <pthread.h>
#include <stdlib.h>

#include <opencog/atomspace/ClassServer.h>
#include <opencog/atomspace/CompositeTruthValue.h>
#include <opencog/atomspace/HandleEntry.h>
#include <opencog/atomspace/IndefiniteTruthValue.h>
#include <opencog/atomspace/Link.h>
#include <opencog/atomspace/Node.h>
#include <opencog/atomspace/SimpleTruthValue.h>
#include <opencog/atomspace/StatisticsMonitor.h>
#include <opencog/atomspace/types.h>
#include <opencog/persist/xml/NMXmlExporter.h>
#include <opencog/util/Config.h>
#include <opencog/util/Logger.h>
#include <opencog/util/oc_assert.h>
*/

//#define DPRINTF printf
//#define DPRINTF(...)

/*
using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::min;
using std::max;
using namespace opencog;
*/

// ====================================================================

AAtomSpace
afunc AAtomSpace_New()
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    // Ensure caching is ready before anything else happens
    setUpCaching();
    #endif
    atomSpaceAsync = new AtomSpaceAsync();
    ownsAtomSpaceAsync = true;
    c_remove = atomSpaceAsync->removeAtomSignal(
            boost::bind(&AtomSpace::handleRemoveSignal, this, _1, _2));

}

AAtomSpace
afunc AAtomSpace_New(const AtomSpace& other)
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    // Ensure caching is ready before anything else happens
    setUpCaching();
    #endif
    this->atomSpaceAsync = other.atomSpaceAsync;
    ownsAtomSpaceAsync = false;
    c_remove = atomSpaceAsync->removeAtomSignal(
            boost::bind(&AtomSpace::handleRemoveSignal, this, _1, _2));
}

AAtomSpace
afunc AAtomSpace_New(AtomSpaceAsync& a)
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    setUpCaching();
    #endif
    atomSpaceAsync = &a;
    ownsAtomSpaceAsync = false;
}

AError
afunc AAtomSpace_Free(AAtomSpace AtomSpace)
{
    c_remove.disconnect();
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    delete __getType;
    delete getTypeCached;
    #endif
    // Will be unnecessary once GC is implemented
    if (ownsAtomSpaceAsync)
        delete atomSpaceAsync;
    return 0;
}

bool
afunc AAtomSpace_HandleRemoveSignal(AAtomSpace AtomSpace, AtomSpaceImpl *as, Handle h)
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    AtomSpace->GetTypeCached->remove(h);
    #endif
    return false;
}

Type
afunc AAtomSpace_GetType(AAtomSpace AtomSpace, Handle h)
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    Type t;

    t = (*getTypeCached)(h);
    return t;
    #else
    return atomSpaceAsync->getType(h)->get_result();
    #endif
}

#ifdef ZMQ_EXPERIMENT
TruthValue*
afunc AAtomSpace_GetTVZmq(AAtomSpace AtomSpace, Handle h, VersionHandle vh)
{
    TruthValueZmqRequest tvr;

    tvr = atomSpaceAsync->getTVZmq(h, vh);
    return tvr->get_result();
}
#endif

#ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
void
afunc AAtomSpace_SetUpCaching(AAtomSpace AtomSpace)
{
    // Initialise lru cache for getType
    __getType = new _getType(AtomSpace);
    getTypeCached = new lru_cache_threaded<AtomSpace::_getType>(1000, *__getType);
}
#endif

strength_t
afunc AAtomSpace_GetMean(AAtomSpace AtomSpace, Handle h, VersionHandle vh)
{
    FloatRequest tvr;

    tvr = atomSpaceAsync->getMean(h, vh);
    return tvr->get_result();
}

confidence_t
afunc AAtomSpace_GetConfidence(AAtomSpace AtomSpace, Handle h, VersionHandle vh)
{
    FloatRequest tvr;

    tvr = atomSpaceAsync->getConfidence(h, vh);
    return tvr->get_result();
}

TruthValuePtr
afunc AAtomSpace_GetTV(AAtomSpace AtomSpace, Handle h, VersionHandle vh)
{
    TruthValueCompleteRequest tvr;

    tvr = atomSpaceAsync->getTVComplete(h, vh);
    TruthValuePtr x(tvr->get_result());
    tvr->result = NULL; // cheat to avoid copying TruthValue once again
    return x;
}

void
afunc AAtomSpace_SetTV(AAtomSpace AtomSpace, Handle h, const TruthValue& tv, VersionHandle vh)
{
    atomSpaceAsync->setTV(h, tv, vh)->get_result();
}

/*
AtomSpace& AtomSpace::operator=(const AtomSpace& other)
{
    throw opencog::RuntimeException(TRACE_INFO,
            "AtomSpace - Cannot copy an object of this class");
}
*/

bool
afunc AAtomSpace_IsNode(AAtomSpace AtomSpace, const Handle& h)
{
    Type t;

    DPRINTF("AtomSpace::isNode Atom space address: %p\n", this);
    t = AAtomSpace_GetType(AtomSpace, h);
    return classserver().isA(t, NODE);
}

bool
afunc AAtomSpace_IsLink(AAtomSpace AtomSpace, const Handle& h)
{
    Type t;

    DPRINTF("AtomSpace::isLink Atom space address: %p\n", this);
    t = AAtomSpace_GetType(h);
    return classserver().isA(t, LINK);
}

void
afunc AAtomSpace_Do_merge_tv(AAtomSpace AtomSpace, Handle h, const TruthValue& tvn)
{
    TruthValuePtr currentTV(getTV(h));
    if (currentTV->isNullTv()) {
        setTV(h, tvn);
    } else {
        TruthValue* mergedTV = currentTV->merge(tvn);
        setTV(h, *mergedTV);
        delete mergedTV;
    }
}

Handle
afunc AAtomSpace_AddPrefixedNode(AAtomSpace AtomSpace, Type t, const string& prefix, const TruthValue& tvn)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    static const int len = 16;
    string name;
    Handle result;
    //Keep trying new random suffixes until you generate a new name
    do {
        name=prefix;
        for (int i = 0; i < len; ++i) {
            name+=alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        result = getHandle(t, name);
    } while(isValidHandle(result));//If the name already exists, try again
    return addNode(t, name, tvn);
}

Handle
afunc AAtomSpace_AddRealAtom(AAtomSpace AtomSpace, const Atom& atom, const TruthValue& tvn)
{
    Handle result;

    DPRINTF("AtomSpace::addRealAtom\n");
    const TruthValue& newTV = (tvn.isNullTv()) ? atom.getTruthValue() : tvn;
    // Check if the given Atom reference is of an atom
    // that was not inserted yet.  If so, adds the atom. Otherwise, just sets
    // result to the correct/valid handle.
    const Node *node = dynamic_cast<const Node *>(&atom);
    if (node) {
        result = getHandle(node->getType(), node->getName());
        if (result == Handle::UNDEFINED) {
            return addNode(node->getType(), node->getName(), newTV);
        }
    } else {
        const Link *link = dynamic_cast<const Link *>(&atom);
        result = getHandle(link->getType(), link->getOutgoingSet());
        if (result == Handle::UNDEFINED) {
            return addLink(link->getType(), link->getOutgoingSet(), newTV);
        }
    }
    do_merge_tv(result,newTV);
    return result;
}

boost::shared_ptr<Atom>
afunc AAtomSpace_CloneAtom(AAtomSpace AtomSpace, const Handle& h)
{
    return atomSpaceAsync->getAtom(h)->get_result();
}

size_t
afunc AAtomSpace_GetAtomHash(AAtomSpace AtomSpace, const Handle& h)
{
    return atomSpaceAsync->getAtomHash(h)->get_result();
}

bool
afunc AAtomSpace_IsValidHandle(AAtomSpace AtomSpace, const Handle& h)
{
    return atomSpaceAsync->isValidHandle(h)->get_result();
}

bool
afunc AAtomSpace_CommitAtom(AAtomSpace AtomSpace, const Atom& a)
{
    return atomSpaceAsync->commitAtom(a)->get_result();
}

AttentionValue
afunc AAtomSpace_GetAV(AAtomSpace AtomSpace, Handle h)
{
    return atomSpaceAsync->getAV(h)->get_result();
}

void
afunc AAtomSpace_SetAV(AAtomSpace AtomSpace, Handle h, const AttentionValue &av)
{
    atomSpaceAsync->setAV(h,av)->get_result();
}

int
afunc AAtomSpace_Nodes(AAtomSpace AtomSpace, VersionHandle vh)
{
    return atomSpaceAsync->nodeCount(vh)->get_result();
}

int
afunc AAtomSpace_Links(AAtomSpace AtomSpace, VersionHandle vh)
{
    return atomSpaceAsync->linkCount(vh)->get_result();
}

void
afunc AAtomSpace_DecayShortTermImportance(AAtomSpace AtomSpace)
{
    atomSpaceAsync->decayShortTermImportance()->get_result();
}

AttentionValue::sti_t
afunc AAtomSpace_GetAttentionalFocusBoundary(AAtomSpace AtomSpace)
{
    return atomSpaceAsync->atomspace.getAttentionBank().getAttentionalFocusBoundary();
}

AttentionValue::sti_t
afunc AAtomSpace_SetAttentionalFocusBoundary(AAtomSpace AtomSpace, AttentionValue::sti_t s)
{
    return atomSpaceAsync->atomspace.getAttentionBank().setAttentionalFocusBoundary(s);
}

void
afunc AAtomSpace_Clear(AAtomSpace AtomSpace)
{
    #ifdef USE_ATOMSPACE_LOCAL_THREAD_CACHE
    getTypeCached->clear();
    #endif
    atomSpaceAsync->clear()->get_result();
}

void
afunc AAtomSpace_Print(AAtomSpace AtomSpace, std::ostream& output, Type type, bool subclass)
{
    atomSpaceAsync->print(output, type, subclass)->get_result();
}
