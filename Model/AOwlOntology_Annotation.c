/* OwlOntology functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 19.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology"

// --- Annotation axioms  ---

AOwlSubAnnotationPropertyOfAxiomSet
func AOwlOntology_GetSubAnnotationPropertyOfAxioms(AOwlAnnotationProperty SubProperty)
{
	return 0;
}

AOwlAnnotationPropertyDomainAxiomSet
func AOwlOntology_GetAnnotationPropertyDomainAxioms(AOwlAnnotationProperty Property)
{
	return 0;
}

AOwlAnnotationPropertyRangeAxiomSet
func AOwlOntology_GetAnnotationPropertyRangeAxioms(AOwlAnnotationProperty Property)
{
	return 0;
}
