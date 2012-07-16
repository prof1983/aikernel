/* OwlOntology functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 19.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "AOwlOntology"

// --- Classes ---

AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSubClass(AOwlClass Cls)
{
	return 0;
}

AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSuperClass(AOwlClass Cls)
{
	return 0;
}

AOwlEquivalentClassesAxiomSet
func AOwlOntology_GetEquivalentClassesAxioms(AOwlClass Cls)
{
	return 0;
}

AOwlDisjointClassesAxiomSet
func AOwlOntology_GetDisjointClassesAxioms(AOwlClass Cls)
{
	return 0;
}

AOwlDisjointUnionAxiomSet
func AOwlOntology_GetDisjointUnionAxioms(AOwlClass OwlClass)
{
	return 0;
}

AOwlHasKeyAxiomSet
func AOwlOntology_GetHasKeyAxioms(AOwlClass Cls)
{
	return 0;
}
