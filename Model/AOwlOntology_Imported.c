/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

// --- Imported ontologies ---

/** Gets the set of document IRIs that are directly imported by this ontology.
 *  This corresponds to the IRIs defined by the directlyImportsDocument association as discussed
 *  in Section 3.4 of the OWL 2 Structural specification.
 *
 *  @return The set of directlyImportsDocument IRIs.
 *
 *  @return UnknownOwlOntologyException (-2) -  If this ontology is no longer managed by its
 *      manager because it was removed from the manager.
 */
AOwlIriSet
func AOwlOntology_GetDirectImportsDocuments(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the set of <em>loaded</em> ontologies that this ontology is related to via the
 *  directlyImports relation.  See Section 3.4 of the OWL 2 specification for the definition
 *  of the directlyImports relation.
 *  <p>
 *  Note that there may be fewer ontologies in the set returned by this method than there are
 *  IRIs in the set returned by the #AOwlOntology_GetDirectImportsDocuments() method.
 *  This will be the case if some of the ontologies that are directly imported by this ontology
 *  are not loaded for what ever reason.
 *  </p>
 *
 *  @return A set of ontologies such that for this ontology O, and each ontology O' in the set,
 *      (O, O') is in the directlyImports relation.
 *
 *  @return UnknownOwlOntologyException (-2) If this ontology is no longer managed by its
 *      manager because it was removed from the manager.
 */
AOwlOntologySet
func AOwlOntology_GetDirectImports(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the set of <em>loaded</em> ontologies that this ontology is related to via the
 *  <em>transitive closure</em> of the <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Imports">directlyImports relation</a>.
 *  <p>
 *  For example, if this ontology imports ontology B, and ontology B imports ontology C, then this method will return the set consisting of
 *  ontology B and ontology C.
 *  </p>
 *
 *  @return The set of ontologies that this ontology is related to via the transitive closure of
 *      the directlyImports relation. The set that is returned is a copy - it will not be updated
 *      if the ontology changes. It is therefore safe to apply changes to this ontology
 *      while iterating over this set.
 *
 *  @return UnknownOwlOntologyException (-2) if this ontology is no longer managed by its
 *      manager because it was removed from the manager.
 */
AOwlOntologySet
func AOwlOntology_GetImports(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the set of <em>loaded</em> ontologies that this ontology is related to via the
 *  <em>reflexive transitive closure</em> of the directlyImports relation
 *  as defined in Section 3.4 of the OWL 2 Structural Specification. (i.e. The set returned
 *  includes all ontologies returned by the #AOwlOntology_GetImports() method plus this ontology.)
 *
 *  <p>
 *  For example, if this ontology imports ontology B, and ontology B imports ontology C, then
 *  this method will return the set consisting of this ontology, ontology B and ontology C.
 *  </p>
 *
 *  @return The set of ontologies in the reflexive transitive closure of the directlyImports relation.
 *
 *  @return UnknownOwlOntologyException (-2) If this ontology is no longer managed by its
 *      manager because it was removed from the manager.
 */
AOwlOntologySet
func AOwlOntology_GetImportsClosure(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the set of imports declarations for this ontology.  The set returned represents the set
 *  of IRIs that correspond to the set of IRIs in an ontology's directlyImportsDocuments (see
 *  Section 3 in the OWL 2 structural specification).
 *
 *  @return The set of imports declarations that correspond to the set of ontology document IRIs
 *      that are directly imported by this ontology. The set that is returned is a copy - it will
 *      not be updated if the ontology changes. It is therefore safe to apply changes to this
 *      ontology while iterating over this set.
 */
AOwlImportsDeclarationSet
func AOwlOntology_GetImportsDeclarations(AOwlOntology Ontology)
{
	return 0;
}
