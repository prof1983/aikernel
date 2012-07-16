/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#ifndef AOwlOntology_H
#define AOwlOntology_H

#include "AOwlTypes.h"

// --- Types ---

typedef AInt AOwlOntologyManager;

typedef struct {
	AOwlOntologyManager OwlOntologyManager;
	AOwlOntologyId OwlOntologyId;
} AOwlOntology_Type;

// --- Functions ---

/** Gets the manager that created this ontology. The manager is used by various methods on
 *  AOwlOntology to resolve imports
 *
 *  @return The manager that created this ontology.
 */
AOwlOntologyManager
func AOwlOntology_GetOwlOntologyManager(AOwlOntology Ontology);

/** Gets the identity of this ontology (i.e. ontology IRI + version IRI).
 *
 *  @return The ID of this ontology.
 */
AOwlOntologyId
func AOwlOntology_GetOntologyId(AOwlOntology Ontology);

/** Determines whether or not this ontology is anonymous.  An ontology is anonymous if it does
 *  not have an ontology IRI.
 *
 *  @return <code>true</code> if this ontology is anonymous, otherwise <code>false</code>
 */
ABoolean
func AOwlOntology_IsAnonymous(AOwlOntology Ontology);

/** Gets the annotations on this ontology.
 *
 *  @return A set of annotations on this ontology.  The set returned will be a copy - modifying
 *      the set will have no effect on the annotations in this ontology, similarly, any changes
 *      that affect the annotations on this ontology will not change the returned set.
 */
AOwlAnnotationSet
func AOwlOntology_GetAnnotations(AOwlOntology Ontology);

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
func AOwlOntology_GetDirectImportsDocuments(AOwlOntology Ontology);

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
func AOwlOntology_GetDirectImports(AOwlOntology Ontology);

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
func AOwlOntology_GetImports(AOwlOntology Ontology);

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
func AOwlOntology_GetImportsClosure(AOwlOntology Ontology);

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
func AOwlOntology_GetImportsDeclarations(AOwlOntology Ontology);

// --- Methods to retrive class, property and individual axioms ---

/** Determines if this ontology is empty - an ontology is empty if it does not contain
 *  any axioms (i.e. #AOwlOntology_GetAxioms() returns the empty set), and it does not
 *  have any annotations (i.e. #AOwlOntology_GetAnnotations() returns the empty set).
 *
 *  @return <code>true</code> if the ontology is empty, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_IsEmpty(AOwlOntology Ontology);

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
func AOwlOntology_GetAxioms(AOwlOntology Ontology);

/** Gets the number of axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetAxiomCount(AOwlOntology Ontology);

/** Gets all of the axioms in the ontology that affect the logical meaning of the ontology.
 *  In other words, this method returns all axioms that are not annotation axioms, or
 *  declaration axioms.
 *
 *  @return A set of axioms which are of the type <code>AOwlLogicalAxiom</code> The set that is
 *      returned is a copy of the axioms in the ontology - it will not be updated if the
 *      ontology changes.
 */
AOwlLogicalAxiomSet
func AOwlOntology_GetLogicalAxioms(AOwlOntology Ontology);

/** Gets the number of logical axioms in this ontology.
 *
 *  @return The number of axioms in this ontology.
 */
AInt
func AOwlOntology_GetLogicalAxiomCount(AOwlOntology Ontology);

/** Gets the axioms which are of the specified type.
 *
 *  @param AxiomType - The type of axioms to be retrived.
 *  @return A set containing the axioms which are of the specified type. The set that is
 *      returned is a copy of the axioms in the ontology - it will not be updated if the
 *      ontology changes.
 */
AOwlAxiomSet
func AOwlOntology_GetAxioms_Type(AOwlOntology Ontology, AOwlAxiomType AxiomType);

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
func AOwlOntology_GetAxioms_Type2(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure);

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
func AOwlOntology_GetTBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

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
func AOwlOntology_GetABoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

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
func AOwlOntology_GetRBoxAxioms(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

/** Gets the axiom count of a specific type of axiom
 *
 *  @param AxiomType - The type of axiom to count
 *  @return The number of the specified types of axioms in this ontology
 */
AInt
func AOwlOntology_GetAxiomCount2(AOwlOntology Ontology, AOwlAxiomType AxiomType);

/** Gets the axiom count of a specific type of axiom, possibly in the imports closure of
 *  this ontology
 *
 *  @param AxiomType - The type of axiom to count
 *  @param IncludeImportsClosure - Specifies that the imports closure should be included when counting axioms
 *  @return The number of the specified types of axioms in this ontology
 */
AInt
func AOwlOntology_GetAxiomCount3(AOwlOntology Ontology, AOwlAxiomType AxiomType,
	ABoolean IncludeImportsClosure);

/** Determines if this ontology contains the specified axiom.
 *
 *  @param Axiom - The axiom to test for.
 *  @return <code>true</code> if the ontology contains the specified axioms, or <code>false</code>
 *      if the ontology doesn't contain the specified axiom.
 */
ABoolean
func AOwlOntology_ContainsAxiom(AOwlOntology Ontology, AOwlAxiom Axiom);

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
	ABoolean IncludeImportsClosure);

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
func AOwlOntology_ContainsAxiomIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom);

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
func AOwlOntology_GetAxiomsIgnoreAnnotations(AOwlOntology Ontology, AOwlAxiom Axiom);

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
	ABoolean IncludeImportsClosure);

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
	ABoolean IncludeImportsClosure);

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
func AOwlOntology_GetGeneralClassAxioms(AOwlOntology Ontology);

// --- References/usage ---

/** Gets the entities that are in the signature of this ontology. The signature of an ontology is
 *  the set of entities that are used to build axioms and annotations in the ontology.
 *  (See <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Entities.2C_Literals.2C_and_Anonymous_Individuals">
 *  The OWL 2 Structural Specification</a>)
 *
 *  @return A set of <code>OWLEntity</code> objects. The set that is returned is a copy - it will
 *      not be updated if the ontology changes. It is therefore safe to apply changes to this
 *      ontology while iterating over this set.
 *  @see #AOwlOntology_GetClassesInSignature()
 *  @see #AOwlOntology_GetObjectPropertiesInSignature()
 *  @see #AOwlOntology_GetDataPropertiesInSignature()
 *  @see #AOwlOntology_GetIndividualsInSignature()
 */
AOwlEntitySet
func AOwlOntology_GetSignature(AOwlOntology Ontology);

