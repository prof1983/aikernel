/* AOwl types
 * Author Prof1983 prof1983@ya.ru
 * Created 14.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: OwlApi
 * http://sourceforge.net/projects/owlapi/
 * http://owlapi.sourceforge.net/
 */

#ifndef AOwlTypes_H
#define AOwlTypes_H

#include "A.h"
#include "ABase2.h"

// ---

typedef AVersion AOwlVersion;

// --- Entity ---

typedef AInt AOwlEntity;

/** Prototype: java.util.Set */
typedef AInt AOwlEntitySet;

/** Prototype: java.util.List */
typedef AInt AOwlEntityList;

/** Prototype: java Iterator */
typedef AInt AOwlEntityIterator;

// --- Object ---

typedef AOwlEntity AOwlObject;

// --- Node ---

typedef AInt AOwlNode;
typedef AInt AOwlNodeSet;
typedef AOwlNode AOwlDefaultNode;
typedef AOwlNode AOwlClassNode;
typedef AOwlNode AOwlDataPropertyNode;
typedef AOwlNode AOwlDatatypeNode;
typedef AOwlNode AOwlNamedIndividualNode;
typedef AOwlNode AOwlObjectPropertyNode;

// --- Ontology ---

typedef AOwlNode AOwlClass;
typedef AOwlNode AOwlDataProperty;
typedef AOwlNode AOwlObjectPropertyExpression;
typedef AOwlNode AOwlNamedIndividual;
typedef AOwlNode AOwlClassExpression;
typedef AOwlNode AOwlDataPropertyExpression;

typedef AInt AOwlAxiom;
typedef AInt AOwlAxiomType;
typedef AInt AOwlIri;
typedef AInt AOwlOntologyId;

typedef AOwlEntity AOwlAnonymousIndividual;
typedef AOwlEntity AOwlIndividual;
typedef AOwlEntity AOwlAnnotationProperty;
typedef AOwlEntity AOwlDatatype;
typedef AOwlEntity AOwlAnnotationSubject;

typedef AOwlEntitySet AOwlAxiomSet;
typedef AOwlEntitySet AOwlAnnotationSet;
typedef AOwlEntitySet AOwlIriSet;
typedef AOwlEntitySet AOwlOntologySet;
typedef AOwlEntitySet AOwlImportsDeclarationSet;
typedef AOwlEntitySet AOwlLogicalAxiomSet;
typedef AOwlEntitySet AOwlClassAxiomSet;
typedef AOwlEntitySet AOwlClassSet;
typedef AOwlEntitySet AOwlObjectPropertySet;
typedef AOwlEntitySet AOwlDataPropertySet;
typedef AOwlEntitySet AOwlNamedIndividualSet;
typedef AOwlEntitySet AOwlAnonymousIndividualSet;
typedef AOwlEntitySet AOwlDatatypeSet;
typedef AOwlEntitySet AOwlAnnotationPropertySet;
typedef AOwlEntitySet AOwlObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlDataPropertyAxiomSet;
typedef AOwlEntitySet AOwlIndividualAxiomSet;
typedef AOwlEntitySet AOwlAnnotationAxiomSet;
typedef AOwlEntitySet AOwlDatatypeDefinitionAxiomSet;
typedef AOwlEntitySet AOwlSubAnnotationPropertyOfAxiomSet;
typedef AOwlEntitySet AOwlAnnotationPropertyDomainAxiomSet;
typedef AOwlEntitySet AOwlAnnotationPropertyRangeAxiomSet;
typedef AOwlEntitySet AOwlDeclarationAxiomSet;
typedef AOwlEntitySet AOwlAnnotationAssertionAxiomSet;
typedef AOwlEntitySet AOwlSubClassOfAxiomSet;
typedef AOwlEntitySet AOwlEquivalentClassesAxiomSet;
typedef AOwlEntitySet AOwlDisjointClassesAxiomSet;
typedef AOwlEntitySet AOwlDisjointUnionAxiomSet;
typedef AOwlEntitySet AOwlHasKeyAxiomSet;
typedef AOwlEntitySet AOwlSubObjectPropertyOfAxiomSet;
typedef AOwlEntitySet AOwlObjectPropertyDomainAxiomSet;
typedef AOwlEntitySet AOwlObjectPropertyRangeAxiomSet;
typedef AOwlEntitySet AOwlInverseObjectPropertiesAxiomSet;
typedef AOwlEntitySet AOwlEquivalentObjectPropertiesAxiomSet;
typedef AOwlEntitySet AOwlDisjointObjectPropertiesAxiomSet;
typedef AOwlEntitySet AOwlFunctionalObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlInverseFunctionalObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlSymmetricObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlAsymmetricObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlReflexiveObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlIrreflexiveObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlTransitiveObjectPropertyAxiomSet;
typedef AOwlEntitySet AOwlSubDataPropertyOfAxiomSet;
typedef AOwlEntitySet AOwlDataPropertyDomainAxiomSet;
typedef AOwlEntitySet AOwlDataPropertyRangeAxiomSet;
typedef AOwlEntitySet AOwlEquivalentDataPropertiesAxiomSet;
typedef AOwlEntitySet AOwlDisjointDataPropertiesAxiomSet;
typedef AOwlEntitySet AOwlFunctionalDataPropertyAxiomSet;
typedef AOwlEntitySet AOwlClassAssertionAxiomSet;
typedef AOwlEntitySet AOwlDataPropertyAssertionAxiomSet;
typedef AOwlEntitySet AOwlObjectPropertyAssertionAxiomSet;
typedef AOwlEntitySet AOwlNegativeObjectPropertyAssertionAxiomSet;
typedef AOwlEntitySet AOwlNegativeDataPropertyAssertionAxiomSet;
typedef AOwlEntitySet AOwlSameIndividualAxiomSet;
typedef AOwlEntitySet AOwlDifferentIndividualsAxiomSet;

