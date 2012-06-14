/* AOwl types
Author(Prof1983 prof1983@ya.ru)
Created(14.06.2012)
LastMod(14.06.2012)
Version(0.0)

Prototype: OwlApi
http://sourceforge.net/projects/owlapi/
http://owlapi.sourceforge.net/
*/

#ifndef AOwl_H
#define AOwl_H

#include "ABase2.h"

#define ATypeDef(Var, Typ) typedef Typ Var

// ---

ATypeDef(AOwlVersion, AVersion);

// --- Entity ---

ATypeDef(AOwlEntity, AInt);

/** Prototype: java.util.Set */
ATypeDef(AOwlEntitySet, AInt);

/** Prototype: java.util.List */
ATypeDef(AOwlEntityList, AInt);

/** Prototype: java Iterator */
ATypeDef(AOwlEntityIterator, AInt);

// --- Object ---

ATypeDef(AOwlObject, AOwlEntity);

// --- Node ---

ATypeDef(AOwlNode, AInt);
ATypeDef(AOwlNodeSet, AInt);
ATypeDef(AOwlDefaultNode, AOwlNode);
ATypeDef(AOwlClassNode, AOwlNode);
ATypeDef(AOwlDataPropertyNode, AOwlNode);
ATypeDef(AOwlDatatypeNode, AOwlNode);
ATypeDef(AOwlNamedIndividualNode, AOwlNode);
ATypeDef(AOwlObjectPropertyNode, AOwlNode);

// --- Ontology ---

ATypeDef(AOwlClass, AOwlNode);
ATypeDef(AOwlDataProperty, AOwlNode);
ATypeDef(AOwlObjectPropertyExpression, AOwlNode);
ATypeDef(AOwlNamedIndividual, AOwlNode);
ATypeDef(AOwlClassExpression, AOwlNode);
ATypeDef(AOwlDataPropertyExpression, AOwlNode);

ATypeDef(AOwlOntology, AInt);

// --- Reasoner ---

/** An AOwlReasoner reasons over a set of axioms (the set of reasoner axioms) that is based on the
	imports closure of a particular ontology - the "root" ontology. This ontology can be obtained
	using the GetRootOntology() method. When the client responsible for creating the reasoner has
	finished with the reasoner instance it must call the Dispose() method to free any resources
	that are used by the reasoner. In general, reasoners should not be instantiated directly,
	but should be created using the appropriate AOwlReasonerFactory. */
ATypeDef(AOwlReasoner, AInt);

// --- AOwlReasonerBufferingMode ---

/** Used to indicate the buffering mode of a reasoner.
	See AOwlReasoner_GetBufferingMode(). */
ATypeDef(AOwlReasonerBufferingMode, AInt);

/** Represents a mode where ontology changes are buffered inside an OwlReasoner.
	The reasoner only considers the changes when the buffer is flushed with the
	AOwlReasoner_Flush() method. */
const AOwlReasonerBufferingMode_Buffering = 0;

/** Represents a mode where ontology changes are not buffered inside an AOwlReasoner.
	The reasoner considers all changes immediately. */
const AOwlReasonerBufferingMode_NonBuffering = 1;

// --- AOwlReasonerFreshEntityPolicy ---

/** A fresh entity is an entity that is not a built in entity (see AOwlEntity_IsBuiltIn())
	and is not contained within the signature of the root ontology imports closure. */
ATypeDef(AOwlReasonerFreshEntityPolicy, AInt);

/** Specifies that fresh entities are allowed when they are encountered in the signature of
	AOwlObjects in queries to a reasoner. */
const AOwlReasonerFreshEntityPolicy_Allow = 0;

/** Specifies that fresh entities are not disallowed.
	When a fresh entity is encountered in the signature of an AOwlObject that is used in a
	query to a reasoner an FreshEntitiesException will be thrown in the calling thread. */
const AOwlReasonerFreshEntityPolicy_Disallow = 1;

// --- AOwlReasonerIndividualNodeSetPolicy ---

/** The policy of how a reasoner will return NodeSets of individuals for queries that return
	node sets of named individuals such as AOwlReasoner_GetTypes(AOwlNamedIndividual, ABoolean) or
	AOwlReasoner_GetInstances(AOwlClassExpression, ABoolean). */
ATypeDef(AOwlReasonerIndividualNodeSetPolicy, AInt);

/** Indicates that NodeSets of named individuals will always contain singleton Nodes and
	individuals that are the same as each other will not be grouped together in one Node
	within the NodeSet.For example, if i, j and k are individuals, and they are instances of C,
	and i is entailed to be the same as j then asking for the instances of A will return a NodeSet
	containing three Nodes, one containing i, one containing j and the third containing k.

	Indicates that NodeSets of named individuals returned by the reasoner will contain Nodes
	that group individuals which are entailed to be the same as each other. For example,
	if i, j and k are individuals, and they are instances of C, and i is entailed to be the
	same as j then asking for the instances of A will return a NodeSet containing two Nodes,
	one containing i and j and the other containing k. */
const AOwlReasonerIndividualNodeSetPolicy_ByName = 0;

/** Indicates that NodeSets of named individuals returned by the reasoner will contain Nodes
	that group individuals which are entailed to be the same as each other.

	Indicates that NodeSets of named individuals will always contain singleton Nodes and
	individuals that are the same as each other will not be grouped together in one Node
	within the NodeSet.For example, if i, j and k are individuals, and they are instances
	of C, and i is entailed to be the same as j then asking for the instances of A will
	return a NodeSet containing three Nodes, one containing i, one containing j
	and the third containing k. */
const AOwlReasonerIndividualNodeSetPolicy_BySameAs = 1;

// --- InferenceType ---

ATypeDef(AOwlInferenceType, AInt);

/** Denotes the computation of the direct types of individuals for each individual in the
	signature of the imports closure of the root ontology. */
const AOwlInferenceType_ClassAssertions = 0;

/** Denotes the computation of the class hierarchy. */
const AOwlInferenceType_ClassHierarchy = 1;

/** Denotes the computation of relationships between individuals and data property values for each
	individual in the signature of the imports closure of the root ontology. */
const AOwlInferenceType_DataPropertyAssertions = 2;

/** Denotes the computation of the data property hierarchy. */
const AOwlInferenceType_DataPropertyHierarchy = 3;

/** Denotes the computation of sets of individuals that are different from each individual in the
	signature of the imports closure of the root ontology. */
const AOwlInferenceType_DifferentIndividuals = 4;

/** Denotes the computation of sets of classes that are disjoint for each class in the
	signature of the imports closure of the root ontology. */
const AOwlInferenceType_DisjointClasses = 5;

/** Denotes the computation of relationships between individuals in the signature of the
	imports closure of the root ontology. */
const AOwlInferenceType_ObjectPropertyAssertions = 6;

/** Denotes the computation of the object property hierarchy. */
const AOwlInferenceType_ObjectPropertyHierarchy = 7;

/** Denotes the computation of individuals that are interpreted as the same object for each
	individual in the imports closure of the root ontology. */
const AOwlInferenceType_SameIndividual = 8;

#endif
