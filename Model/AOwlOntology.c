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

// --- Functions ---

/** Gets the manager that created this ontology. The manager is used by various methods on
 *  AOwlOntology to resolve imports
 *
 *  @return The manager that created this ontology.
 */
AOwlOntologyManager
func AOwlOntology_GetOwlOntologyManager(AOwlOntology Ontology)
{
	return 0;
}

/** Gets the identity of this ontology (i.e. ontology IRI + version IRI).
 *
 *  @return The ID of this ontology.
 */
AOwlOntologyId
func AOwlOntology_GetOntologyId(AOwlOntology Ontology)
{
	return 0;
}

/** Determines whether or not this ontology is anonymous.  An ontology is anonymous if it does
 *  not have an ontology IRI.
 *
 *  @return <code>true</code> if this ontology is anonymous, otherwise <code>false</code>
 */
ABoolean
func AOwlOntology_IsAnonymous(AOwlOntology Ontology)
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
func AOwlOntology_GetAnnotations(AOwlOntology Ontology)
{
	return 0;
}

// --- Annotation axioms  ---

/** Gets the <code>SubAnnotationPropertyOfAxiom</code>s where the specified property is
 *  the sub-property.
 *
 *  @param SubProperty - The sub-property of the axioms to be retrieved.
 *  @return A set of <code>AOwlSubAnnotationPropertyOfAxiom</code>s such that the
 *  sub-property is equal to <code>subProperty</code>.
 */
AOwlSubAnnotationPropertyOfAxiomSet
func AOwlOntology_GetSubAnnotationPropertyOfAxioms(AOwlAnnotationProperty SubProperty)
{
	return 0;
}

/** Gets the <code>OWLAnnotationPropertyDomainAxiom</code>s where the specified property
 *  is the property in the domain axiom.
 *
 *  @param Property - The property that the axiom specifies a domain for.
 *  @return A set of <code>AOwlAnnotationPropertyDomainAxiom</code>s such that the property
 *      is equal to <code>property</code>.
 */
AOwlAnnotationPropertyDomainAxiomSet
func AOwlOntology_GetAnnotationPropertyDomainAxioms(AOwlAnnotationProperty Property)
{
	return 0;
}

/** Gets the <code>AOwlAnnotationPropertyRangeAxiom</code>s where the specified property
 *  is the property in the range axiom.
 *
 *  @param Property - The property that the axiom specifies a range for.
 *  @return A set of <code>AOwlAnnotationPropertyRangeAxiom</code>s such that the property
 *      is equal to <code>property</code>.
 */
AOwlAnnotationPropertyRangeAxiomSet
func AOwlOntology_GetAnnotationPropertyRangeAxioms(AOwlAnnotationProperty Property)
{
	return 0;
}

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
func AOwlOntology_GetDeclarationAxioms(AOwlEntity Subject)
{
	return 0;
}

/** Gets the axioms that annotate the specified entity.
 *
 *  @param Entity - The entity whose annotations are to be retrieved.
 *  @return The set of entity annotation axioms. Note that this set will be a copy and will
 *      not be updated if the ontology changes. It is therefore safe to iterate over this set
 *      while making changes to the ontology.
 */
AOwlAnnotationAssertionAxiomSet
func AOwlOntology_GetAnnotationAssertionAxioms(AOwlAnnotationSubject Entity)
{
	return 0;
}

// --- Classes ---

/** Gets all of the subclass axioms where the left hand side (the subclass) is equal to the specified class.
 *
 *  @param Cls - The class that is equal to the left hand side of the axiom (subclass).
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSubClass(AOwlClass Cls)
{
	return 0;
}

/** Gets all of the subclass axioms where the right hand side (the superclass) is equal to
 *  the specified class.
 *
 *  @param Cls - The class
 *  @return The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlSubClassOfAxiomSet
func AOwlOntology_GetSubClassAxiomsForSuperClass(AOwlClass Cls)
{
	return 0;
}

/** Gets all of the equivalent axioms in this ontology that contain the specified class
 *  as an operand.
 *
 *  @param Cls - The class
 *  @return A set of equivalent class axioms that contain the specified class as an operand.
 *      The set that is returned is a copy - it will not be updated if the ontology changes.
 *      It is therefore safe to apply changes to this ontology while iterating over this set.
 */
AOwlEquivalentClassesAxiomSet
func AOwlOntology_GetEquivalentClassesAxioms(AOwlClass Cls)
{
	return 0;
}

/** Gets the set of disjoint class axioms that contain the specified class as an operand.
 *
 *  @param Cls - The class that should be contained in the set of disjoint class axioms
 *      that will be returned.
 *  @return The set of disjoint axioms that contain the specified class. The set that is
 *      returned is a copy - it will not be updated if the ontology changes. It is therefore
 *      safe to apply changes to this ontology while iterating over this set.
 */
AOwlDisjointClassesAxiomSet
func AOwlOntology_GetDisjointClassesAxioms(AOwlClass Cls)
{
	return 0;
}

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
func AOwlOntology_GetDisjointUnionAxioms(AOwlClass OwlClass)
{
	return 0;
}

/** Gets the has key axioms that have the specified class as their subject.
 *
 *  @param Cls - The subject of the has key axioms
 *  @return The set of has key axioms that have cls as their subject. The set that is returned
 *      is a copy - it will not be updated if the ontology changes. It is therefore safe to
 *      apply changes to this ontology while iterating over this set.
 */
