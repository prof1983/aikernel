/* OwlOntology functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 19.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology"

// --- Object properties ---

AOwlSubObjectPropertyOfAxiomSet
func AOwlOntology_GetObjectSubPropertyAxiomsForSubProperty(AOwlObjectPropertyExpression SubProperty)
{
	return 0;
}

AOwlSubObjectPropertyOfAxiomSet
func AOwlOntology_GetObjectSubPropertyAxiomsForSuperProperty(
	AOwlObjectPropertyExpression SuperProperty)
{
	return 0;
}

AOwlObjectPropertyDomainAxiomSet
func AOwlOntology_GetObjectPropertyDomainAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlObjectPropertyRangeAxiomSet
func AOwlOntology_GetObjectPropertyRangeAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlInverseObjectPropertiesAxiomSet
func AOwlOntology_GetInverseObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlEquivalentObjectPropertiesAxiomSet
func AOwlOntology_GetEquivalentObjectPropertiesAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlDisjointObjectPropertiesAxiomSet
func AOwlOntology_GetDisjointObjectPropertiesAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlInverseFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetInverseFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlSymmetricObjectPropertyAxiomSet
func AOwlOntology_GetSymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlAsymmetricObjectPropertyAxiomSet
func AOwlOntology_GetAsymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlReflexiveObjectPropertyAxiomSet
func AOwlOntology_GetReflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlIrreflexiveObjectPropertyAxiomSet
func AOwlOntology_GetIrreflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

AOwlTransitiveObjectPropertyAxiomSet
func AOwlOntology_GetTransitiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}