/** Gets the entities that are in the signature of this ontology.  The signature of an ontology
 *  is the set of entities that are used to build axioms and annotations in the ontology.
 *  (See <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Entities.2C_Literals.2C_and_Anonymous_Individuals">
 *  The OWL 2 Structural Specification</a>)
 *
 *  @param IncludeImportsClosure - Specifies whether or not the returned set of entities should
 *      represent the signature of just this ontology, or the signature of the imports closure of
 *      this ontology.
 *  @return A set of <code>OWLEntity</code> objects. The set that is returned is a copy - it will
 *      not be updated if the ontology changes. It is therefore safe to apply changes to this
 *      ontology while iterating over this set.
 *  @see #AOwlOntology_GetClassesInSignature()
 *  @see #AOwlOntology_GetObjectPropertiesInSignature()
 *  @see #AOwlOntology_GetDataPropertiesInSignature()
 *  @see #AOwlOntology_GetIndividualsInSignature()
 */
AOwlEntitySet
func AOwlOntology_GetSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

/** Gets the classes that are in the signature of this ontology.
 *  @return A set of named classes, which are referenced by any axiom in this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlClassSet
func AOwlOntology_GetClassesInSignature(AOwlOntology Ontology);

/** Gets the classes that are in the signature of this ontology, and possibly the imports closure
 *  of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether classes should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code> then
 *      the set of classes returned will correspond to the union of the classes in the signatures
 *      of the ontologies in the imports closure of this ontology. If <code>false</code>
 *      then the set of classes returned will correspond to the classes that are in the signature
 *      of this just this ontology.
 *  @return A set of classes that are in the signature of this ontology and possibly the union of
 *      the signatures of the ontologies in the imports closure of this ontology. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore safe
 *      to apply changes to this ontology while iterating over this set.
 */
AOwlClassSet
func AOwlOntology_GetClassesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

/** Gets the object properties that are in the signature of this ontology.
 *  @return A set of object properties which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature(AOwlOntology Ontology);

/** Gets the object properties that are in the signature of this ontology, and possibly the
 *  imports closure of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether object properties should be drawn from the
 *      signature of just this ontology or the imports closure of this ontology. If
 *      <code>true</code> then the set of object properties returned will correspond to the union
 *      of the object properties in the signatures of the ontologies in the imports closure of
 *      this ontology. If <code>false</code> then the set of object properties returned will
 *      correspond to the object properties that are in the signature of this just this ontology.
 *  @return A set of object properties that are in the signature of this ontology and possibly
 *      the union of the signatures of the ontologies in the imports closure of this ontology.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlObjectPropertySet
func AOwlOntology_GetObjectPropertiesInSignature2(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure);

/** Gets the data properties that are in the signature of this ontology.
 *  @return A set of data properties, which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature3(AOwlOntology Ontology);

/** Gets the data properties that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *
 *  @param IncludeImportsClosure - Specifies whether data properties should be drawn from the
 *      signature of just this ontology or the imports closure of this ontology. If
 *      <code>true</code> then the set of data properties returned will correspond to the union
 *      of the data properties in the signatures of the ontologies in the imports closure of this
 *      ontology. If <code>false</code> then the set of data properties returned will correspond
 *      to the data properties that are in the signature of this just this ontology.
 *  @return A set of data properties that are in the signature of this ontology and possibly the
 *      union of the signatures of the ontologies in the imports closure of this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertySet
func AOwlOntology_GetDataPropertiesInSignature4(AOwlOntology Ontology,
	ABoolean IncludeImportsClosure);

/** Gets the individuals that are in the signature of this ontology.
 *  @return A set of individuals, which are in the signature of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature(AOwlOntology Ontology);

/** Gets the individuals that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *  @param IncludeImportsClosure Specifies whether individuals should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code>
 *      then the set of individuals returned will correspond to the union of the individuals
 *      in the signatures of the ontologies in the imports closure of this ontology.
 *      If <code>false</code> then the set of individuals returned will correspond to the
 *      individuals that are in the signature of this just this ontology.
 *  @return A set of individuals that are in the signature of this ontology and possibly the
 *      union of the signatures of the ontologies in the imports closure of this ontology.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlNamedIndividualSet
func AOwlOntology_GetIndividualsInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

/** Gets the referenced anonymous individuals
 *  @return The set of referenced anonymous individuals
 */
AOwlAnonymousIndividualSet
func AOwlOntology_GetReferencedAnonymousIndividuals(AOwlOntology Ontology);

/** Gets the datatypes that are in the signature of this ontology.
 *  @return A set of datatypes, which are in the signature of this ontology. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature(AOwlOntology Ontology);

/** Gets the datatypes that are in the signature of this ontology, and possibly the imports
 *  closure of this ontology.
 *  @param IncludeImportsClosure - Specifies whether datatypes should be drawn from the signature
 *      of just this ontology or the imports closure of this ontology. If <code>true</code> then
 *      the set of datatypes returned will correspond to the union of the datatypes in the
 *      signatures of the ontologies in the imports closure of this ontology. If <code>false</code>
 *      then the set of datatypes returned will correspond to the datatypes that are in the
 *      signature of this just this ontology.
 *  @return A set of datatypes that are in the signature of this ontology and possibly the union
 *      of the signatures of the ontologies in the imports closure of this ontology. The set that
 *      is returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlDatatypeSet
func AOwlOntology_GetDatatypesInSignature2(AOwlOntology Ontology, ABoolean IncludeImportsClosure);

/** Gets the annotation properties that are in the signature of this ontology.
 *  @return A set of annotation properties, which are in the signature of this ontology. The set
 *      that is returned is a copy - it will not be updated if the ontology changes. It is
 *      therefore safe to apply changes to this ontology while iterating over this set.
 *  @see #AOwlOntology_GetSignature()
 */
AOwlAnnotationPropertySet
func AOwlOntology_GetAnnotationPropertiesInSignature(AOwlOntology Ontology);