/**
 * </p>
 * Represents an OWL 2 <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/#Ontologies">
 * Ontology</a> in the OWL 2 specification.
 * </p>
 * <p>
 * An <code>AOwlOntology</code> consists of a possibly empty set of AOwlAxioms
 * and a possibly empty set of AOwlAnnotations.  An ontology can have an ontology IRI which can
 * be used to identify the ontology. If it has an ontology IRI then it may also have an ontology
 * version IRI. Since OWL 2, an ontology need not have an ontology IRI.
 * (See the <a href="http://www.w3.org/TR/2009/REC-owl2-syntax-20091027/">OWL 2 Structural
 * Specification</a>).
 * </p>
 * An ontology cannot be modified directly. Changes must be applied via its
 * <code>AOwlOntologyManager</code>.
 */
typedef AInt AOwlOntology;

// --- Reasoner ---

/** An AOwlReasoner reasons over a set of axioms (the set of reasoner axioms) that is based on the
 *  imports closure of a particular ontology - the "root" ontology. This ontology can be obtained
 *  using the GetRootOntology() method. When the client responsible for creating the reasoner has
 *  finished with the reasoner instance it must call the Dispose() method to free any resources
 *  that are used by the reasoner. In general, reasoners should not be instantiated directly,
 *  but should be created using the appropriate AOwlReasonerFactory.
 */
typedef AInt AOwlReasoner;

// --- AOwlReasonerBufferingMode ---

/** Used to indicate the buffering mode of a reasoner.
 *
 *  Values:
 *  @n #AOwlReasonerBufferingMode_Buffering
 *  @n #AOwlReasonerBufferingMode_NonBuffering
 *
 *  @see AOwlReasoner_GetBufferingMode().
 */
typedef AInt AOwlReasonerBufferingMode;

/** Represents a mode where ontology changes are buffered inside an OwlReasoner.
 *  The reasoner only considers the changes when the buffer is flushed with the
 *  AOwlReasoner_Flush() method.
 */
#define AOwlReasonerBufferingMode_Buffering 0

/** Represents a mode where ontology changes are not buffered inside an AOwlReasoner.
 *  The reasoner considers all changes immediately.
 */
#define AOwlReasonerBufferingMode_NonBuffering 1

// --- AOwlReasonerFreshEntityPolicy ---

/** A fresh entity is an entity that is not a built in entity (see AOwlEntity_IsBuiltIn())
 *  and is not contained within the signature of the root ontology imports closure.
 *
 *  Values:
 *  @n #AOwlReasonerFreshEntityPolicy_Allow
 *  @n #AOwlReasonerFreshEntityPolicy_Disallow
 */
typedef AInt AOwlReasonerFreshEntityPolicy;

/** Specifies that fresh entities are allowed when they are encountered in the signature of
 *  AOwlObjects in queries to a reasoner.
 */
#define AOwlReasonerFreshEntityPolicy_Allow 0

