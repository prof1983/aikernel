/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 19.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology.h"

// --- Access by IRI ---

ABoolean
func AOwlOntology_ContainsClassInSignature(AOwlOntology Ontology, AOwlIri OwlClassIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsClassInSignature2(AOwlOntology Ontology, AOwlIri OwlClassIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIri, ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsDataPropertyInSignature3(AOwlOntology Ontology,
	AOwlIri OwlDataPropertyIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsDataPropertyInSignature4(AOwlOntology Ontology,
	AOwlIri OwlDataPropertyIri, ABoolean includeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri, ABoolean IncludeImportsClosure)
{
	return 0;
}

ABoolean
func AOwlOntology_ContainsIndividualInSignature(AOwlOntology Ontology, AOwlIri OwlIndividualIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsIndividualInSignature2(AOwlOntology Ontology, AOwlIri OwlIndividualIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsDatatypeInSignature(AOwlOntology Ontology, AOwlIri OwlDatatypeIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsDatatypeInSignature2(AOwlOntology Ontology, AOwlIri OwlDatatypeIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature(AOwlOntology Ontology, AOwlIri Iri)
{
	return 0;
}

AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature2(AOwlOntology Ontology, AOwlIri Iri,
	ABoolean IncludeImportsClosure)
{
	return 0;
}
