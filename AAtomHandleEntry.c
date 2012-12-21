/* AAtomHandleEntry
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/HandleEntry.cc
 */

/*
#include "HandleEntry.h"

#include <opencog/util/platform.h>

#include <opencog/atomspace/ClassServer.h>
#include <opencog/atomspace/CompositeTruthValue.h>
#include <opencog/atomspace/Link.h>
#include <opencog/atomspace/Node.h>
#include <opencog/atomspace/TLB.h>
#include <opencog/util/exceptions.h>

//#define DPRINTF printf
#define DPRINTF(...)

using namespace opencog;
*/

void
afunc AHandleEntry_Init(Handle handle)
{
    ++existingObjects;
    // linked-list with no head cell
    this->handle = handle;
    next = NULL;
}

AErrro
AHandleEntry_Free(AHandleEntry HandleEntry)
{
    --existingObjects;
    // recursion is not used to avoid stack overflow on large lists
    if (next != NULL) {
        HandleEntry *p, *q;
        p = q = next;
        while (p->next != NULL) {
            p = p->next;
            q->next = NULL;
            delete q;
            q = p;
        }
        delete p;
    }
}

AAtom
func AHandleEntry_GetAtom(AHandleEntry HandleEntry)
{
    return TLB::getAtom(HandleEntry->handle);
}

AHandleEntry
afunc AHandleEntry_Clone()
{
    AHandleEntry answer;
    AHandleEntry p;
    AHandleEntry q;

    if (this == NULL) return(NULL);

    // answer keeps the cloned list head while p is used to iterate in the
    // cloned list
    answer = p = new HandleEntry(handle);
    q = this->next;
    while (q != NULL) {
        p->next = new HandleEntry(q->handle);
        p = p->next;
        q = q->next;
    }
    return answer;
}

AInt
afunc AHandleEntry_GetSize(AHnadleEntry HandleEntry)
{
    AHandleEntry current;
    int size;

    current = HandleEntry;
    size = 0;
    // O(n) to get list size
    while (current != NULL) {
        current = current->next;
        size++;
    }
    return size;
}