/** Gets the axioms where the specified entity appears in the signature of the axiom. The set
 *  that is returned, contains all axioms that directly reference the specified entity.
 *
 *  @param OwlEntity - The entity that should be directly referred to by an axiom that appears
 *      in the results set.
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms(AOwlOntology Ontology, AOwlEntity OwlEntity);

/** Gets the axioms where the specified entity appears in the signature of the axiom. The set
 *  that is returned, contains all axioms that directly reference the specified entity.
 *
 *  @param OwlEntity - The entity that should be directly referred to by an axiom that appears
 *      in the results set.
 *  @param IncludeImportsClosure - Specifies if the axioms returned should just be from this
 *      ontology, or from the imports closure of this ontology. If <code>true</code> the axioms
 *      returned will be from the imports closure of this ontology, if <code>false</code>
 *      the axioms returned will just be from this ontology.
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure);

AOwlAxiomSet
func AOwlOntology_GetReferencingAxioms3(AOwlOntology Ontology, AOwlAnonymousIndividual Individual);

/** Determines if the signature of the ontology contains the specified entity.
 *
 *  @param OwlEntity - The entity
 *  @return <code>true</code> if the signature of this ontology contains <code>owlEntity</code>,
 *      otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature(AOwlOntology Ontology, AOwlEntity OwlEntity);

/** Determines if the signature of this ontology, and possibly the signature of any of the
 *  ontologies in the imports closure of this ontology, contains the specified entity.
 *
 *  @param OwlEntity - The entity
 *  @param IncludeImportsClosure - Specifies whether the imports closure should be examined for
 *      the entity reference or not.
 *  @return <code>true</code> if the ontology contains a reference to the specified entity,
 *      otherwise <code>false</code> The set that is returned is a copy - it will not be
 *      updated if the ontology changes. It is therefore safe to apply changes to this ontology
 *      while iterating over this set.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure);

/** Determines if the signature of this ontology contains a class, object property, data property,
 *  named individual, annotation property or datatype with the specified IRI.
 *
 *  @param EntityIRI - The IRI to test for.
 *  @return <code>true</code> if the signature of this ontology contains a class, object property,
 *      data property, named individual, annotation property or datatype with the specified IRI.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature3(AOwlOntology Ontology, AOwlIri EntityIri);

/** Determines if the signature of this ontology and possibly its imports closure contains a class,
 *  object property, data property, named individual, annotation property or datatype with the
 *  specified IRI.
 *
 *  @param EntityIRI - The IRI to test for.
 *  @param IncludeImportsClosure - Specifies whether the imports closure of this ontology should
 *      be examined or not.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if the
 *      signature of this ontology or the signature of an ontology in the imports closure of this
 *      ontology contains a class, object property, data property, named individual, annotation
 *      property or datatype with the specified IRI. If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains a class, object
 *      property, data property, named individual, annotation property or datatype with the
 *      specified IRI.
 */
ABoolean
func AOwlOntology_ContainsEntityInSignature4(AOwlOntology Ontology, AOwlIri EntityIri,
	ABoolean IncludeImportsClosure);

/** Determines if this ontology declares an entity i.e. it contains a declaration axiom for the
 *  specified entity.
 *
 * @param OwlEntity - The entity to be tested for
 * @return <code>true</code> if the ontology contains a declaration for the specified entity,
 *     otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_IsDeclared(AOwlOntology Ontology, AOwlEntity OwlEntity);

/** Determines if this ontology or its imports closure declares an entity i.e.
 *  contains a declaration axiom for the specified entity.
 *
 *  @param OwlEntity - The entity to be tested for
 *  @param IncludeImportsClosure - <code>true</code> if the imports closure of this ontology
 *      should be examined, <code>false</code> if just this ontology should be examined.
 *  @return <code>true</code> if the ontology or its imports closure contains a declaration for
 *      the specified entity, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_IsDeclared2(AOwlOntology Ontology, AOwlEntity OwlEntity,
	ABoolean IncludeImportsClosure);

// --- Access by IRI ---

/** Determines if the signature of this ontology contains an OWLClass with the specified IRI.
 *
 *  @param OwlClassIRI - The IRI of the OWLClass to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLClass that has
 *      <code>owlClassIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsClassInSignature(AOwlOntology Ontology, AOwlIri OwlClassIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the ontologies
 *  in the imports closure of this ontology, contains an OWLClass that has the specified IRI.
 *
 *  @param OwlClassIRI - The IRI of the class to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an OWLClass with <code>owlClassIRI</code> as its IRI in the signature of at least one
 *      ontology in the imports clousre of this ontology and <code>false</code> if this is not
 *      the case. If <code>includeImportsClosure=false</code> then returns <code>true</code>
 *      if the signature of this ontology contains an OWLClass that has <code>owlClassIRI</code>
 *      as its IRI and <code>false</code> if the signature of this ontology does not contain
 *      a class with <code>owlClassIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsClassInSignature2(AOwlOntology Ontology, AOwlIri OwlClassIri,
	ABoolean IncludeImportsClosure);

/** Determines if the signature of this ontology contains an OWLObjectProperty with the specified IRI.
 *
 *  @param OwlObjectPropertyIri - The IRI of the OWLObjectProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLObjectProperty
 *      that has <code>owlObjectPropertyIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLObjectProperty that
 *  has the specified IRI.
 *
 *  @param OwlObjectPropertyIri - The IRI of the OWLObjectProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlObjectProperty with <code>owlObjectPropertyIRI</code> as its IRI in the
 *      signature of at least one ontology in the imports clousre of this ontology
 *      and <code>false</code> if this is not the case.  If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlObjectProperty that has <code>owlObjectPropertyIRI</code> as its IRI and
 *      <code>false</code> if the signature of this ontology does not contain a class
 *      with <code>owlObjectPropertyIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsObjectPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlObjectPropertyIri, ABoolean IncludeImportsClosure);

/** Determines if the signature of this ontology contains an OWLDataProperty with the specified IRI.
 *
 *  @param OwlDataPropertyIri - The IRI of the OWLDataProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLDataProperty that
 *      has <code>owlDataPropertyIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsDataPropertyInSignature3(AOwlOntology Ontology,
	AOwlIri OwlDataPropertyIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLDataProperty that has
 *  the specified IRI.
 *
 *  @param OwlDataPropertyIri - The IRI of the OWLDataProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an OWLDataProperty with <code>owlDataPropertyIRI</code> as its IRI in the signature
 *      of at least one ontology in the imports clousre of this ontology and <code>false</code>
 *      if this is not the case. If <code>includeImportsClosure=false</code> then returns
 *      <code>true</code> if the signature of this ontology contains an AOwlDataProperty that
 *      has <code>owlDataPropertyIRI</code> as its IRI and <code>false</code> if the signature
 *      of this ontology does not contain a class with <code>owlDataPropertyIRI</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsDataPropertyInSignature4(AOwlOntology Ontology,
	AOwlIri OwlDataPropertyIri, ABoolean includeImportsClosure);

/** Determines if the signature of this ontology contains an AOwlAnnotationProperty
 *  with the specified IRI.
 *
 *  @param OwlAnnotationPropertyIri - The IRI of the AOwlAnnotationProperty to check for.
 *  @return <code>true</code> if the signature of this ontology contains an
 *      AOwlAnnotationProperty that has <code>owlAnnotationPropertyIRI</code> as its IRI,
 *      otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLAnnotationProperty
 *  that has the specified IRI.
 *
 *  @param OwlAnnotationPropertyIri - The IRI of the OWLAnnotationProperty to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlAnnotationProperty with <code>owlAnnotationPropertyIRI</code> as its IRI in the
 *      signature of at least one ontology in the imports clousre of this ontology
 *      and <code>false</code> if this is not the case.  If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlAnnotationProperty that has <code>OwlAnnotationPropertyIRI</code> as its IRI
 *      and <code>false</code> if the signature of this ontology does not contain a class
 *      with <code>OwlAnnotationPropertyIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsAnnotationPropertyInSignature2(AOwlOntology Ontology,
	AOwlIri OwlAnnotationPropertyIri, ABoolean IncludeImportsClosure);

/** Determines if the signature of this ontology contains an OWLNamedIndividual with the
 *  specified IRI.
 *
 *  @param OwlIndividualIri - The IRI of the OWLNamedIndividual to check for.
 *  @return <code>true</code> if the signature of this ontology contains an AOwlNamedIndividual
 *      that has <code>owlIndividualIRI</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsIndividualInSignature(AOwlOntology Ontology, AOwlIri OwlIndividualIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an AOwlNamedIndividual
 *  that has the specified IRI.
 *
 *  @param OwlIndividualIri - The IRI of the OWLNamedIndividual to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlNamedIndividual with <code>OwlIndividualIri</code> as its IRI in the
 *      signature of at least one ontology in the imports closure of this ontology
 *      and <code>false</code> if this is not the case. If <code>includeImportsClosure=false</code>
 *      then returns <code>true</code> if the signature of this ontology contains an
 *      AOwlNamedIndividual that has <code>OwlIndividualIri</code> as its IRI and <code>false</code>
 *      if the signature of this ontology does not contain a class with
 *      <code>OwlIndividualIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsIndividualInSignature2(AOwlOntology Ontology, AOwlIri OwlIndividualIri,
	ABoolean IncludeImportsClosure);

/** Determines if the signature of this ontology contains an OWLDatatype with the specified IRI.
 *
 *  @param OwlDatatypeIri - The IRI of the OWLDatatype to check for.
 *  @return <code>true</code> if the signature of this ontology contains an OWLDatatype that
 *      has <code>OwlDatatypeIri</code> as its IRI, otherwise <code>false</code>.
 */
