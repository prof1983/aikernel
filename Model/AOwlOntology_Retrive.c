/* OwlOntology functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 18.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology"

// --- Methods to retrive class, property and individual axioms ---

ABoolean
func AOwlOntology_IsEmpty(AOwlOntology Ontology)
{
	return ATrue;
}

AOwlAxiomSet
func AOwlOntology_GetAxioms(AOwlOntology Ontology)
{
	return 0;
}

AInt
func AOwlOntology_GetAxiomCount(AOwlOntology Ontology)
{
	return 0;
}

AOwlLogicalAxiomSet
func AOwlOntology_GetLogicalAxioms(AOwlOntology Ontology)
{
	return 0;
}

AInt
func AOwlOntology_GetLogicalAxiomCount(AOwlOntology Ontology)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetAxioms_Type(AOwlOntology Ontology, AOwlAxiomType AxiomType)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetAxioms_Type2(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetTBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetABoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetRBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

AInt
func AOwlOntology_GetAxiomCount2(AOwlOntology Ontology, AOwlAxiomType AxiomType)
{
	return 0;
}

AInt
func AOwlOntology_GetAxiomCount3(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

ABoolean
func AOwlOntology_ContainsAxiom(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return 0;
}

ABoolean
func AOwlOntology_ContainsAxiom2(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

ABoolean
func AOwlOntology_ContainsAxiomIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return AFalse;
}

AOwlAxiomSet
func AOwlOntology_GetAxiomsIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return 0;
}

AOwlAxiomSet
func AOwlOntology_GetAxiomsIgnoreAnnotations2(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

ABoolean
func AOwlOntology_ContainsAxiomIgnoreAnnotations3(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

AOwlClassAxiomSet
func AOwlOntology_GetGeneralClassAxioms(AOwlOntology Ontology)
{
	return 0;
}
