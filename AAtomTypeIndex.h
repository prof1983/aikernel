/* AAtomTypeIndex
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/TypeIndex.h
 */

#ifndef AAtomTypeIndex_H
#define AAtomTypeIndex_H

/*
#include <set>
#include <vector>

#include <opencog/atomspace/FixedIntegerIndex.h>
#include <opencog/atomspace/Handle.h>
*/

#include "AAtomTypes.h"

//class HandleEntry;

/** Implements an integer index as an RB-tree (C++ set) */

typedef struct {
    // --- private ---
    size_t num_types;
} ATypeIndex_Type;

typedef ATypeIndex_Type* ATypeIndex;

// --- class TypeIndex: public FixedIntegerIndex ---

// --- public ---

ATypeIndex
afunc ATypeIndex_New();

void
afunc ATypeIndex_InsertAtom(ATypeIndex TypeIndex, AAtom Atom);

void
afunc ATypeIndex_RemoveAtom(ATypeIndex TypeIndex, AAtom Atom);

void
afunc ATypeIndex_Resize(ATypeIndex TypeIndex);

HandleEntry*
afunc ATypeIndex_GetHandleSet(ATypeIndex TypeIndex, Type type, bool subclass);

/*
class iterator
{
    friend class TypeIndex;
    public:
        iterator(Type, bool);
        iterator& operator++(int);
        iterator& operator=(iterator);
        bool operator==(iterator);
        bool operator!=(iterator);
        Handle operator*(void);
    private:
        Type type;
        bool subclass;
        std::vector<UnorderedHandleSet>::const_iterator s;
        std::vector<UnorderedHandleSet>::const_iterator send;
        Type currtype;
        UnorderedHandleSet::const_iterator se;
};

iterator begin(Type, bool) const;
iterator end(void) const;
*/

#endif // AAtomTypeIndex_H