ABoolean
func AOwlOntology_ContainsDatatypeInSignature(AOwlOntology Ontology, AOwlIri OwlDatatypeIri);

/** Determines if the signature of this ontology, or possibly the signature of one of the
 *  ontologies in the imports closure of this ontology, contains an OWLDatatype that has the
 *  specified IRI.
 *
 *  @param OwlDatatypeIri - The IRI of the OWLDatatype to check for
 *  @param IncludeImportsClosure - <code>true</code> if the signature of the ontologies in the
 *      imports closure of this ontology should be checked, <code>false</code> if just the
 *      signature of this ontology should be chekced.
 *  @return If <code>includeImportsClosure=true</code> then returns <code>true</code> if there
 *      is an AOwlDatatype with <code>OwlDatatypeIri</code> as its IRI in the signature of at
 *      least one ontology in the imports closure of this ontology and <code>false</code> if
 *      this is not the case. If <code>includeImportsClosure=false</code> then returns
 *      <code>true</code> if the signature of this ontology contains an AOwlDatatype that
 *      has <code>OwlDatatypeIri</code> as its IRI and <code>false</code> if the signature
 *      of this ontology does not contain a class with <code>OwlDatatypeIri</code> as its IRI.
 */
ABoolean
func AOwlOntology_ContainsDatatypeInSignature2(AOwlOntology Ontology, AOwlIri OwlDatatypeIri,
	ABoolean IncludeImportsClosure);

/** Gets the entities in the signature of this ontology that have the specified IRI.
 *
 *  @param Iri - The IRI of the entities to be retrieved.
 *  @return A set of entities that are in the signature of this ontology that have the specified
 *      IRI. The set will be empty if there are no entities in the signature of this ontology
 *      with the specified IRI.
 */
AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature(AOwlOntology Ontology, AOwlIri Iri);

/** Gets the entities in the signature of this ontology, and possibly the signature of the imports
 *  closure of this ontology, that have the specified IRI.
 *
 *  @param Iri - The IRI of the entitied to be retrieved.
 *  @param IncludeImportsClosure - Specifies if the signatures of the ontologies in the imports
 *      closure of this ontology should also be taken into account
 *  @return If <code>includeImportsClosure=true</code> then returns a set of entities that are
 *      in the signature of this ontology or the signature of an ontology in the imports closure
 *      of this ontology that have <code>iri</code> as their IRI. If
 *      <code>includeImportsClosure=false</code> then returns the entities in the signature
 *      of just this ontology that have <code>iri</code> as their IRI.
 */
AOwlEntitySet
func AOwlOntology_GetEntitiesInSignature2(AOwlOntology Ontology, AOwlIri Iri,
	ABoolean IncludeImportsClosure);

// --- Axioms that form part of a description of a named entity ---