AHandleEntry
afunc AHandleEntry_Last(AHandleEntry HandleEntry)
{
    AHandleEntry current;

    current = HandleEntry;
    // O(n) to get last member
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

ABoolean
afunc AHandleEntry_Contains(AHandleEntry HandleEntry, Handle h)
{
    AHandleEntry current;

    current = HandleEntry;
    while (current != NULL) {
        if (current->handle == h)
            return true;
        current = current->next;
    }
    return false;
}

AHandleEntry
afunc AHandleEntry_Intersection(AHandleEntry HandleEntry, AHandleEntry set1, AHandleEntry set2)
{
    std::vector<HandleEntry*> sets(2);
    sets[0] = set1;
    sets[1] = set2;
    return AHandleEntry_Intersection(HandleEntry, sets);
}

AHandleEntry
afunc AHandleEntry_Remove(AHandleEntry HandleEntry, AHandleEntry set, Handle h)
{
    AHandleEntry buffer;
    AHandleEntry head;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.
    while ((set != NULL) &&
            (set->handle == h)) {
        buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }
    if (set == NULL) return NULL;
    head = set;
    while (set->next != NULL) {
        if (set->next->handle == h) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }
    // head contains the filtered list.
    return head;
}

AInt
afunc AHandleEntry_HandleCompare(const void* e1, const void* e2)
{
    return Handle::compare(*((Handle *)e1), *((Handle *)e2));
}

AHandleEntry
afunc AHandleEntry_Intersection(std::vector<HandleEntry*>& sets)
{
    Handle** v;
    int* sizeArray;
    HandleEntry* current;
    int j;

    // leave this method if there are no lists
    if (sets.size() == 0) {
        return NULL;
    }

    // if there is at least one null list, intersection is empty
    for (unsigned int i = 0; i < sets.size(); i++) {
        if (sets[i] == NULL) {
            for (unsigned int j = 0; j < sets.size(); j++) {
                if (sets[j] != NULL) {
                    delete sets[j];
                }
            }
            return NULL;
        }
    }

    v = new Handle*[sets.size()];
    sizeArray = new int[sets.size()];

    // The set of linked-lists is transformed into a set of sorted arrays.
    // Each list is traversed and its elements are put into a regular array
    // which is sorted before being passed to the actual intersection
    // computation algorithm. Once the lists are transformed, they are deleted.
    for (unsigned int i = 0; i < sets.size(); i++) {
        sizeArray[i] = sets[i]->getSize();
        v[i] = new Handle[sizeArray[i]];

        // linked-list linearization
        current = sets[i];
        j = 0;
        while (current != NULL) {
            v[i][j++] = current->handle;
            current = current->next;
        }

        if (j != sizeArray[i]) {
            throw RuntimeException(TRACE_INFO, "consistency check failed for intersection");
        }

        // sets[i] is destroyed after v is set.
        delete sets[i];

        // each list is ordered, to make intersection algorithm cheaper.
        qsort(v[i], sizeArray[i], sizeof(Handle), handleCompare);
    }

    // this call will actually compute the intersection
    return intersection(v, sizeArray, sets.size());
}

AInt
afunc AHandleEntry_NextMatch(AHnadleEntry HandleEntry, Handle** sets, int* sizes, std::vector<int>& cursors)
{
    int n;
    bool fail;
    int cursor;
    Handle* handles;
    Handle max;

    n = cursors.size();
    for (;;) {
        fail = false;
        cursor = cursors[0];
        if (cursor >= sizes[0]) return -1; // prevents invalid data read
        handles = sets[0];
        max = handles[cursor];
        // Handle max(0); // this is zero, not null (the smallest possible pointer)
        // if current positions stored in cursors is not a match, the largest
        // value pointed by cursors is computed to reposition cursors
        // accordingly
        for (int j = 0; j < n; j++) {
            // overflow in one of the arrays: no more matches
            if (cursors[j] >= sizes[j]) {
                return -1;
            }
            if (sets[j][cursors[j]] >  max) {
                max = sets[j][cursors[j]];
            }
            if (sets[0][cursors[0]] != sets[j][cursors[j]]) {
                fail = true;
                // can't break here in order to compute max
            }
        }


        if (fail) {
            // current position is not a match, so cursors are updated to point
            // to the next element in each array which is greater than or
            // equals to max
            for (int j = 0; j < n; j++) {
                while (sets[j][cursors[j]] < max) {
                    cursors[j]++;
                    // overflow in one of the arrays: no more matches
                    if (cursors[j] >= sizes[j]) {
                        return -1;
                    }
                }
            }
        } else {
            // current position is a match so all cursors are incremented of 1
            for (int j = 0; j < n; j++) {
                cursors[j]++;
            }
            return cursors[0] - 1;
        }
    }
}

AHandleEntry
afunc AHandleEntry_Intersection(AHandleEntry HandleEntry, Handle** sets, int* sizes, int n)
{
    AHandleEntry answer
    AHandleEntry current;

    answer = NULL;
    current = NULL;

    // there is one cursor for each list.
    std::vector<int> cursors(n, 0);
    int pos;

    while ((pos = nextMatch(sets, sizes, cursors)) >= 0) {
        if (answer == NULL) {
            answer = current = new HandleEntry(sets[0][pos]);
        } else {
            current->next = new HandleEntry(sets[0][pos]);
            current = current->next;
        }
    }

    for (int i = 0; i < n; i++) {
        delete[](sets[i]);
    }
    delete[](sets);
    delete[](sizes);

    return answer;
}

AHandleEntry
afunc AHandleEntry_Concatenation(AHandleEntry HandleEntry, HandleEntry* set1, HandleEntry* set2)
{
    AHandleEntry current;

    if (set1 == NULL) return set2;

    if (set2 != NULL) {
        // it scans the first list until the last element is reached, and then
        // it makes the next of the last element point to the first element of the
        // second list.
        current = set1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = set2;
    }

    return set1;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, bool deleted)
{
    AHandleEntry buffer;
    AHandleEntry head;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while ((set != NULL) &&
            set->getAtom()->isMarkedForRemoval() != deleted) {
        buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }

    if (set == NULL) return NULL;


    head = set;
    while (set->next != NULL) {
        if (set->getAtom()->isMarkedForRemoval() != deleted) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_filterSet(AHandleEntry HandleEntry, AHandleEntry set, Arity arity)
{
    AAtom atom;
    ALink link;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL) {
        atom = set->getAtom();
        link = dynamic_cast<Link *>(atom);
        int lar = 0;
        if (link) lar = link->getArity();
        if (lar == arity) break;

        HandleEntry *buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }

    if (set == NULL) return NULL;

    HandleEntry* head = set;
    while (set->next != NULL) {
        atom = set->next->getAtom();
        link = dynamic_cast<Link *>(atom);
        int lar = 0;
        if (link) lar = link->getArity(); 
        if (lar != arity) {
            HandleEntry * buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, const char* name)
{
    AHandleEntry buffer;
    AHandleEntry head;
    AAtom itAtom;
    bool noName;

    noName = (name == NULL || *name == 0);

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL &&
           ((!noName && classserver().isLink(set->getAtom()->getType())) ||
            (noName && classserver().isNode(set->getAtom()->getType()) &&
              ((Node*) set->getAtom())->getName() != "") ||
            (!noName &&
              strcmp(((Node*) set->getAtom())->getName().c_str(), name)))) {
        buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }

    if (set == NULL) return NULL;

    head = set;
    while (set->next != NULL) {
        itAtom = set->next->getAtom();
        if ((!noName && classserver().isLink(itAtom->getType())) ||
            (noName && classserver().isNode(itAtom->getType()) &&
              ((Node*) itAtom)->getName() != "") ||
            (!noName && 
              strcmp(((Node*) itAtom)->getName().c_str(), name))) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Type type, bool subclass)
{
    AHandleEntry buffer;
    AHandleEntry head;

    if ((type == ATOM) && (subclass == true)) {
        return set;
    }

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while ((set != NULL) &&
            ((!subclass && (type != set->getAtom()->getType())) ||
             (subclass && !classserver().isA(set->getAtom()->getType(), type)))) {
        buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }

    if (set == NULL) return NULL;

    head = set;
    while (set->next != NULL) {
        if ((!subclass && (type != set->next->getAtom()->getType())) ||
            (subclass && !classserver().isA(set->next->getAtom()->getType(), type))) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, const char* name, Type type, bool subclass)
{
    return AHandleEntry_FilterSet(HandleEntry, filterSet(set, type, subclass), name);
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Handle handle, Arity arity)
{
    AHandleEntry buffer;

    // TODO: What is the arity parameter for?

    buffer = TLB::getAtom(handle)->getIncomingSet()->clone();

    return(intersection(set, buffer));
}


AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Handle handle, Arity position, Arity arity)
{
    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL) {
        Atom *atom = set->getAtom();
        Link *link = dynamic_cast<Link *>(atom);
        if (link && 
            ((link->getArity() != arity) ||
             (position >= arity) ||
             (link->getOutgoingSet()[position] != handle))) {
            HandleEntry *buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            break;
        }
    }
    if (set == NULL) return NULL;

    HandleEntry* head = set;
    while (set->next != NULL) {
        Atom *atom = set->next->getAtom();
        Link *link = dynamic_cast<Link *>(atom);
        if (link && ((link->getArity() != arity) ||
                (position >= arity) ||
                (link->getOutgoingSet()[position] != handle))) {
            HandleEntry *buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Type type, bool subclass, Arity arity)
{
    AHandleEntry buffer;
    Type target;
    AAtom atom;
    ALink link;
    AHandleEntry head;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL) {
        atom = set->getAtom();
        link = dynamic_cast<Link *>(atom);
        if (link->getArity() != arity) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            int position;
            for (position = 0; position < arity; position++) {
                if ((target = link->getOutgoingAtom(position)->getType()) &&
                        ((!subclass && (type == target)) ||
                         (subclass && classserver().isA(target, type)))) {
                    break;
                }
            }

            if (position == arity) {
                buffer = set;
                set = set->next;
                buffer->next = NULL;
                delete buffer;
            } else {
                break;
            }
        }
    }

    if (set == NULL) return NULL;

    head = set;
    while (set->next != NULL) {
        atom = set->next->getAtom();
        link = dynamic_cast<Link *>(atom);
        if (link->getArity() != arity) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            int position;
            for (position = 0; position < arity; position++) {
                if ((target = link->getOutgoingAtom(position)->getType()) &&
                        ((!subclass && (type == target)) ||
                         (subclass && classserver().isA(target, type)))) {
                    break;
                }
            }

            if (position == arity) {
                buffer = set->next;
                set->next = set->next->next;
                buffer->next = NULL;
                delete buffer;
            } else {
                set = set->next;
            }
        }

    }

    // head contains the filtered list.
    return head;
}


AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Type type, bool subclass, Arity position, Arity arity)
{
    AHandleEntry buffer;
    Type target;
    AAtom atom;
    ALink link;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL) {
        atom = set->getAtom();
        link = dynamic_cast<Link *>(atom);

        if ((link->getArity() != arity) ||
             (target = link->getOutgoingAtom(position)->getType(),
              ((!subclass && (type != target)) ||
               (subclass && !classserver().isA(target, type))))) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            break;
        }
    }

    if (set == NULL) return NULL;

    HandleEntry* head = set;
    while (set->next != NULL) {
        atom = set->next->getAtom();
        link = dynamic_cast<Link *>(atom);
        if (((link->getArity() != arity) ||
                (target = link->getOutgoingAtom(position)->getType(),
                 ((!subclass && (type != target)) ||
                  (subclass && !classserver().isA(target, type)))))) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, const char* name, Type type, bool subclass, Arity position, Arity arity)
{
    return filterSet(filterSet(set, type, subclass, position, arity), name, position, arity);
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, const char* name, Arity position, Arity arity)
{
    AHandleEntry buffer;
    bool noName;
    AAtom atom;
    ALink link;
    AAtom itAtom;

    noName = (name == NULL || *name == 0);

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while (set != NULL) {
        atom = set->getAtom();
        link = dynamic_cast<Link *>(atom);
        itAtom = NULL;
        if (link->getArity() == arity)
            itAtom = link->getOutgoingAtom(position);
        if (itAtom == NULL ||
             (!noName && classserver().isLink(itAtom->getType())) ||
             (noName && classserver().isNode(itAtom->getType()) &&
               ((Node*) itAtom)->getName() != "") ||
             (!noName &&
               strcmp(name, ((Node*) itAtom)->getName().c_str()))) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            break;
        }
    }

    if (set == NULL) return NULL;

    HandleEntry* head = set;
    while (set->next != NULL) {
        atom = set->next->getAtom();
        link = dynamic_cast<Link *>(atom);
        itAtom = NULL;
        if (link->getArity() == arity)
            itAtom = link->getOutgoingAtom(position);
        if (itAtom == NULL ||
             (!noName && classserver().isLink(itAtom->getType())) ||
             (noName && classserver().isNode(itAtom->getType()) &&
               ((Node*) itAtom)->getName() != "") ||
             (!noName &&
               strcmp(name, ((Node*) itAtom)->getName().c_str()))) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, AttentionValue::sti_t lowerBound, AttentionValue::sti_t upperBound)
{
    AHandleEntry buffer;
    AHandleEntry head;

    // The search for invalid elements need to be done in two steps because
    // invalid elements found in the middle of the list need to be treated
    // differently from invalid elements found in its begining.

    while ((set != NULL) &&
            ((set->getAtom()->getAttentionValue().getSTI() < lowerBound) ||
             (set->getAtom()->getAttentionValue().getSTI() > upperBound))) {
        buffer = set;
        set = set->next;
        buffer->next = NULL;
        delete buffer;
    }

    if (set == NULL) return NULL;

    head = set;
    while (set->next != NULL) {
        if ((set->next->getAtom()->getAttentionValue().getSTI() < lowerBound) ||
                (set->next->getAtom()->getAttentionValue().getSTI() > upperBound)) {
            buffer = set->next;
            set->next = set->next->next;
            buffer->next = NULL;
            delete buffer;
        } else {
            set = set->next;
        }
    }

    // head contains the filtered list.
    return head;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, VersionHandle vh)
{
    AHandleEntry head;
    AHandleEntry buffer;

    head = set;
    if (!isNullVersionHandle(vh)) {
        // The search for invalid elements need to be done in two steps because
        // invalid elements found in the middle of the list need to be treated
        // differently from invalid elements found in its begining.

        while ( (set != NULL) &&
                (set->getAtom()->getTruthValue().getType() != COMPOSITE_TRUTH_VALUE ||
                 ((const CompositeTruthValue&) set->getAtom()->getTruthValue()).getVersionedTV(vh).isNullTv())
              ) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        }

        if (set == NULL) return NULL;

        head = set;
        while (set->next != NULL) {
            if (set->next->getAtom()->getTruthValue().getType() != COMPOSITE_TRUTH_VALUE ||
                    ((const CompositeTruthValue&) set->next->getAtom()->getTruthValue()).getVersionedTV(vh).isNullTv()) {
                buffer = set->next;
                set->next = set->next->next;
                buffer->next = NULL;
                delete buffer;
            } else {
                set = set->next;
            }
        }
    }

    // head contains the filtered list.
    return head;
}

