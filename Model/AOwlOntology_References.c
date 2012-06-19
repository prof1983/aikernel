/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 19.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology.h"

// --- References/usage ---

AOwlEntitySet
func AOwlOntology_GetSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlEntitySet
func AOwlOntology_GetSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlClassSet
func AOwlOntology_GetClassesInSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlClassSet
func AOwlOntology_GetClassesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature2(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature3(AOwlOntology Ontology)
{
	return 0;
}

AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature4(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAnonymousIndividualSet
func AOwlOntology_GetReferencedAnonymousIndividuals(AOwlOntology Ontology)
{
	return 0;
}

AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAnnotationPropertySet
func AOwlOntology_GetAnnotationPropertiesInSignature(AOwlOntology Ontology)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms3(AOwlOntology Ontology, AOwlAnonymousIndividual Individual)
{
	return 0;
}

ABoolean
func AOwlOntology_ContainsEntityInSignature(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsEntityInSignature2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsEntityInSignature3(AOwlOntology Ontology, AOwlIri EntityIri)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsEntityInSignature4(AOwlOntology Ontology, AOwlIri EntityIri,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_IsDeclared(AOwlOntology Ontology, AOwlEntity OwlEntity)
{
	return AFalse;
}

ABoolean
func AOwlOntology_IsDeclared2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}