/** Gets the axioms that form the definition/description of a class.
 *
 *  @param Cls - The class whose describing axioms are to be retrieved.
 *  @return A set of class axioms that describe the class. This set includes
 *      <ul>
 *        <li>Subclass axioms where the subclass is equal to the specified class</li>
 *        <li>Equivalent class axioms where the specified class is an operand in the
 *            equivalent class axiom</li>
 *        <li>Disjoint class axioms where the specified class is an operand in the
 *            disjoint class axiom</li>
 *        <li>Disjoint union axioms, where the specified class is the named class that
 *            is equivalent to the disjoint union</li>
 *      </ul>
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlClassAxiomSet
func AOwlOntology_GetAxioms_Class(AOwlOntology Ontology, AOwlClass Cls);

/** Gets the axioms that form the definition/description of an object property.
 *
 *  @param Prop - The property whose defining axioms are to be retrieved.
 *  @return A set of object property axioms that includes
 *      <ul>
 *        <li>Sub-property axioms where the sub property is equal to the specified property</li>
 *        <li>Equivalent property axioms where the axiom contains the specified property</li>
 *        <li>Equivalent property axioms that contain the inverse of the specified property</li>
 *        <li>Disjoint property axioms that contain the specified property</li>
 *        <li>Domain axioms that specify a domain of the specified property</li>
 *        <li>Range axioms that specify a range of the specified property</li>
 *        <li>Any property characteristic axiom (i.e. Functional, Symmetric, Reflexive
 *            etc.) whose subject is the specified property</li>
 *        <li>Inverse properties axioms that contain the specified property</li>
 *      </ul>
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlObjectPropertyAxiomSet
func AOwlOntology_GetAxioms_ObjPropExpr(AOwlOntology Ontology, AOwlObjectPropertyExpression Prop);

/** Gets the axioms that form the definition/description of a data property.
 *
 *  @param Prop - The property whose defining axioms are to be retrieved.
 *  @return A set of data property axioms that includes
 *      <ul>
 *        <li>Sub-property axioms where the sub property is equal
 *            to the specified property</li>
 *        <li>Equivalent property axioms where the axiom contains the specified property</li>
 *        <li>Disjoint property axioms that contain the specified property</li>
 *        <li>Domain axioms that specify a domain of the specified property</li>
 *        <li>Range axioms that specify a range of the specified property</li>
 *        <li>Any property characteristic axiom (i.e. Functional, Symmetric, Reflexive
 *            etc.) whose subject is the specified property</li>
 *      </ul>
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertyAxiomSet
func AOwlOntology_GetAxioms_DataProp(AOwlOntology Ontology, AOwlDataProperty Prop);

/** Gets the axioms that form the definition/description of an individual
 *
 *  @param Individual - The individual whose defining axioms are to be retrieved.
 *  @return A set of individual axioms that includes
 *      <ul>
 *        <li>Individual type assertions that assert the type of the specified individual</li>
 *        <li>Same individuals axioms that contain the specified individual</li>
 *        <li>Different individuals axioms that contain the specified individual</li>
 *        <li>Object property assertion axioms whose subject is the specified individual</li>
 *        <li>Data property assertion axioms whose subject is the specified individual</li>
 *        <li>Negative object property assertion axioms whose subject is the
 *            specified individual</li>
 *        <li>Negative data property assertion axioms whose subject is the specified individual</li>
 *      </ul>
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 */
AOwlIndividualAxiomSet
func AOwnOntology_GetAxioms_Individ(AOwlOntology Ontology, AOwlIndividual Individual);

/** Gets the axioms that form the definition/description of an annotation property.
 *
 *  @param Property - The property whose definition axioms are to be retrieved
 *  @return A set of axioms that includes
 *      <ul>
 *        <li>Annotation subpropertyOf axioms where the specified property is the sub property</li>
 *        <li>Annotation property domain axioms that specify a domain for the specified property</li>
 *        <li>Annotation property range axioms that specify a range for the specified property</li>
 *      </ul>
 */
AOwlAnnotationAxiomSet
func AOwlOntology_GetAxioms_AnnotationProp(AOwlOntology Ontology, AOwlAnnotationProperty Property);

/** Gets the datatype definition axioms for the specified datatype
 *
 *  @param Datatype - The datatype
 *  @return The set of datatype definition axioms for the specified datatype
 */
AOwlDatatypeDefinitionAxiomSet
func AOwlOntology_GetAxioms_Datatype(AOwlOntology Ontology, AOwlDatatype Datatype);

// --- Annotation axioms  ---

/** Gets the <code>SubAnnotationPropertyOfAxiom</code>s where the specified property is
 *  the sub-property.
 *
 *  @param SubProperty - The sub-property of the axioms to be retrieved.
 *  @return A set of <code>AOwlSubAnnotationPropertyOfAxiom</code>s such that the
 *  sub-property is equal to <code>subProperty</code>.
 */
AOwlSubAnnotationPropertyOfAxiomSet
func AOwlOntology_GetSubAnnotationPropertyOfAxioms(AOwlAnnotationProperty SubProperty);

/** Gets the <code>OWLAnnotationPropertyDomainAxiom</code>s where the specified property
 *  is the property in the domain axiom.
 *
 *  @param Property - The property that the axiom specifies a domain for.
 *  @return A set of <code>AOwlAnnotationPropertyDomainAxiom</code>s such that the property
 *      is equal to <code>property</code>.
 */
AOwlAnnotationPropertyDomainAxiomSet
func AOwlOntology_GetAnnotationPropertyDomainAxioms(AOwlAnnotationProperty Property);

/** Gets the <code>AOwlAnnotationPropertyRangeAxiom</code>s where the specified property
 *  is the property in the range axiom.
 *
 *  @param Property - The property that the axiom specifies a range for.
 *  @return A set of <code>AOwlAnnotationPropertyRangeAxiom</code>s such that the property
 *      is equal to <code>property</code>.
 */
AOwlAnnotationPropertyRangeAxiomSet
func AOwlOntology_GetAnnotationPropertyRangeAxioms(AOwlAnnotationProperty Property);

//////////////////////////////////////////////////////////////////////////////////////////////
//
// Various methods that provide axioms relating to specific entities that allow
// frame style views to be composed for a particular entity.  Such functionality is
// useful for ontology editors and browsers.
//
//////////////////////////////////////////////////////////////////////////////////////////////

/** Gets the declaration axioms for specified entity.
 *
 *  @param Subject - The entity that is the subject of the set of returned axioms.
 *  @return The set of declaration axioms. Note that this set will be a copy and will not be
 *      updated if the ontology changes. It is therefore safe to iterate over this set while
 *      making changes to the ontology.
 */
AOwlDeclarationAxiomSet
func AOwlOntology_GetDeclarationAxioms(AOwlEntity Subject);

/** Gets the axioms that annotate the specified entity.
 *
 *  @param Entity - The entity whose annotations are to be retrieved.
 *  @return The set of entity annotation axioms. Note that this set will be a copy and will
 *      not be updated if the ontology changes. It is therefore safe to iterate over this set
 *      while making changes to the ontology.
 */
AOwlAnnotationAssertionAxiomSet
func AOwlOntology_GetAnnotationAssertionAxioms(AOwlAnnotationSubject Entity);

// --- Classes ---

/** Gets all of the subclass axioms where the left hand side (the subclass) is equal to the specified class.
 *
 *  @param Cls - The class that is equal to the left hand side of the axiom (subclass).
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSubClass(AOwlClass Cls);

/** Gets all of the subclass axioms where the right hand side (the superclass) is equal to
 *  the specified class.
 *
 *  @param Cls - The class
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSuperClass(AOwlClass Cls);

/** Gets all of the equivalent axioms in this ontology that contain the specified class
 *  as an operand.
 *
 *  @param Cls - The class
 *  @return A set of equivalent class axioms that contain the specified class as an operand.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlEquivalentClassesAxiomSet
func AOwlOntology_GetEquivalentClassesAxioms(AOwlClass Cls);

/** Gets the set of disjoint class axioms that contain the specified class as an operand.
 *
 *  @param Cls - The class that should be contained in the set of disjoint class axioms
 *      that will be returned.
 *  @return The set of disjoint axioms that contain the specified class. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 */
