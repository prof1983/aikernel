/* AOwlObject functions
 * Author(Prof1983 prof1983@ya.ru)
 * Created(14.06.2012)
 * LastMod(15.06.2012)
 * Version(0.0)
 *
 * Prototype: OwlApi
 * http://sourceforge.net/projects/owlapi/
 * http://owlapi.sourceforge.net/
 */

#include "AOwl.h"

// --- OwlObject ---

//void
//accept(OWLObjectVisitor visitor)

//<O> O
//accept(OWLObjectVisitorEx<O> visitor)

/** A convenience method that obtains the classes that are in the signature of this object.
 *  @return A set containing the classes (OwlClass) that are in the signature of this object.
 *      The set is a subset of the signature, and is not backed by the signature;
 *      it is a modifiable collection and changes are not reflected by the signature.
 */
AOwlEntitySet
func AOwlObject_GetClassesInSignature()
{
	return 0;
}

/** A convenience method that obtains the data properties that are in the
 *  signature of this object.
 *
 *  @return A set containing the data properties (OwlDataProperty) that are in the signature of
 *      this object. The set is a subset of the signature, and is not backed by the signature;
 *      it is a modifiable collection and changes are not reflected by the signature.
 */
AOwlEntitySet
func AOwlObject_GetDataPropertiesInSignature()
{
	return 0;
}

/** A convenience method that obtains the datatypes that are in the signature of this object.
 *
 *  @return A set containing the datatypes (OwlDatatype) that are in the signature of this object.
 *      The set is a subset of the signature, and is not backed by the signature;
 *      it is a modifiable collection and changes are not reflected by the signature.
 */
AOwlEntitySet
func AOwlObject_GetDatatypesInSignature()
{
	return 0;
}

/** A convenience method that obtains the individuals that are in the signature of this object.
 *
 *  @return A set containing the individuals (OwlNamedIndividual) that are in the signature of
 *      this object. The set is a subset of the signature, and is not backed by the signature;
 *      it is a modifiable collection and changes are not reflected by the signature.
 */
AOwlEntitySet
func AOwlObject_GetIndividualsInSignature()
{
	return 0;
}

/** Gets all of the nested (includes top level) class expressions that are used in this object.
 *
 *  @return A set of OWLClassExpressions that represent the nested class expressions used in
 *      this object.
 */
AOwlEntitySet
func AOwlObject_GetNestedClassExpressions()
{
	return 0;
}

/** A convenience method that obtains the object properties that are in the signature of this object.
 *  @return A set containing the object properties (OwlObjectProperty) that are in the signature
 *      of this object. The set is a subset of the signature, and is not backed by the signature;
 *      it is a modifiable collection and changes are not reflected by the signature.
 */
AOwlEntitySet
func AOwlObject_GetObjectPropertiesInSignature()
{
	return 0;
}

/** Gets the signature of this object.
 *
 *  @return A set of entities (OwlEntity) that correspond to the signature of this object.
 *      The set is an unmodifiable collection.
 */
AOwlEntitySet
func AOwlObject_GetSignature()
{
	return 0;
}

/** Determines if this object is either, owl:Nothing (the bottom class), owl:bottomObjectProperty
 *  (the bottom object property), owl:bottomDataProperty (the bottom data property).
 *
 *  @return true if this object corresponds to one of the above entities.
 */
ABoolean
func AOwlObject_IsBottomEntity()
{
	return AFalse;
}

/** Determines if this object is either, owl:Thing (the top class), owl:topObjectProperty
 *  (the top object property), owl:topDataProperty (the top data property) or rdfs:Literal
 *  (the top datatype).
 *
 *  @return true if this object corresponds to one of the above entities.
 */
ABoolean
func AOwlObject_IsTopEntity()
{
	return AFalse;
}