/** Specifies that fresh entities are not disallowed.
 *  When a fresh entity is encountered in the signature of an AOwlObject that is used in a
 *  query to a reasoner an FreshEntitiesException will be thrown in the calling thread.
 */
#define AOwlReasonerFreshEntityPolicy_Disallow 1

// --- AOwlReasonerIndividualNodeSetPolicy ---

/** The policy of how a reasoner will return NodeSets of individuals for queries that return
 *  node sets of named individuals such as AOwlReasoner_GetTypes(AOwlNamedIndividual, ABoolean) or
 *  AOwlReasoner_GetInstances(AOwlClassExpression, ABoolean).
 *
 * @n #AOwlReasonerIndividualNodeSetPolicy_ByName
 * @n #AOwlReasonerIndividualNodeSetPolicy_BySameAs
 */
typedef AInt AOwlReasonerIndividualNodeSetPolicy;

/** Indicates that NodeSets of named individuals will always contain singleton Nodes and
 *  individuals that are the same as each other will not be grouped together in one Node
 *  within the NodeSet.For example, if i, j and k are individuals, and they are instances of C,
 *  and i is entailed to be the same as j then asking for the instances of A will return a NodeSet
 *  containing three Nodes, one containing i, one containing j and the third containing k.
 *
 *  Indicates that NodeSets of named individuals returned by the reasoner will contain Nodes
 *  that group individuals which are entailed to be the same as each other. For example,
 *  if i, j and k are individuals, and they are instances of C, and i is entailed to be the
 *  same as j then asking for the instances of A will return a NodeSet containing two Nodes,
 *  one containing i and j and the other containing k.
 */
#define AOwlReasonerIndividualNodeSetPolicy_ByName 0

/** Indicates that NodeSets of named individuals returned by the reasoner will contain Nodes
 *  that group individuals which are entailed to be the same as each other.
 *
 *  Indicates that NodeSets of named individuals will always contain singleton Nodes and
 *  individuals that are the same as each other will not be grouped together in one Node
 *  within the NodeSet.For example, if i, j and k are individuals, and they are instances
 *  of C, and i is entailed to be the same as j then asking for the instances of A will
 *  return a NodeSet containing three Nodes, one containing i, one containing j
 *  and the third containing k.
 */
#define AOwlReasonerIndividualNodeSetPolicy_BySameAs 1

// --- InferenceType ---

/** InferenceType
 *
 * @n #AOwlInferenceType_ClassAssertions
 * @n #AOwlInferenceType_ClassHierarchy
 * @n #AOwlInferenceType_DataPropertyAssertions
 * @n #AOwlInferenceType_DataPropertyHierarchy
 * @n #AOwlInferenceType_DifferentIndividuals
 * @n #AOwlInferenceType_DisjointClasses
 * @n #AOwlInferenceType_ObjectPropertyAssertions
 * @n #AOwlInferenceType_ObjectPropertyHierarchy
 * @n #AOwlInferenceType_SameIndividual
 */
typedef AInt AOwlInferenceType;

/** Denotes the computation of the direct types of individuals for each individual in the
 *  signature of the imports closure of the root ontology.
 */
#define AOwlInferenceType_ClassAssertions 0

/** Denotes the computation of the class hierarchy. */
#define AOwlInferenceType_ClassHierarchy 1

/** Denotes the computation of relationships between individuals and data property values for each
 *  individual in the signature of the imports closure of the root ontology.
 */
#define AOwlInferenceType_DataPropertyAssertions 2

/** Denotes the computation of the data property hierarchy. */
#define AOwlInferenceType_DataPropertyHierarchy 3

/** Denotes the computation of sets of individuals that are different from each individual in the
 *  signature of the imports closure of the root ontology.
 */
#define AOwlInferenceType_DifferentIndividuals 4

/** Denotes the computation of sets of classes that are disjoint for each class in the
 *  signature of the imports closure of the root ontology.
 */
#define AOwlInferenceType_DisjointClasses 5

/** Denotes the computation of relationships between individuals in the signature of the
 *  imports closure of the root ontology.
 */
#define AOwlInferenceType_ObjectPropertyAssertions 6

/** Denotes the computation of the object property hierarchy. */
#define AOwlInferenceType_ObjectPropertyHierarchy 7

/** Denotes the computation of individuals that are interpreted as the same object for each
 *  individual in the imports closure of the root ontology.
 */
#define AOwlInferenceType_SameIndividual 8

// ---

typedef AInt AOwlInferenceTypeSet;

#endif // AOwlTypes_H