AOwlDisjointClassesAxiomSet
func AOwlOntology_GetDisjointClassesAxioms(AOwlClass Cls);

/** Gets the set of disjoint union axioms that have the specified class as the named class
 *  that is equivalent to the disjoint union of operands. For example, if the ontology
 *  contained the axiom DisjointUnion(A, propP some C, D, E) this axiom would be returned
 *  for class A (but not for D or E).
 *
 *  @param OwlClass - The class that indexes the axioms to be retrieved.
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDisjointUnionAxiomSet
func AOwlOntology_GetDisjointUnionAxioms(AOwlClass OwlClass);

/** Gets the has key axioms that have the specified class as their subject.
 *
 *  @param Cls - The subject of the has key axioms
 *  @return The set of has key axioms that have cls as their subject. The set that is returned
 *      is a copy - it will not be updated if the ontology changes. It is therefore safe to
 *      apply changes to this ontology while iterating over this set.
 */
AOwlHasKeyAxiomSet
func AOwlOntology_GetHasKeyAxioms(AOwlClass Cls);

// --- Object properties ---

/** Gets the AOwlSubObjectPropertyOfAxiom's where the sub-property is equal to the
 *  specified property.
 *
 *  @param SubProperty - The property which is equal to the sub property of the retrived axioms.
 *  @return A set of AOwlSubObjectPropertyOfAxiom's such that each axiom in the set is of the form
 *      <code>SubObjectPropertyOf(subProperty, pe)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubObjectPropertyOfAxiomSet
func AOwlOntology_GetObjectSubPropertyAxiomsForSubProperty(AOwlObjectPropertyExpression SubProperty);

/** Gets the AOwlSubObjectPropertyOfAxiom's where the super-property (returned by
 *  AOwlSubObjectPropertyOfAxiom_GetSuperProperty()) is equal to the specified property.
 *
 *  @param SuperProperty - The property which is equal to the super-property of the retrived axioms.
 *  @return A set of AOwlSubObjectPropertyOfAxiom's such that each axiom in the set is of the form
 *      <code>SubObjectPropertyOf(pe, superProperty)</code>. The set that is returned is a
 *      copy - it will not be updated if the ontology changes. It is therefore safe to apply
 *      changes to this ontology while iterating over this set.
 */
AOwlSubObjectPropertyOfAxiomSet
func AOwlOntology_GetObjectSubPropertyAxiomsForSuperProperty(
	AOwlObjectPropertyExpression SuperProperty);

/** Gets the AOwlObjectPropertyDomainAxiom's where the property (returned by
 *  AOwlObjectPropertyRangeAxiom_GetProperty()) is equal to the specified property.
 *
 *  @param Property - The property which is equal to the property of the retrived axioms.
 *  @return A set of AOwlObjectPropertyDomainAxiom's such that each axiom in the set is of
 *      the form <code>ObjectPropertyDomain(pe, ce)</code>. The set that is returned is a
 *      copy - it will not be updated if the ontology changes. It is therefore safe to apply
 *      changes to this ontology while iterating over this set.
 */
AOwlObjectPropertyDomainAxiomSet
func AOwlOntology_GetObjectPropertyDomainAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlObjectPropertyRangeAxiom's where the property (returned by
 *  AOwlObjectPropertyRangeAxiom_GetProperty()) is equal to the specified property.
 *
 *  @param Property - The property which is equal to the property of the retieved axioms.
 *  @return A set of AOwlObjectPropertyRangeAxiom's such that each axiom in the set is of
 *      the form <code>ObjectPropertyRange(property, ce)</code>. The set that is returned is a
 *      copy - it will not be updated if the ontology changes. It is therefore safe to apply
 *      changes to this ontology while iterating over this set.
 */
AOwlObjectPropertyRangeAxiomSet
func AOwlOntology_GetObjectPropertyRangeAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlInverseObjectPropertiesAxiom's where the specified property is contained in the
 *  set returned by #AOwlInverseObjectPropertiesAxiom_GetProperties().
 *
 *  @param Property - The property which is equal to the property of the retrieved axioms.
 *  @return A set of AOwlInverseObjectPropertiesAxiom's such that each axiom in the set is of
 *      the form <code>InverseObjectProperties(property, pe)</code> or
 *      <code>InverseObjectProperties(pe, property)</code>. The set that is returned is a
 *      copy - it will not be updated if the ontology changes.  It is therefore safe to
 *      apply changes to this ontology while iterating over this set.
 */
AOwlInverseObjectPropertiesAxiomSet
func AOwlOntology_GetInverseObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlEquivalentObjectPropertiesAxiom's that make the specified property equivalent
 *  to some other object property expression(s).
 *
 *  @param Property - The property that the retrieved axioms make equivalent to some other
 *      property expressions. For each axiom retrieved the set of properties returned by
 *      #AOwlEquivalentObjectPropertiesAxiom_GetProperties() will contain property.
 *  @return A set of AOwlEquivalentObjectPropertiesAxiom's such that each axiom in the set
 *      is of the form <code>EquivalentObjectProperties(pe0, ..., property, ..., pen)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlEquivalentObjectPropertiesAxiomSet
func AOwlOntology_GetEquivalentObjectPropertiesAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlDisjointObjectPropertiesAxiom's that make the specified property disjoint with
 *  some other object property expression(s).
 *
 *  @param Property - The property that the retrieved axioms makes disjoint to some other
 *      property expressions. For each axiom retrieved the set of properties returned by
 *      AOwlDisjointObjectPropertiesAxiom_GetProperties() will contain property.
 *  @return A set of AOwlDisjointObjectPropertiesAxiom's such that each axiom in the set
 *      is of the form <code>DisjointObjectProperties(pe0, ..., property, ..., pen)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDisjointObjectPropertiesAxiomSet
func AOwlOntology_GetDisjointObjectPropertiesAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlFunctionalObjectPropertyAxiom's contained in this ontology that make the
 *  specified object property functional.
 *
 *  @param Property - The property (returned by AOwlFunctionalObjectPropertyAxiom_GetProperty())
 *      that is made functional by the axioms.
 *  @return A set of AOwlFunctionalObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>FunctionalObjectProperty(property)</code>.
 */
AOwlFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlInverseFunctionalObjectPropertyAxiom's contained in this ontology that
 *  make the specified object property inverse functional.
 *
 *  @param Property - The property (returned by AOwlInverseFunctionalObjectPropertyAxiom_GetProperty())
 *      that is made inverse functional by the axioms.
 *  @return A set of AOwlFunctionalObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>InverseFunctionalObjectProperty(property)</code>.
 */
AOwlInverseFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetInverseFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlSymmetricObjectPropertyAxiom's contained in this ontology that make the
 *  specified object property symmetric.
 *
 *  @param Property - The property (returned by AOwlSymmetricObjectPropertyAxiom_GetProperty())
 *      that is made symmetric by the axioms.
 *  @return A set of AOwlSymmetricObjectPropertyAxiom's such that each axiom in the set is
 *      of the form <code>SymmetricObjectProperty(property)</code>.
 */
AOwlSymmetricObjectPropertyAxiomSet
func AOwlOntology_GetSymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlAsymmetricObjectPropertyAxiom's contained in this ontology that
 *  make the specified object property asymmetric.
 *
 *  @param Property - The property (returned by AOwlAsymmetricObjectPropertyAxiom_GetProperty())
 *      that is made asymmetric by the axioms.
 *  @return A set of AOwlAsymmetricObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>AsymmetricObjectProperty(property)</code>.
 */
AOwlAsymmetricObjectPropertyAxiomSet
func AOwlOntology_GetAsymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlReflexiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property reflexive.
 *
 *  @param Property - The property (returned by AOwlReflexiveObjectPropertyAxiom_GetProperty())
 *      that is made reflexive by the axioms.
 *  @return A set of AOwlReflexiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>ReflexiveObjectProperty(property)</code>.
 */
AOwlReflexiveObjectPropertyAxiomSet
func AOwlOntology_GetReflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlIrreflexiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property irreflexive.
 *  @param Property - The property (returned by AOwlIrreflexiveObjectPropertyAxiom_GetProperty())
 *      that is made irreflexive by the axioms.
 *  @return A set of AOwlIrreflexiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>IrreflexiveObjectProperty(property)</code>.
 */
AOwlIrreflexiveObjectPropertyAxiomSet
func AOwlOntology_GetIrreflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

/** Gets the AOwlTransitiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property transitive.
 *
 *  @param property The property (returned by AOwlTransitiveObjectPropertyAxiom_GetProperty())
 *      that is made transitive by the axioms.
 *  @return A set of AOwlTransitiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>TransitiveObjectProperty(property)</code>.
 */
AOwlTransitiveObjectPropertyAxiomSet
func AOwlOntology_GetTransitiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property);

// --- Data properties ---

/** Gets the AOwlSubDataPropertyOfAxiom's where the sub-property is equal to the specified property.
 *
 *  @param SubProperty - The property which is equal to the sub property of the retrived axioms.
 *  @return A set of AOwlSubDataPropertyOfAxiom's such that each axiom in the set is of the form
 *      <code>SubDataPropertyOf(subProperty, pe)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubDataPropertyOfAxiomSet
func AOwlOntology_GetDataSubPropertyAxiomsForSubProperty(AOwlDataProperty SubProperty);

/** Gets the AOwlSubDataPropertyOfAxiom's where the super-property (returned by
 *  AOwlSubDataPropertyOfAxiom_GetSuperProperty()) is equal to the specified property.
 *
 *  @param SuperProperty - The property which is equal to the super-property of the retrived axioms.
 *  @return A set of AOwlSubDataPropertyOfAxiom's such that each axiom in the set is of the form
 *      <code>SubDataPropertyOf(pe, superProperty)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubDataPropertyOfAxiomSet
func AOwlOntology_GetDataSubPropertyAxiomsForSuperProperty(AOwlDataPropertyExpression SuperProperty);

/** Gets the AOwlDataPropertyDomainAxiom's where the property (returned by
 *  AOwlDataPropertyRangeAxiom_GetProperty()) is equal to the specified property.
 *
 *  @param Property - The property which is equal to the property of the retrived axioms.
 *  @return A set of AOwlDataPropertyDomainAxiom's such that each axiom in the set is of the
 *      form <code>DataPropertyDomain(pe, ce)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertyDomainAxiomSet
func AOwlOntology_GetDataPropertyDomainAxioms(AOwlDataProperty Property);

/** Gets the AOwlDataPropertyRangeAxiom's where the property (returned by
 *  AOwlDataPropertyRangeAxiom_GetProperty()) is equal to the specified property.
 *
 *  @param Property - The property which is equal to the property of the retieved axioms.
 *  @return A set of AOwlDataPropertyRangeAxiom's such that each axiom in the set is of the
 *      form <code>DataPropertyRange(property, ce)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertyRangeAxiomSet
func AOwlOntology_GetDataPropertyRangeAxioms(AOwlDataProperty Property);

/** Gets the AOwlEquivalentDataPropertiesAxiom's that make the specified property
 *  equivalent to some other data property expression(s).
 *
 *  @param Property - The property that the retrieved axioms make equivalent to some other
 *      property expressions. For each axiom retrieved the set of properties returned by
 *      AOwlEquivalentDataPropertiesAxiom_getProperties() will contain property.
 *  @return A set of AOwlEquivalentDataPropertiesAxiom's such that each axiom in the set is of
 *      the form <code>EquivalentDataProperties(pe0, ..., property, ..., pen)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlEquivalentDataPropertiesAxiomSet
func AOwlOntology_GetEquivalentDataPropertiesAxioms(AOwlDataProperty Property);

/** Gets the AOwlDisjointDataPropertiesAxiom's that make the specified property
 *  disjoint with some other data property expression(s).
 *
 *  @param Property - The property that the retrieved axioms makes disjoint to some other property
 *      expressions. For each axiom retrieved the set of properties returned by
 *      AOwlDisjointDataPropertiesAxiom_GetProperties() will contain property.
 *  @return A set of AOwlDisjointDataPropertiesAxiom's such that each axiom in the set is of
 *      the form <code>DisjointDataProperties(pe0, ..., property, ..., pen)</code>. The set that is
 *      returned is a copy - it will not be updated if the ontology changes.  It is therefore safe
 *      to apply changes to this ontology while iterating over this set.
 */
AOwlDisjointDataPropertiesAxiomSet
func AOwlOntology_GetDisjointDataPropertiesAxioms(AOwlDataProperty Property);

