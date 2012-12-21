/* AAtom handle
 * Author Prof1983 <prof1983@ya.ru>
 * Created 21.12.2012
 * LastMod 21.12.2012
 * Prototype https://github.com/opencog/opencog.git/opencog/atomspace/Handle.h
 */

#ifndef AAtomHandle_H
#define AAtomHandle_H

#include "ABase"

//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <boost/unordered_set.hpp>

// UUID == Universally Unique Identifier
typedef unsigned long UUID;

typedef struct {
    // --- private ---
    UUID uuid;
} AAtomHandle_Type;

typedef AAtomHandle_Type* AAtomHandle;

typedef AAtomHandle Handle;

//class Handle
//{

/*
friend class TLB;
friend class AtomStorage;
friend class SchemeSmob;
friend class AtomspaceHTabler;
*/

// --- public ---

//static const Handle UNDEFINED;
//explicit Handle(const UUID u) : uuid(u) {};

AAtomHandle
afunc AAtomHandle_New(AAtomHandle h);
//: uuid(h.uuid) {};

//explicit Handle() : uuid(UNDEFINED.uuid) {};

//inline
UUID
afunc AAtomHandle_Value(AAtomHandle Handle);
//const { return uuid; }

/*
inline Handle& operator=(const Handle& h) {
    uuid = h.uuid;
    return *this;
}
inline bool operator==(const Handle& h) const { return uuid == h.uuid; }
inline bool operator!=(const Handle& h) const { return uuid != h.uuid; }
inline bool operator< (const Handle& h) const { return uuid <  h.uuid; }
inline bool operator> (const Handle& h) const { return uuid >  h.uuid; }
inline bool operator<=(const Handle& h) const { return uuid <= h.uuid; }
inline bool operator>=(const Handle& h) const { return uuid >= h.uuid; }
*/

/** Returns a negative value, zero or a positive value if the first
 *  argument is respectively smaller than, equal to, or larger than
 *  the second argument.
 *  @param The first handle element.
 *  @param The second handle element.
 *  @return A negative value, zero or a positive value if the first
 *      argument is respectively smaller than, equal to, or larger then the
 *      second argument.
 */
AInt
afunc AAtomHandle_Compare(AAtomHandle h1, AAtomHandle h2)
{
    if (h1->uuid < h2->uuid) return -1;
    if (h1->uuid > h2->uuid) return 1;
    return 0;
}

//typedef std::vector<Handle> HandleSeq;
//typedef std::vector<HandleSeq> HandleSeqSeq;
//typedef boost::unordered_set<Handle, boost::hash<opencog::Handle> > UnorderedHandleSet;

/*
static inline std::string operator+ (const char *lhs, Handle h)
{
    std::string rhs = lhs;
    char buff[25];
    snprintf(buff, 24, "%lu)", h.value());
    return rhs + buff;
}

static inline std::string operator+ (const std::string &lhs, Handle h)
{
    char buff[25];
    snprintf(buff, 24, "%lu)", h.value());
    return lhs + buff;
}

inline std::size_t hash_value(Handle const& h)
{
    return static_cast<std::size_t>(h.value());
}

} // namespace opencog

namespace std { 
inline std::ostream& operator<<(std::ostream& out, const opencog::Handle& h) {
    out << h.value();
    return out;
}
} //namespace std
*/

#endif // AAtomHandle_H