ABoolean
afunc AHandleEntry_MatchesFilterCriteria(AHandleEntry HandleEntry, AAtom atom, Type targetType, bool targetSubclasses, VersionHandle vh)
{
    bool result = false;
    Link *link = dynamic_cast<Link *>(atom);
    int larry = 0;
    if (link) {
        larry = link->getArity();
        for (int i = 0; i < larry && !result; i++) {
            const Atom* target = link->getOutgoingAtom(i);
            DPRINTF("Checking atom with TYPE = %s, TV = %s\n", classserver().getTypeName(target->getType()), target->getTruthValue().toString().c_str());
            if (target->getTruthValue().getType() == COMPOSITE_TRUTH_VALUE &&
                    !((const CompositeTruthValue&) target->getTruthValue()).getVersionedTV(vh).isNullTv()) {
                if (targetSubclasses) {
                    result = classserver().isA(target->getType(), targetType);
                } else {
                    result = targetType == target->getType();
                }
            }
        }
    }
    DPRINTF("matchesFilterCriteria (%s, %s, %s, [%p, %s]) returning %s\n",
            atom->toString().c_str(),
            classserver().getTypeName(targetType),
            targetSubclasses?"true":"false",
            vh.substantive,
            INDICATOR_TYPES[vh.indicator],
            result?"true":"false");
    return result;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, Type targetType, bool targetSubclasses, VersionHandle vh)
{
    AHandleEntry buffer;
    AHandleEntry head;

    head = set;
    if (!isNullVersionHandle(vh)) {

        // The search for invalid elements need to be done in two steps because
        // invalid elements found in the middle of the list need to be treated
        // differently from invalid elements found in its begining.

        while ( (set != NULL) && !matchesFilterCriteria(set->getAtom(), targetType, targetSubclasses, vh)) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        }

        if (set == NULL) return NULL;

        head = set;
        while (set->next != NULL) {
            if (!matchesFilterCriteria(set->next->getAtom(), targetType, targetSubclasses, vh)) {
                buffer = set->next;
                set->next = set->next->next;
                buffer->next = NULL;
                delete buffer;
            } else {
                set = set->next;
            }
        }
    }

    // head contains the filtered list.
    return head;
}

