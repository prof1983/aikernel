/* AOwl types
Author(Prof1983 prof1983@ya.ru)
Created(14.06.2012)
LastMod(14.06.2012)
Version(0.0)

Prototype: OwlApi
http://sourceforge.net/projects/owlapi/
http://owlapi.sourceforge.net/
*/

#ifndef AOwl_H
#define AOwl_H

#include "ABase2.h"

#define ATypeDef(Var, Typ) typedef Typ Var

// --- OwlObject ---

ATypeDef(AOwlEntity, AInt);
ATypeDef(AOwlObject, AOwlEntity);
ATypeDef(AOwlEntitySet, AInt);
ATypeDef(AOwlEntityIterator, AInt);

// --- Node ---

ATypeDef(AOwlNode, AInt);
ATypeDef(AOwlDefaultNode, AOwlNode);
ATypeDef(AOwlClassNode, AOwlNode);
ATypeDef(AOwlDataPropertyNode, AOwlNode);
ATypeDef(AOwlDatatypeNode, AOwlNode);
ATypeDef(AOwlNamedIndividualNode, AOwlNode);
ATypeDef(AOwlObjectPropertyNode, AOwlNode);

#endif