/** Gets the AOwlFunctionalDataPropertyAxiom's contained in this ontology that
 *  make the specified data property functional.
 *
 *  @param Property - The property (returned by AOwlFunctionalDataPropertyAxiom_GetProperty())
 *      that is made functional by the axioms.
 *  @return A set of AOwlFunctionalDataPropertyAxiom's such that each axiom in the
 *      set is of the form <code>FunctionalDataProperty(property)</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlFunctionalDataPropertyAxiomSet
func AOwlOntology_GetFunctionalDataPropertyAxioms(AOwlDataPropertyExpression Property);

// --- Individuals ---

/** Gets the #AOwlClassAssertionAxiom's contained in this ontology that
 *  make the specified <code>individual</code> an instance of some class expression.
 *
 *  @param Individual - The individual that the returned axioms make an instance of some
 *      class expression.
 *  @return A set of #AOwlClassAssertionAxiom's such that each axiom in the set is of the form
 *      <code>ClassAssertion(ce, individual)</code> (for each axiom
 *      #AOwlClassAssertionAxiom_getIndividual() is equal to <code>individual</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlClassAssertionAxiomSet
func AOwlOntology_GetClassAssertionAxioms(AOwlIndividual Individual);

/** Gets the #AOwlClassAssertionAxiom's contained in this ontology that make the
 *  specified class expression, <code>ce</code>, a type for some individual.
 *
 *  @param Ce - The class expression that the returned axioms make a type for some individual.
 *  @return A set of #AOwlClassAssertionAxiom's such that each axiom in the set is of the form
 *      <code>ClassAssertion(ce, ind)</code> (for each axiom
 *      #AOwlClassAssertionAxiom_GetClassExpression() is equal to <code>ce</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlClassAssertionAxiomSet
func AOwlOntology_GetClassAssertionAxioms2(AOwlClassExpression Ce);

/** Gets the #AOwlDataPropertyAssertionAxiom's contained in this ontology that
 *  have the specified <code>individual</code> as the subject of the axiom.
 *
 *  @param Individual - The individual that the returned axioms have as a subject.
 *  @return A set of #AOwlDataPropertyAssertionAxiom's such that each axiom in the set is of the
 *      form <code>DataPropertyAssertion(dp, individual, l)</code> (for each axiom
 *      AOwlDataPropertyAssertionAxiom_GetSubject() is equal to <code>individual</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDataPropertyAssertionAxiomSet
func AOwlOntology_GetDataPropertyAssertionAxioms(AOwlIndividual Individual);

/** Gets the #AOwlObjectPropertyAssertionAxiom's contained in this ontology that
 *  have the specified <code>individual</code> as the subject of the axiom.
 *
 *  @param Individual - The individual that the returned axioms have as a subject.
 *  @return A set of AOwlObjectPropertyAssertionAxiom's such that each axiom in the set is of
 *      the form <code>ObjectPropertyAssertion(dp, individual, obj)</code> (for each axiom
 *      #AOwlObjectPropertyAssertionAxiom_GetSubject() is equal to <code>individual</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlObjectPropertyAssertionAxiomSet
func AOwlOntology_GetObjectPropertyAssertionAxioms(AOwlIndividual Individual);

/** Gets the AOwlNegativeObjectPropertyAssertionAxiom's contained in this ontology that
 *  have the specified <code>individual</code> as the subject of the axiom.
 *
 *  @param Individual - The individual that the returned axioms have as a subject.
 *  @return A set of #AOwlNegativeObjectPropertyAssertionAxiom's such that each axiom in
 *      the set is of the form <code>NegativeObjectPropertyAssertion(dp, individual, obj)</code>
 *      (for each axiom AOwlNegativeObjectPropertyAssertionAxiom_GetSubject() is
 *      equal to <code>individual</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlNegativeObjectPropertyAssertionAxiomSet
func AOwlOntology_GetNegativeObjectPropertyAssertionAxioms(AOwlIndividual Individual);

/** Gets the #AOwlNegativeDataPropertyAssertionAxiom's contained in this ontology that
 *  have the specified <code>individual</code> as the subject of the axiom.
 *
 *  @param Individual - The individual that the returned axioms have as a subject.
 *  @return A set of #AOwlNegativeDataPropertyAssertionAxiom's such that each axiom in
 *      the set is of the form <code>NegativeDataPropertyAssertion(dp, individual, obj)</code>
 *      (for each axiom AOwlNegativeDataPropertyAssertionAxiom_GetSubject() is
 *      equal to <code>individual</code>).
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlNegativeDataPropertyAssertionAxiomSet
func AOwlOntology_GetNegativeDataPropertyAssertionAxioms(AOwlIndividual Individual);

/** Gets the #AOwlSameIndividualAxiom's contained in this ontology that make
 *  the specified <code>individual</code> the same as some other individual.
 *
 *  @param Individual - The individual that the returned axioms make the same as some
 *      other individual.
 *  @return A set of #AOwlSameIndividualAxiom's such that each axiom in the set is of the
 *      form <code>SameIndividual(individual, ind, ...)</code> (for each axiom returned
 *  #AOwlSameIndividualAxiom_GetIndividuals() contains <code>individual</code>.
 *  The set that is returned is a copy - it will not be updated if the ontology changes.
 *  It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSameIndividualAxiomSet
func AOwlOntology_GetSameIndividualAxioms(AOwlIndividual Individual);

/** Gets the #AOwlDifferentIndividualsAxiom's contained in this ontology that make
 *  the specified <code>individual</code> different to some other individual.
 *
 *  @param Individual - The individual that the returned axioms make the different as some
 *      other individual.
 *  @return A set of #AOwlDifferentIndividualsAxiom's such that each axiom in the set is of the
 *      form <code>DifferentIndividuals(individual, ind, ...)</code> (for each axiom returned
 *      #AOwlDifferentIndividualsAxiom_GetIndividuals() contains <code>individual</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDifferentIndividualsAxiomSet
func AOwlOntology_GetDifferentIndividualAxioms(AOwlIndividual Individual);

/** Gets the #AOwlDatatypeDefinitionAxiom's contained in this ontology that provide
 *  a definition for the specified datatype.
 *
 *  @param Datatype - The datatype for which the returned axioms provide a definition.
 *  @return A set of AOwlDatatypeDefinitionAxiom's such that for each axiom in the
 *      set AOwlDatatypeDefinitionAxiom_GetDatatype() is equal to <code>datatype</code>.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlDatatypeDefinitionAxiomSet
func AOwlOntology_GetDatatypeDefinitions(AOwlDatatype Datatype);

#endif // AOwlOntology_H