ABoolean
afunc AHandleEntry_MatchesFilterCriteria(AHandleEntry HandleEntry, AAtom atom, const char* targetName, Type targetType, VersionHandle vh)
{
    bool result;
    ALink link;
    int larry;

    result = false;
    link = dynamic_cast<Link *>(atom);
    larry = 0;
    if (link) {
        larry = link->getArity();
        for (int i = 0; i < larry && !result; i++) {
            const Atom* target = link->getOutgoingAtom(i);
            DPRINTF("Checking atom with TYPE = %s, TV = %s\n", classserver().getTypeName(target->getType()), target->getTruthValue().toString().c_str());
            if (classserver().isA(target->getType(), NODE)) {
                DPRINTF("Node name = %s\n", ((Node*) target)->getName().c_str());
            }

            if (target->getTruthValue().getType() == COMPOSITE_TRUTH_VALUE &&
                    !((const CompositeTruthValue&) target->getTruthValue()).getVersionedTV(vh).isNullTv()) {
                if (targetType == target->getType()) {
                    const char* nodeName = ((Node*) target)->getName().c_str();
                    result = !strcmp(targetName, nodeName);
                }
            }
        }
    }
    DPRINTF("matchesFilterCriteria (%s, %s, %s, [%p, %s]) returning %s\n",
            atom->toString().c_str(),
            targetName,
            classserver().getTypeName(targetType),
            vh.substantive,
            INDICATOR_TYPES[vh.indicator],
            result?"true":"false");
    return result;
}

