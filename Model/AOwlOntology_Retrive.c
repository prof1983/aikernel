/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

// --- Methods to retrive class, property and individual axioms ---

/** Determines if this ontology is empty - an ontology is empty if it does not contain
 *  any axioms (i.e. #AOwlOntology_GetAxioms() returns the empty set), and it does not
 *  have any annotations (i.e. #AOwlOntology_GetAnnotations() returns the empty set).
 *
 *  @return <code>true</code> if the ontology is empty, otherwise <code>false</code>.
 */
ABoolean
func AOntology_IsEmpty(AOwlOntology Ontology)
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
func AOwlOntology_GetAxioms(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the number of axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetAxiomCount(AOwlOntology Ontology)
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
func AOwlOntology_GetLogicalAxioms(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the number of logical axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetLogicalAxiomCount(AOwlOntology Ontology)
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
func AOwlOntology_GetAxioms2(AOwlOntology Ontology, AOwlAxiomType AxiomType)
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
func AOwlOntology_GetAxioms3(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure)
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
AOwlAxiomSet
func AOwlOntology_GetTBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the axioms that form the ABox for this ontology, i.e., the ones whose type is in
 *  the AxiomType::ABoxAxiomTypes
 *
 *  @param IncludeImportsClosure - if <code>true</code> then axioms of the specified type will also
 *  be retrieved from the imports closure of this ontology, if <code>false</code> then axioms of
 *  the specified type will only be retrieved from this ontology.
 *  @return A set containing the axioms which are of the specified type. The set that is returned
 *      is a copy of the axioms in the ontology (and its imports closure) - it will not be
 *      updated if the ontology changes.
 */
AOwlAxiomSet
func AOwlOntology_GetABoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the axioms that form the RBox for this ontology, i.e., the ones whose type is in
 *  the AxiomType::RBoxAxiomTypes
 *
 *  @param IncludeImportsClosure - if <code>true</code> then axioms of the specified type will
 *      also be retrieved from the imports closure of this ontology, if <code>false</code>
 *      then axioms of the specified type will only be retrieved from this ontology.
 *  @return A set containing the axioms which are of the specified type. The set that is
 *      returned is a copy of the axioms in the ontology (and its imports closure) - it will
 *      not be updated if the ontology changes.
 */
AOwlAxiomSet
func AOwlOntology_GetRBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Gets the axiom count of a specific type of axiom
 *
 *  @param AxiomType - The type of axiom to count
 *  @return The number of the specified types of axioms in this ontology
 */
AInt
func AOwlOntology_GetAxiomCount2(AOwlOntology Ontology, AOwlAxiomType AxiomType)
{
	return 0;
}

/** Gets the axiom count of a specific type of axiom, possibly in the imports closure of
 *  this ontology
 *
 *  @param AxiomType - The type of axiom to count
 *  @param IncludeImportsClosure - Specifies that the imports closure should be included when counting axioms
 *  @return The number of the specified types of axioms in this ontology
 */
AInt
func AOwlOntology_GetAxiomCount3(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Determines if this ontology contains the specified axiom.
 *
 *  @param Axiom - The axiom to test for.
 *  @return <code>true</code> if the ontology contains the specified axioms, or <code>false</code>
 *      if the ontology doesn't contain the specified axiom.
 */
ABoolean
func AOwlOntology_ContainsAxiom(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return 0;
}

/** Determines if this ontology, and possibly the imports closure, contains the specified axiom.
 *
 *  @param Axiom - The axiom to test for.
 *  @param IncludeImportsClosure - if <code>true</code> the imports closure of this ontology will be
 *      searched for the specific axiom, if <code>false</code> just this ontology will be searched.
 *  @return <code>true</code> if the ontology contains the specified axioms, or <code>false</code>
 *      if the ontology doesn't contain the specified axiom.
 */
ABoolean
func AOwlOntology_ContainsAxiom2(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Determines if this ontology contains the specified axiom, but ignoring any annotations on this
 *  axiom. For example, if the ontology contains <code>SubClassOf(Annotation(p V) A B)</code> then
 *  this method will return <code>true</code> if the ontology contains <code>SubClassOf(A B)</code> or
 *  <code>SubClassOf(Annotation(q S) A B)</code> for any annotation property <code>q</code> and
 *  any annotation value <code>S</code>.
 *
 *  @param Axiom - The axiom to test for.
 *  @return <code>true</code> if this ontology contains this axiom with or without annotations.
 */
ABoolean
func AOwlOntology_ContainsAxiomIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return AFalse;
}

/** Gets the set of axioms contained in this ontology that have the same "logical structure" as
 *  the specified axiom.
 *
 *  @param axiom The axiom that specifies the logical structure of the axioms to retrieve.
 *      If this axiom is annotated then the annotations are ignored.
 *  @return A set of axioms such that for any two axioms, <code>axiomA</code> and
 *      <code>axiomB</code> in the set, <code>axiomA.getAxiomWithoutAnnotations()</code> is equal
 *      to <code>axiomB.getAxiomWithoutAnnotations()</code>. The specified axiom will be
 *      contained in the set.
 */
AOwlAxiomSet
func AOwlOntology_GetAxiomsIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom)
{
	return 0;
}

/** Gets the set of axioms contained in this ontology that have the same "logical structure" as
 *  the specified axiom, possibly searching the imports closure of this ontology.
 *
 *  @param Axiom - The axiom that specifies the logical structure of the axioms to retrieve.
 *      If this axiom is annotated then the annotations are ignored.
 *  @param IncludeImportsClosure - if <code>true</code> then axioms in the imports closure of
 *      this ontology are returned, if <code>false</code> only axioms in this ontology will
 *      be returned.
 *  @return A set of axioms such that for any two axioms, <code>axiomA</code> and
 *      <code>axiomB</code> in the set, <code>axiomA.getAxiomWithoutAnnotations()</code> is equal to
 *      <code>axiomB.getAxiomWithoutAnnotations()</code>.  The specified axiom will be
 *      contained in the set.
 */
AOwlAxiomSet
func AOwlOntology_GetAxiomsIgnoreAnnotations2(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return 0;
}

/** Determines if this ontology and possibly its imports closure contains the specified axiom but
 *  ignoring any annotations on this axiom. For example, if the ontology contains
 *  <code>SubClassOf(Annotation(p V) A B)</code> then this method
 *  will return <code>true</code> if the ontology contains <code>SubClassOf(A B)</code> or
 *  <code>SubClassOf(Annotation(q S) A B)</code> for any annotation property <code>q</code> and any annotation
 *  value <code>S</code>.
 *
 *  @param Axiom - The axiom to test for.
 *  @param IncludeImportsClosure - if <code>true</code> the imports closure of this ontology
 *      will be searched for the specified axiom. If <code>false</code> only this ontology
 *      will be searched for the specifed axiom.
 *  @return <code>true</code> if this ontology contains this axiom with or without annotations.
 */
ABoolean
func AOwlOntology_ContainsAxiomIgnoreAnnotations3(AOwlOntology Ontology, AOwlAxiom Axiom,
	ABoolean IncludeImportsClosure)
{
	return AFalse;
}

/** Gets the set of general axioms in this ontology.  This includes: <ul> <li>Subclass axioms
 *  that have a complex class as the subclass</li> <li>Equivalent class axioms that don't contain
 *  any named classes (<code>OWLClass</code>es)</li> <li>Disjoint class axioms that don't contain
 *  any named classes (<code>OWLClass</code>es)</li> </ul>
 *
 *  @return The set that is returned is a copy of the axioms in the ontology - it will not be
 *      updated if the ontology changes. It is therefore safe to apply changes to this ontology
 *      while iterating over this set.
 */
AOwlClassAxiomSet
func AOwlOntology_GetGeneralClassAxioms(AOwlOntology Ontology)
{
	return 0;
}
