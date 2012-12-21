/* AAtom
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/Atom.cc
 */

#include "AAtom.h"

/*
#include <set>

#ifndef WIN32
#include <unistd.h>
#endif

#include <opencog/atomspace/AtomSpaceDefinitions.h>
#include <opencog/atomspace/AtomTable.h>
#include <opencog/atomspace/ClassServer.h>
#include <opencog/atomspace/Link.h>
#include <opencog/atomspace/StatisticsMonitor.h>
#include <opencog/util/Logger.h>
#include <opencog/util/exceptions.h>
#include <opencog/util/misc.h>
#include <opencog/util/platform.h>

//#define DPRINTF printf
#define DPRINTF(...)

#undef Type
*/

AError
func AAtom_Init(AAtom Atom, Type T, const TruthValue& tv, const AttentionValue& av)
{
    Atom->Handle = Handle::UNDEFINED;
    Atom->Flags = 0;
    Atom->AtomTable = NULL;
    Atom->Incoming = NULL;
    Atom->Type = T;

    Atom->TruthValue = NULL;
    AAtom_SetTruthValue(tv);
    AAtom_SetAttentionValue(av);

    return 0;
}

AAtom
func Atom_New(Type type, const TruthValue& tv, const AttentionValue& av)
{
    AAtom Res;
    Res = GetMem(sizeof(AAtom_Type));
    AAtom_Init(Res, type, tv, av);
    return Res;
}

AError
func AAtom_Free(AAtom Atom)
{
    if (Atom->incoming != NULL) delete Atom->incoming;
    if (Atom->truthValue != &(TruthValue::DEFAULT_TV())) delete Atom->truthValue;
    return 0;
}

AttentionValue&
func AAtom_GetAttentionValue(AAtom Atom)
{
    return Atom->AttentionValue;
}

TruthValue*
func AAtom_GetTruthValue(AAtom Atom)
{
    return Atom->truthValue;
}

AError
func AAtom_SetTruthValue(AAtom Atom, const TruthValue& tv)
{
    if (Atom->truthValue != NULL && &tv != Atom->truthValue && Atom->truthValue != &(TruthValue::DEFAULT_TV())) {
        delete Atom->truthValue;
    }
    Atom->truthValue = (TruthValue*) & (TruthValue::DEFAULT_TV());
    if (!tv.isNullTv() && (&tv != &(TruthValue::DEFAULT_TV()))) {
        Atom->truthValue = tv.clone();
    }
    return 0;
}

AError
func AAtom_SetAttentionValue(AAtom Atom, const AttentionValue& new_av)
{
    int newBin;
    int oldBin;

    // --- Code ---

    if (new_av == Atom->attentionValue) return 0;

    oldBin = -1;
    if (Atom->atomTable != NULL) {
        // gets current bin
        oldBin = ImportanceIndex::importanceBin(Atom->attentionValue.getSTI());
    }

    Atom->attentionValue = new_av;

    if (Atom->atomTable != NULL) {
        // gets new bin
        newBin = ImportanceIndex::importanceBin(Atom->attentionValue.getSTI());

        // if the atom importance has changed its bin,
        // updates the importance index
        if (oldBin != newBin) {
            Atom->atomTable->updateImportanceIndex(this, oldBin);
            StatisticsMonitor::getInstance()->atomChangeImportanceBin(type, oldBin, newBin);
        }
    }
    return 0;
}

AError
func AAtom_AddIncomingHandle(AAtom Atom, Handle handle)
{
    HandleEntry* entry;

    // --- Code ---

    // creates a new entry with handle
    entry = new HandleEntry(handle);
    // entry is placed in the first position of the incoming set
    entry->next = incoming;
    Atom->incoming = entry;

    return 0;
}

AError
func AAtom_RemoveIncomingHandle(AAtom Atom, Handle handle)
{
    HandleEntry* current;
    HandleEntry* foundit;

    // --- Code ---

    DPRINTF("Entering Atom::removeIncomingHandle(): handle:\n%lu\nincoming:\n%s\n", handle.value(), Atom->incoming->toString().c_str());
    current = Atom->incoming;
    // checks if incoming set is empty
    if (Atom->incoming == NULL) {
        return -2;
        //throw RuntimeException(TRACE_INFO, "unable to extract incoming element from empty set");
    }

    // checks if the handle to be removed is the first one
    if (Atom->incoming->handle == handle) {
        Atom->incoming = Atom->incoming->next;
        current->next = NULL;
        delete current;
    } else {
        if (current->next == NULL) {
            return -3;
            //throw RuntimeException(TRACE_INFO, "unable to extract incoming element");
        }
        // scans the list looking for the desired handle
        while (current->next->handle != handle) {
            current = current->next;
            if (current->next == NULL) {
                return -4;
                //throw RuntimeException(TRACE_INFO, "unable to extract incoming element");
            }
        }
        // deletes entry when the handle is found
        foundit = current->next;
        current->next = foundit->next;
        foundit->next = NULL;
        delete foundit;
    }
    DPRINTF("Exiting Atom::removeIncomingHandle(): incoming:\n%s\n", Atom->incoming->toString().c_str());
    return 0;
}

bool
func AAtom_GetFlag(AAtom Atom, int Flag)
{
    return (Atom->Flags & flag) != 0;
}

AError
func AAtom_SetFlag(AAtom Atom, int Flag, bool Value)
{
    if (Value) {
        Atom->Flags |= Flag;
    } else {
        Atom->Flags &= ~(Flag);
    }
    return 0;
}

AError
func AAtom_UnsetRemovalFlag(AAtom Atom)
{
    Atom->Flags &= ~MARKED_FOR_REMOVAL;
    return 0;
}

AError
func AAtom_MarkForRemoval(AAtom Atom)
{
    Atom->Flags |= MARKED_FOR_REMOVAL;
    return 0;
}

AError
func AAtom_SetAtomTable(AAtom Atom, AtomTable *tb)
{
    Atom->atomTable = tb;
    return 0;
}

