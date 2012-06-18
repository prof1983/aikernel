/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

typedef AInt AOwlOntologyManager;

typedef struct {
	AOwlOntologyManager OwlOntologyManager;
	AOwlOntologyId OwlOntologyId;
} AOwlOntology_Type;

typedef AOwlEntitySet AOwlAnnotationSet;
typedef AOwlEntitySet AOwlIriSet;
typedef AOwlEntitySet AOwlOntologySet;
typedef AOwlEntitySet AOwlImportsDeclarationSet;
typedef AOwlEntitySet AOwlLogicalAxiomSet;

// --- Functions ---

/** Gets the manager that created this ontology. The manager is used by various methods on
 *  AOwlOntology to resolve imports
 *
 *  @return The manager that created this ontology.
 */
AOwlOntologyManager
func AOwlOntology_GetOwlOntologyManager()
{
	return 0;
}

/** Gets the identity of this ontology (i.e. ontology IRI + version IRI).
 *
 *  @return The ID of this ontology.
 */
AOwlOntologyId
func AOwlOntology_GetOntologyId()
{
	return 0;
}

/** Determines whether or not this ontology is anonymous.  An ontology is anonymous if it does
 *  not have an ontology IRI.
 *
 *  @return <code>true</code> if this ontology is anonymous, otherwise <code>false</code>
 */
ABoolean
func AOwlOntology_IsAnonymous()
{
	return AFalse;
}

/** Gets the annotations on this ontology.
 *
 *  @return A set of annotations on this ontology.  The set returned will be a copy - modifying
 *      the set will have no effect on the annotations in this ontology, similarly, any changes
 *      that affect the annotations on this ontology will not change the returned set.
 */
AOwlAnnotationSet
func AOwlOntology_GetAnnotations()
{
	return 0;
}

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
func AOwlOntology_GetDirectImportsDocuments()
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
func AOwlOntology_GetDirectImports()
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
func AOwlOntology_GetImports()
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
func AOwlOntology_GetImportsClosure()
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
AOwlImportsDeclarationSet AOwlOntology_GetImportsDeclarations()
{
	return 0;
}

// --- Methods to retrive class, property and individual axioms ---

/** Determines if this ontology is empty - an ontology is empty if it does not contain
 *  any axioms (i.e. #AOwlOntology_GetAxioms() returns the empty set), and it does not
 *  have any annotations (i.e. #AOwlOntology_GetAnnotations() returns the empty set).
 *
 *  @return <code>true</code> if the ontology is empty, otherwise <code>false</code>.
 */
ABoolean
func AOntology_IsEmpty()
{
	return ATrue;
}

/** Retrieves all of the axioms in this ontology. Note that to test whether or not this
 *  ontology is empty (i.e. contains no axioms, the isEmpty method is preferred over
 *  getAxioms().isEmpty(). )
 *
 *  @return The set of all axioms in this ontology, including logical axioms and annotation
 *      axioms. The set that is returned is a copy of the axioms in the ontology - it will
 *      not be updated if the ontology changes. It is recommended that the
 *      <code>containsAxiom</code> method is used to determine whether or not this ontology
 *      contains a particular axiom rather than using getAxioms().contains().
 */
AOwlAxiomSet
func AOwlOntology_GetAxioms()
{
	return 0;
}

/** Gets the number of axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetAxiomCount()
{
	return 0;
}

/** Gets all of the axioms in the ontology that affect the logical meaning of the ontology.
 *  In other words, this method returns all axioms that are not annotation axioms, or
 *  declaration axioms.
 *
 *  @return A set of axioms which are of the type <code>AOwlLogicalAxiom</code> The set that is
 *      returned is a copy of the axioms in the ontology - it will not be updated if the
 *      ontology changes.
 */
AOwlLogicalAxiomSet
func AOwlOntology_GetLogicalAxioms()
{
	return 0;
}

/** Gets the number of logical axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetLogicalAxiomCount()
{
	return 0;
}

/** Gets the axioms which are of the specified type.
 *
 *  @param AxiomType - The type of axioms to be retrived.
 *  @return A set containing the axioms which are of the specified type. The set that is
 *      returned is a copy of the axioms in the ontology - it will not be updated if the
 *      ontology changes.
 */
AOwlAxiomSet
func AOwlOntology_GetAxioms(AOwlAxiomType AxiomType)
{
	return 0;
}

/** Gets the axioms which are of the specified type.
 *
 *  @param AxiomType - The type of axioms to be retrived.
 *  @param IncludeImportsClosure - if <code>true</code> then axioms of the specified type will
 *      also be retrieved from the imports closure of this ontology, if <code>false</code>
 *      then axioms of the specified type will only be retrieved from this ontology.
 *  @return A set containing the axioms which are of the specified type. The set that is
 *      returned is a copy of the axioms in the ontology (and its imports closure) - it will
 *      not be updated if the ontology changes.
 */
AOwlAxiomSet
func AOwlOntology_GetAxioms(AOwlAxiomType AxiomType, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the axioms that form the TBox for this ontology, i.e., the ones whose type is in
 *  the AxiomType::TBoxAxiomTypes
 *
 *  @param IncludeImportsClosure - if <code>true</code> then axioms of the specified type
 *      will also be retrieved from the imports closure of this ontology, if <code>false</code>
 *      then axioms of the specified type will only be retrieved from this ontology.
 *  @return A set containing the axioms which are of the specified type. The set that is
 *      returned is a copy of the axioms in the ontology (and its imports closure) - it
 *      will not be updated if the ontology changes.
 */
AOwlAxiomSet AOwlOntology_GetTBoxAxioms(ABoolean IncludeImportsClosure)
{
	return 0;
}



