/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 19.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology.h"

// --- Axioms that form part of a description of a named entity ---

AOwlClassAxiomSet
func AOwlOntology_GetAxioms_Class(AOwlOntology Ontology, AOwlClass Cls)
{
	return 0;
}

AOwlObjectPropertyAxiomSet
func AOwlOntology_GetAxioms_ObjPropExpr(AOwlOntology Ontology, AOwlObjectPropertyExpression Prop)
{
	return 0;
}

AOwlDataPropertyAxiomSet
func AOwlOntology_GetAxioms_DataProp(AOwlOntology Ontology, AOwlDataProperty Prop)
{
	return 0;
}

AOwlIndividualAxiomSet
func AOwnOntology_GetAxioms_Individ(AOwlOntology Ontology, AOwlIndividual Individual)
{
	return 0;
}

AOwlAnnotationAxiomSet
func AOwlOntology_GetAxioms_AnnotationProp(AOwlOntology Ontology, AOwlAnnotationProperty Property)
{
	return 0;
}

AOwlDatatypeDefinitionAxiomSet
func AOwlOntology_GetAxioms_Datatype(AOwlOntology Ontology, AOwlDatatype Datatype)
{
	return 0;
}
