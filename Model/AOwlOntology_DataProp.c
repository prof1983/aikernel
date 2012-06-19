/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 19.06.2012
 * LastMod 19.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology.h"

// --- Data properties ---

AOwlSubDataPropertyOfAxiomSet
func AOwlOntology_GetDataSubPropertyAxiomsForSubProperty(AOwlDataProperty SubProperty)
{
	return 0;
}

AOwlSubDataPropertyOfAxiomSet
func AOwlOntology_GetDataSubPropertyAxiomsForSuperProperty(AOwlDataPropertyExpression SuperProperty)
{
	return 0;
}

AOwlDataPropertyDomainAxiomSet
func AOwlOntology_GetDataPropertyDomainAxioms(AOwlDataProperty Property)
{
	return 0;
}

AOwlDataPropertyRangeAxiomSet
func AOwlOntology_GetDataPropertyRangeAxioms(AOwlDataProperty Property)
{
	return 0;
}

AOwlEquivalentDataPropertiesAxiomSet
func AOwlOntology_GetEquivalentDataPropertiesAxioms(AOwlDataProperty Property)
{
	return 0;
}

AOwlDisjointDataPropertiesAxiomSet
func AOwlOntology_GetDisjointDataPropertiesAxioms(AOwlDataProperty Property)
{
	return 0;
}

AOwlFunctionalDataPropertyAxiomSet
func AOwlOntology_GetFunctionalDataPropertyAxioms(AOwlDataPropertyExpression Property)
{
	return 0;
}
