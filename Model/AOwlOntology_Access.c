/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

// --- Access by IRI ---

/** Determines if the signature of this ontology contains an OWLClass with the specified IRI.
 *
 *  @param OwlClassIRI - The IRI of the OWLClass to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLClass that has
 *      <code>owlClassIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsClassInSignature(AOwlOntology Ontology, AOwlIri OwlClassIRI)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the ontologies
 *  in the imports closure of this ontology, contains an OWLClass that has the specified IRI.
 *
 *  @param OwlClassIRI - The IRI of the class to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an OWLClass with <code>owlClassIRI</code> as its IRI in the signature of at least one
 *      ontology in the imports clousre of this ontology and <code>false</code> if this is not
 *      the case. If <code>includeImportsClosure=false</code> then returns <code>true</code>
 *      if the signature of this ontology contains an OWLClass that has <code>owlClassIRI</code>
 *      as its IRI and <code>false</code> if the signature of this ontology does not contain
 *      a class with <code>owlClassIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsClassInSignature2(AOwlOntology Ontology, AOwlIri OwlClassIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if the signature of this ontology contains an OWLObjectProperty with the specified IRI.
 *
 *  @param OwlObjectPropertyIri - The IRI of the OWLObjectProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLObjectProperty
 *      that has <code>owlObjectPropertyIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIRI)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLObjectProperty that
 *  has the specified IRI.
 *
 *  @param OwlObjectPropertyIri - The IRI of the OWLObjectProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlObjectProperty with <code>owlObjectPropertyIRI</code> as its IRI in the
 *      signature of at least one ontology in the imports clousre of this ontology
 *      and <code>false</code> if this is not the case.  If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlObjectProperty that has <code>owlObjectPropertyIRI</code> as its IRI and
 *      <code>false</code> if the signature of this ontology does not contain a class
 *      with <code>owlObjectPropertyIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIri, ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if the signature of this ontology contains an OWLDataProperty with the specified IRI.
 *
 *  @param OwlDataPropertyIri - The IRI of the OWLDataProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLDataProperty that
 *      has <code>owlDataPropertyIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsDataPropertyInSignature3(AOwlOntology Ontology, AOwlIri OwlDataPropertyIri)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLDataProperty that has
 *  the specified IRI.
 *
 *  @param OwlDataPropertyIri - The IRI of the OWLDataProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an OWLDataProperty with <code>owlDataPropertyIRI</code> as its IRI in the signature
 *      of at least one ontology in the imports clousre of this ontology and <code>false</code>
 *      if this is not the case. If <code>includeImportsClosure=false</code> then returns
 *      <code>true</code> if the signature of this ontology contains an AOwlDataProperty that
 *      has <code>owlDataPropertyIRI</code> as its IRI and <code>false</code> if the signature
 *      of this ontology does not contain a class with <code>owlDataPropertyIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsDataPropertyInSignature4(AOwlOntology Ontology, AOwlIri OwlDataPropertyIri,
	ABoolean includeImportsClosure)
{
	return AFalse;
}

/** Determines if the signature of this ontology contains an AOwlAnnotationProperty
 *  with the specified IRI.
 *
 *  @param OwlAnnotationPropertyIri - The IRI of the AOwlAnnotationProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an
 *      AOwlAnnotationProperty that has <code>owlAnnotationPropertyIRI</code> as its IRI,
 *      otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLAnnotationProperty
 *  that has the specified IRI.
 *
 *  @param OwlAnnotationPropertyIri - The IRI of the OWLAnnotationProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlAnnotationProperty with <code>owlAnnotationPropertyIRI</code> as its IRI in the
 *      signature of at least one ontology in the imports clousre of this ontology
 *      and <code>false</code> if this is not the case.  If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlAnnotationProperty that has <code>OwlAnnotationPropertyIRI</code> as its IRI
 *      and <code>false</code> if the signature of this ontology does not contain a class
 *      with <code>OwlAnnotationPropertyIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Determines if the signature of this ontology contains an OWLNamedIndividual with the
 *  specified IRI.
 *
 *  @param OwlIndividualIri - The IRI of the OWLNamedIndividual to check for.
 *  @return <code>true</code> if the signature of this ontology contains an AOwlNamedIndividual
 *      that has <code>owlIndividualIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsIndividualInSignature(AOwlOntology Ontology, AOwlIri OwlIndividualIri)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an AOwlNamedIndividual
 *  that has the specified IRI.
 *
 *  @param OwlIndividualIri - The IRI of the OWLNamedIndividual to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlNamedIndividual with <code>OwlIndividualIri</code> as its IRI in the
 *      signature of at least one ontology in the imports closure of this ontology
 *      and <code>false</code> if this is not the case. If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlNamedIndividual that has <code>OwlIndividualIri</code> as its IRI and <code>false</code>
 *      if the signature of this ontology does not contain a class with
 *      <code>OwlIndividualIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsIndividualInSignature2(AOwlOntology Ontology, AOwlIri OwlIndividualIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if the signature of this ontology contains an OWLDatatype with the specified IRI.
 *
 *  @param OwlDatatypeIri - The IRI of the OWLDatatype to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLDatatype that
 *      has <code>OwlDatatypeIri</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsDatatypeInSignature(AOwlOntology Ontology, AOwlIri OwlDatatypeIri)
{
	return AFalse;
}

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLDatatype that has the
 *  specified IRI.
 *
 *  @param OwlDatatypeIri - The IRI of the OWLDatatype to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlDatatype with <code>OwlDatatypeIri</code> as its IRI in the signature of at
 *      least one ontology in the imports closure of this ontology and <code>false</code> if
 *      this is not the case. If <code>includeImportsClosure=false</code> then returns
 *      <code>true</code> if the signature of this ontology contains an AOwlDatatype that
 *      has <code>OwlDatatypeIri</code> as its IRI and <code>false</code> if the signature
 *      of this ontology does not contain a class with <code>OwlDatatypeIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsDatatypeInSignature2(AOwlOntology Ontology, AOwlIri OwlDatatypeIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Gets the entities in the signature of this ontology that have the specified IRI.
 *
 *  @param Iri - The IRI of the entities to be retrieved.
 *  @return A set of entities that are in the signature of this ontology that have the specified
 *      IRI. The set will be empty if there are no entities in the signature of this ontology
 *      with the specified IRI.
 */
AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature(AOwlOntology Ontology, AOwlIri Iri)
{
	return 0;
}

/** Gets the entities in the signature of this ontology, and possibly the signature of the imports
 *  closure of this ontology, that have the specified IRI.
 *
 *  @param Iri - The IRI of the entitied to be retrieved.
 *  @param IncludeImportsClosure - Specifies if the signatures of the ontologies in the imports
 *      closure of this ontology should also be taken into account
 *  @return If <code>includeImportsClosure=true</code> then returns a set of entities that are
 *      in the signature of this ontology or the signature of an ontology in the imports closure
 *      of this ontology that have <code>iri</code> as their IRI. If
 *      <code>includeImportsClosure=false</code> then returns the entities in the signature
 *      of just this ontology that have <code>iri</code> as their IRI.
 */
AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature2(AOwlOntology Ontology, AOwlIri Iri,
	ABoolean IncludeImportsClosure)
{
	return 0;
}
