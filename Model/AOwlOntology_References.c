/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

// --- References/usage ---

/** Gets the entities that are in the signature of this ontology. The signature of an ontology is
 *  the set of entities that are used to build axioms and annotations in the ontology.
 *  (See <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Entities.2C_Literals.2C_and_Anonymous_Individuals">
 *  The OWL 2 Structural Specification</a>)
 *
 *  @return A set of <code>OWLEntity</code> objects. The set that is returned is a copy - it will
 *      not be updated if the ontology changes. It is therefore safe to apply changes to this
 *      ontology while iterating over this set.
 *  @see #AOwlOntology_GetClassesInSignature()
 *  @see #AOwlOntology_GetObjectPropertiesInSignature()
 *  @see #AOwlOntology_GetDataPropertiesInSignature()
 *  @see #AOwlOntology_GetIndividualsInSignature()
 */
AOwlEntitySet
func AOwlOntology_GetSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the entities that are in the signature of this ontology.  The signature of an ontology
 *  is the set of entities that are used to build axioms and annotations in the ontology.
 *  (See <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Entities.2C_Literals.2C_and_Anonymous_Individuals">
 *  The OWL 2 Structural Specification</a>)
 *
 *  @param IncludeImportsClosure - Specifies whether or not the returned set of entities should
 *      represent the signature of just this ontology, or the signature of the imports closure of
 *      this ontology.
 *  @return A set of <code>OWLEntity</code> objects. The set that is returned is a copy - it will
 *      not be updated if the ontology changes. It is therefore safe to apply changes to this
 *      ontology while iterating over this set.
 *  @see #AOwlOntology_GetClassesInSignature()
 *  @see #AOwlOntology_GetObjectPropertiesInSignature()
 *  @see #AOwlOntology_GetDataPropertiesInSignature()
 *  @see #AOwlOntology_GetIndividualsInSignature()
 */
AOwlEntitySet
func AOwlOntology_GetSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the classes that are in the signature of this ontology.
 *  @return A set of named classes, which are referenced by any axiom in this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlClassSet
func AOwlOntology_GetClassesInSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the classes that are in the signature of this ontology, and possibly the imports closure
 *  of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether classes should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code> then
 *      the set of classes returned will correspond to the union of the classes in the signatures
 *      of the ontologies in the imports closure of this ontology. If <code>false</code>
 *      then the set of classes returned will correspond to the classes that are in the signature
 *      of this just this ontology.
 *  @return A set of classes that are in the signature of this ontology and possibly the union of
 *      the signatures of the ontologies in the imports closure of this ontology. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore safe
 *      to apply changes to this ontology while iterating over this set.
 */
