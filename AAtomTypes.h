/* AAtom basic type definitions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/types.h
 */

#ifndef AAtomTypes_H
#define AAtomTypes_H

#include "ABase2.h"

//#include <boost/variant.hpp>
//#include <opencog/atomspace/Handle.h>

typedef AAtom;

// type and arity of Atoms, represented as short integers (16 bits)
typedef unsigned short Type;
typedef unsigned short Arity;
// stimulus
typedef short stim_t;

//typedef boost::variant<Handle, Type, int, unsigned int, float, bool,
//                       unsigned char, char, short int> Vertex;

//typedef std::vector<Vertex> VertexSeq;

//class HandlePredicate {
//inline bool operator()(const Handle& h) { return this->test(h); }

//bool
//afunc HandlePredicate_Test(const Handle& h);
//{ return true; }

//class AtomPredicate {
//inline bool operator()(const Atom& a) { return this->test(a); }

//bool
//afunc AtomPredicate_Test(const Atom&);
//{ return true; }

//class AtomComparator {
//inline bool operator()(const Atom& a,const Atom& b) { return this->test(a,b); }

//bool
//afunc AtomComparator_Test(const Atom&,const Atom&);
//{ return true; }

#endif // AAtomTypes_H
