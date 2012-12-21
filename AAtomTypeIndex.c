/* AAtomTypeIndex
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/TypeIndex.cc
 */

/*
#include "TypeIndex.h"
#include "ClassServer.h"
#include "HandleEntry.h"
#include "TLB.h"
*/

//using namespace opencog;

ATypeIndex
afunc ATypeIndex_New()
{
    ATypeIndex Res;

    ATypeIndex = GetMem(sizeof(ATypeIndex_Type));
	ATypeIndex_Resize(Res);

    return Res;
}

void
afunc ATypeIndex_Resize(ATypeIndex TypeIndex)
{
	num_types = classserver().getNumberOfClasses();
	FixedIntegerIndex::resize(num_types + 1);
}

void
afunc ATypeIndex_InsertAtom(ATypeIndex TypeIndex, AAtom Atom)
{
    Type t;

	t = AAtom_GetType(Atom);
	insert(t, AAtom_GetHandle(Atom));
}

void
afunc ATypeIndex_RemoveAtom(ATypeIndex TypeIndex, AAtom Atom)
{
    Type t;

	t = AAtom_GetType(Atom);
	remove(t, AAtom_GetHandle(Atom));
}

HandleEntry*
afunc ATypeIndex_GetHandleSet(ATypeIndex TypeIndex, Type type, bool subclass)
{
	iterator it = begin(type, subclass);
	iterator itend = end();

	HandleEntry *he = NULL;
	while (it != itend)
	{
		HandleEntry *nhe = new HandleEntry(*it);
		nhe->next = he;
		he = nhe;
		it++;
	}
	return he;
}

// ================================================================

ATypeIndexIterator
afunc ATypeIndex_Begin(ATypeIndex TypeInded, Type t, bool sub)
{
	iterator it(t, sub);
	it.send = idx.end();

	it.s = idx.begin();
	it.currtype = 0;
	while (it.s != it.send)
	{
		// Find the first type which is a subtype, and start iteration there.
		if ((it.type == it.currtype) || 
		    (sub && (classserver().isA(it.currtype, it.type))))
		{
			it.se = it.s->begin();
			if (it.se != it.s->end()) return it;
		}
		it.currtype++;
		it.s++;
	}

	return it;
}

ATypeIndexIterator
afunc ATypeIndex_End(ATypeIndex TypeIndex)
{
	iterator it(num_types, false);
	it.se = idx.at(num_types).end();
	it.s = idx.end();
	it.send = idx.end();
	it.currtype = num_types;
	return it;
}

ATypeIndexInterator
afunc ATypeIndexIterator_New(Type t, bool sub)
{
    ATypeIndexIterator Res;

    Res = GetMem(sizeof(ATypeIndexIterator_Type));
	Res->type = t;
	Res->subclass = sub;

    return Res;
}

/*
TypeIndex::iterator& TypeIndex::iterator::operator=(iterator v)
{
	s = v.s;
	send = v.send;
	se = v.se;
	currtype = v.currtype;
	type = v.type;
	subclass = v.subclass;
	return *this;
}

Handle TypeIndex::iterator::operator*(void)
{
	if (s == send) return Handle::UNDEFINED;
	return *se;
}

bool TypeIndex::iterator::operator==(iterator v)
{
	if ((v.s == v.send) && (s == send)) return true;
	return v.se == se;
}

bool TypeIndex::iterator::operator!=(iterator v)
{
	if ((v.s == v.send) && (s != send)) return v.se != se;
	if ((v.s != v.send) && (s == send)) return v.se != se;
	return false;
}

TypeIndex::iterator& TypeIndex::iterator::operator++(int i)
{
	if (s == send) return *this;

	se++;
	if (se == s->end())
	{
		do
		{
			s++;
			currtype++;

			// Find the first type which is a subtype, and start iteration there.
			if ((type == currtype) ||
			    (subclass && (classserver().isA(currtype, type))))
			{
				se = s->begin();
				if (se != s->end()) return *this;
			}
		} while (s != send);
	}

	return *this;
}
*/

// ================================================================