AHandleEntry
afunc AHandleEntry_FilterSet(AHandleEntry HandleEntry, AHandleEntry set, const char* targetName, Type targetType, VersionHandle vh)
{
    AHandleEntry buffer;
    AHandleEntry head;

    head = set;
    if (!isNullVersionHandle(vh)) {
        // The search for invalid elements need to be done in two steps because
        // invalid elements found in the middle of the list need to be treated
        // differently from invalid elements found in its begining.

        while ( (set != NULL) && !matchesFilterCriteria(set->getAtom(), targetName, targetType, vh)) {
            buffer = set;
            set = set->next;
            buffer->next = NULL;
            delete buffer;
        }

        if (set == NULL) return NULL;

        head = set;
        while (set->next != NULL) {
            if (!matchesFilterCriteria(set->next->getAtom(), targetName, targetType, vh)) {
                buffer = set->next;
                set->next = set->next->next;
                buffer->next = NULL;
                delete buffer;
            } else {
                set = set->next;
            }
        }
    }

    // head contains the filtered list.
    return head;
}

/*
std::string HandleEntry::toString(void)
{
    std::string answer;

    for (HandleEntry* current = this; current != NULL; current = current->next) {
        Atom* atom = TLB::getAtom(current->handle);
        if (atom != NULL) {
            if (classserver().isA(atom->getType(), NODE)) {
                answer += ((Node*) atom)->getName();
            } else if (classserver().isA(atom->getType(), LINK)) {
                answer += ((Link*) atom)->toShortString();
            }
            //char buf[1024];
            //sprintf(buf,"[table=%d]", atom->getAtomTable());
            //answer += buf;
        }
        answer += " -> ";
    }
    answer += "NULL";
    return answer;
}
*/

/*
std::vector<Handle> HandleEntry::toHandleVector(void)
{
    std::vector<Handle> vector;
    for (HandleEntry* current = this; current != NULL; current = current->next) {
        vector.push_back(current->handle);
    }
    return vector;
}
*/

AHandleEntry
afunc AHandleEntry_FromHandleVector(AHandleVector HandleVector, const std::vector<Handle> &v)
{
    AHandleEntry ret;
    AHandleEntry temp;

    ret = NULL;
    size_t sz = v.size();
    for (int i = sz - 1; i >= 0; i--) {
        temp = new HandleEntry(v[i]);
        ret = HandleEntry::concatenation(temp, ret);
    }
    return(ret);
}