AOwlHasKeyAxiomSet
func AOwlOntology_GetHasKeyAxioms(AOwlClass Cls)
{
	return 0;
}

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
func AOwlOntology_GetObjectSubPropertyAxiomsForSubProperty(AOwlObjectPropertyExpression SubProperty)
{
	return 0;
}

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
	AOwlObjectPropertyExpression SuperProperty)
{
	return 0;
}

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
func AOwlOntology_GetObjectPropertyDomainAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetObjectPropertyRangeAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetInverseObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetEquivalentObjectPropertiesAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetDisjointObjectPropertiesAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlFunctionalObjectPropertyAxiom's contained in this ontology that make the
 *  specified object property functional.
 *
 *  @param Property - The property (returned by AOwlFunctionalObjectPropertyAxiom_GetProperty())
 *      that is made functional by the axioms.
 *  @return A set of AOwlFunctionalObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>FunctionalObjectProperty(property)</code>.
 */
AOwlFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlInverseFunctionalObjectPropertyAxiom's contained in this ontology that
 *  make the specified object property inverse functional.
 *
 *  @param Property - The property (returned by AOwlInverseFunctionalObjectPropertyAxiom_GetProperty())
 *      that is made inverse functional by the axioms.
 *  @return A set of AOwlFunctionalObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>InverseFunctionalObjectProperty(property)</code>.
 */
AOwlInverseFunctionalObjectPropertyAxiomSet
func AOwlOntology_GetInverseFunctionalObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlSymmetricObjectPropertyAxiom's contained in this ontology that make the
 *  specified object property symmetric.
 *
 *  @param Property - The property (returned by AOwlSymmetricObjectPropertyAxiom_GetProperty())
 *      that is made symmetric by the axioms.
 *  @return A set of AOwlSymmetricObjectPropertyAxiom's such that each axiom in the set is
 *      of the form <code>SymmetricObjectProperty(property)</code>.
 */
AOwlSymmetricObjectPropertyAxiomSet
func AOwlOntology_GetSymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlAsymmetricObjectPropertyAxiom's contained in this ontology that
 *  make the specified object property asymmetric.
 *
 *  @param Property - The property (returned by AOwlAsymmetricObjectPropertyAxiom_GetProperty())
 *      that is made asymmetric by the axioms.
 *  @return A set of AOwlAsymmetricObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>AsymmetricObjectProperty(property)</code>.
 */
AOwlAsymmetricObjectPropertyAxiomSet
func AOwlOntology_GetAsymmetricObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlReflexiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property reflexive.
 *
 *  @param Property - The property (returned by AOwlReflexiveObjectPropertyAxiom_GetProperty())
 *      that is made reflexive by the axioms.
 *  @return A set of AOwlReflexiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>ReflexiveObjectProperty(property)</code>.
 */
AOwlReflexiveObjectPropertyAxiomSet
func AOwlOntology_GetReflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlIrreflexiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property irreflexive.
 *  @param Property - The property (returned by AOwlIrreflexiveObjectPropertyAxiom_GetProperty())
 *      that is made irreflexive by the axioms.
 *  @return A set of AOwlIrreflexiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>IrreflexiveObjectProperty(property)</code>.
 */
AOwlIrreflexiveObjectPropertyAxiomSet
func AOwlOntology_GetIrreflexiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

/** Gets the AOwlTransitiveObjectPropertyAxiom's contained in this ontology that
 *      make the specified object property transitive.
 *
 *  @param property The property (returned by AOwlTransitiveObjectPropertyAxiom_GetProperty())
 *      that is made transitive by the axioms.
 *  @return A set of AOwlTransitiveObjectPropertyAxiom's such that each axiom in the
 *      set is of the form <code>TransitiveObjectProperty(property)</code>.
 */
AOwlTransitiveObjectPropertyAxiomSet
func AOwlOntology_GetTransitiveObjectPropertyAxioms(AOwlObjectPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetDataSubPropertyAxiomsForSubProperty(AOwlDataProperty SubProperty)
{
	return 0;
}

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
func AOwlOntology_GetDataSubPropertyAxiomsForSuperProperty(AOwlDataPropertyExpression SuperProperty)
{
	return 0;
}

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
func AOwlOntology_GetDataPropertyDomainAxioms(AOwlDataProperty Property)
{
	return 0;
}

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
func AOwlOntology_GetDataPropertyRangeAxioms(AOwlDataProperty Property)
{
	return 0;
}

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
func AOwlOntology_GetEquivalentDataPropertiesAxioms(AOwlDataProperty Property)
{
	return 0;
}

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
func AOwlOntology_GetDisjointDataPropertiesAxioms(AOwlDataProperty Property)
{
	return 0;
}

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
func AOwlOntology_GetFunctionalDataPropertyAxioms(AOwlDataPropertyExpression Property)
{
	return 0;
}

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
func AOwlOntology_GetClassAssertionAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetClassAssertionAxioms2(AOwlClassExpression Ce)
{
	return 0;
}

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
func AOwlOntology_GetDataPropertyAssertionAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetObjectPropertyAssertionAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetNegativeObjectPropertyAssertionAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetNegativeDataPropertyAssertionAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetSameIndividualAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetDifferentIndividualAxioms(AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetDatatypeDefinitions(AOwlDatatype Datatype)
{
	return 0;
}