AOwlClassSet
func AOwlOntology_GetClassesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the object properties that are in the signature of this ontology.
 *  @return A set of object properties which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the object properties that are in the signature of this ontology, and possibly the
 *  imports closure of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether object properties should be drawn from the
 *      signature of just this ontology or the imports closure of this ontology. If
 *      <code>true</code> then the set of object properties returned will correspond to the union
 *      of the object properties in the signatures of the ontologies in the imports closure of
 *      this ontology. If <code>false</code> then the set of object properties returned will
 *      correspond to the object properties that are in the signature of this just this ontology.
 *  @return A set of object properties that are in the signature of this ontology and possibly
 *      the union of the signatures of the ontologies in the imports closure of this ontology.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature2(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the data properties that are in the signature of this ontology.
 *  @return A set of data properties, which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature3(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the data properties that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether data properties should be drawn from the
 *      signature of just this ontology or the imports closure of this ontology. If
 *      <code>true</code> then the set of data properties returned will correspond to the union
 *      of the data properties in the signatures of the ontologies in the imports closure of this
 *      ontology. If <code>false</code> then the set of data properties returned will correspond
 *      to the data properties that are in the signature of this just this ontology.
 *  @return A set of data properties that are in the signature of this ontology and possibly the
 *      union of the signatures of the ontologies in the imports closure of this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature4(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the individuals that are in the signature of this ontology.
 *  @return A set of individuals, which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the individuals that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *  @param IncludeImportsClosure Specifies whether individuals should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code>
 *      then the set of individuals returned will correspond to the union of the individuals
 *      in the signatures of the ontologies in the imports closure of this ontology.
 *      If <code>false</code> then the set of individuals returned will correspond to the
 *      individuals that are in the signature of this just this ontology.
 *  @return A set of individuals that are in the signature of this ontology and possibly the
 *      union of the signatures of the ontologies in the imports closure of this ontology.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the referenced anonymous individuals
 *  @return The set of referenced anonymous individuals
 */
AOwlAnonymousIndividualSet
func AOwlOntology_GetReferencedAnonymousIndividuals(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the datatypes that are in the signature of this ontology.
 *  @return A set of datatypes, which are in the signature of this ontology. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the datatypes that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *  @param IncludeImportsClosure - Specifies whether datatypes should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code> then
 *      the set of datatypes returned will correspond to the union of the datatypes in the
 *      signatures of the ontologies in the imports closure of this ontology. If <code>false</code>
 *      then the set of datatypes returned will correspond to the datatypes that are in the
 *      signature of this just this ontology.
 *  @return A set of datatypes that are in the signature of this ontology and possibly the union
 *      of the signatures of the ontologies in the imports closure of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the annotation properties that are in the signature of this ontology.
 *  @return A set of annotation properties, which are in the signature of this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlAnnotationPropertySet
func AOwlOntology_GetAnnotationPropertiesInSignature(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the axioms where the specified entity appears in the signature of the axiom. The set
 *  that is returned, contains all axioms that directly reference the specified entity.
 *
 *  @param OwlEntity - The entity that should be directly referred to by an axiom that appears
 *      in the results set.
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return 0;
}

/** Gets the axioms where the specified entity appears in the signature of the axiom. The set
 *  that is returned, contains all axioms that directly reference the specified entity.
 *
 *  @param OwlEntity - The entity that should be directly referred to by an axiom that appears
 *      in the results set.
 *  @param IncludeImportsClosure - Specifies if the axioms returned should just be from this
 *      ontology, or from the imports closure of this ontology. If <code>true</code> the axioms
 *      returned will be from the imports closure of this ontology, if <code>false</code>
 *      the axioms returned will just be from this ontology.
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the axioms that reference the specified anonymous individual
 *
 *  @param Individual - The individual
 *  @return The axioms that reference the specified anonymous individual
 */
AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms3(AOwlOntology Ontology, AOwlAnonymousIndividual Individual)
{
	return 0;
}

/** Determines if the signature of the ontology contains the specified entity.
 *
 *  @param OwlEntity - The entity
 *  @return <code>true</code> if the signature of this ontology contains <code>owlEntity</code>,
 *      otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return AFalse;
}

/** Determines if the signature of this ontology, and possibly the signature of any of the
 *  ontologies in the imports closure of this ontology, contains the specified entity.
 *
 *  @param OwlEntity - The entity
 *  @param IncludeImportsClosure - Specifies whether the imports closure should be examined for
 *      the entity reference or not.
 *  @return <code>true</code> if the ontology contains a reference to the specified entity,
 *      otherwise <code>false</code> The set that is returned is a copy - it will not be
 *      updated if the ontology changes. It is therefore safe to apply changes to this ontology
 *      while iterating over this set.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if the signature of this ontology contains a class, object property, data property,
 *  named individual, annotation property or datatype with the specified IRI.
 *
 *  @param EntityIRI - The IRI to test for.
 *  @return <code>true</code> if the signature of this ontology contains a class, object property,
 *      data property, named individual, annotation property or datatype with the specified IRI.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature3(AOwlOntology Ontology, AOwlIri EntityIri)
{
	return AFalse;
}

/** Determines if the signature of this ontology and possibly its imports closure contains a class,
 *  object property, data property, named individual, annotation property or datatype with the
 *  specified IRI.
 *
 *  @param EntityIRI - The IRI to test for.
 *  @param IncludeImportsClosure - Specifies whether the imports closure of this ontology should
 *      be examined or not.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if the
 *      signature of this ontology or the signature of an ontology in the imports closure of this
 *      ontology contains a class, object property, data property, named individual, annotation
 *      property or datatype with the specified IRI. If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains a class, object
 *      property, data property, named individual, annotation property or datatype with the
 *      specified IRI.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature4(AOwlOntology Ontology, AOwlIri EntityIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if this ontology declares an entity i.e. it contains a declaration axiom for the
 *  specified entity.
 *
 * @param OwlEntity - The entity to be tested for
 * @return <code>true</code> if the ontology contains a declaration for the specified entity,
 *     otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_IsDeclared(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return AFalse;
}

/** Determines if this ontology or its imports closure declares an entity i.e.
 *  contains a declaration axiom for the specified entity.
 *
 *  @param OwlEntity - The entity to be tested for
 *  @param IncludeImportsClosure - <code>true</code> if the imports closure of this ontology
 *      should be examined, <code>false</code> if just this ontology should be examined.
 *  @return <code>true</code> if the ontology or its imports closure contains a declaration for
 *      the specified entity, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_IsDeclared2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}
