/* OwlOntology functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 19.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology"

//////////////////////////////////////////////////////////////////////////////////////////////
//
// Various methods that provide axioms relating to specific entities that allow
// frame style views to be composed for a particular entity.  Such functionality is
// useful for ontology editors and browsers.
//
//////////////////////////////////////////////////////////////////////////////////////////////

AOwlDeclarationAxiomSet
func AOwlOntology_GetDeclarationAxioms(AOwlEntity Subject)
{
	return 0;
}

AOwlAnnotationAssertionAxiomSet
func AOwlOntology_GetAnnotationAssertionAxioms(AOwlAnnotationSubject Entity)
{
	return 0;
}
