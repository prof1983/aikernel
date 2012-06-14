/* AOwl reasoner functions
Author(Prof1983 prof1983@ya.ru)
Created(14.06.2012)
LastMod(14.06.2012)
Version(0.0)

Prototype: OwlApi
http://sourceforge.net/projects/owlapi/
http://owlapi.sourceforge.net/
*/

#include "AOwl.h"

// --- AOwlReasoner ---

/*
Ontology Change Management (Buffering and Non-Buffering Modes)

At creation time, an OwlReasoner will load the axioms in the root ontology imports closure.
It will attach itself as a listener to the OwlOntologyManager that manages the root ontology.
The reasoner will listen to any OwlOntologyChanges and respond appropriately to them before
answering any queries. If the BufferingMode of the reasoner (the answer to GetBufferingMode()
is BufferingMode.NON_BUFFERING) the ontology changes are processed by the reasoner immediately so
that any queries asked after the changes are answered with respect to the changed ontologies.
If the BufferingMode of the reasoner is BufferingMode.BUFFERING then ontology changes are
stored in a buffer and are only taken into consideration when the buffer is flushed with the
Flush() method. When reasoning, axioms in the root ontology imports closure, minus the axioms
returned by the GetPendingAxiomAdditions() method, plus the axioms returned by the
GetPendingAxiomRemovals() are taken into consideration.

Reasoner Axioms

The set of axioms that the reasoner takes into consideration when answering queries is
known as the set of reasoner axioms. This corresponds the axioms in the imports closure of the
root ontology plus the axioms returned by the GetPendingAxiomRemovals() minus the axioms
returned by GetPendingAxiomAdditions().

Nodes

The reasoner interface contains methods that return NodeSets. These are sets of Nodes.
A Node contains entities.

For a Node<OwlClass> of classes, each class in the node is equivalent to the other classes in the
Node with respect to the imports closure of the root ontology.

For a Node<OwlObjectProperty> of object properties, each object property in the Node is
equivalent to the other object properties in the node with respect to the imports closure of the
root ontology.

For a Node<OwlDataProperty> of data properties, each data property in the Node is equivalent to the
other data properties in the node with respect to the imports closure of the root ontology.

For a Node<OwlNamedIndividual> of named individuals, each individual in the node is the same as the
other individuals in the node with respect to the imports closure of the root ontology.

By abuse of notation, we say that a NodeSet "contains" an entity if that entity is contained in
one of the Nodes in the NodeSet.
*/

/** Disposes of this reasoner. */
AInt
func AOwlReasoner_Dispose(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Flushes any changes stored in the buffer, which causes the reasoner to take into
	consideration the changes the current root ontology specified by the changes. */
AInt
func AOwlReasoner_Flush(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:Nothing) in the class hierarchy. */
AOwlClass
func AOwlReasoner_GetBottomClassNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:bottomDataProperty) in the data property hierarchy. */
AOwlDataProperty
func AOwlReasoner_GetBottomDataPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:bottomObjectProperty) in the object property hierarchy. */
AOwlObjectPropertyExpression
func AOwlReasoner_GetBottomObjectPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the buffering mode of this reasoner. */
AOwlReasonerBufferingMode
func AOwlReasoner_GetBufferingMode(AOwlReasoner OwlReasoner)
{
	return AOwlReasonerBufferingMode_Buffering;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect domains of this
	property with respect to the imports closure of the root ontology. */
AOwlNodeSet
func AOwlReasoner_GetDataPropertyDomains(AOwlReasoner OwlReasoner, AOwlDataProperty pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the data property values (AOwlLiteral) for the specified individual and data property
	expression. */
AOwlEntitySet
func AOwlReasoner_GetDataPropertyValues(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind,
	AOwlDataProperty pe)
{
    return 0;
}

/** Gets the individuals (AOwlNamedIndividual) which are entailed to be different from the
	specified individual. */
AOwlNodeSet
func AOwlReasoner_GetDifferentIndividuals(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind)
{
	return 0;
}

/** Gets the classes (AOwlClass) that are disjoint with the specified class expression ce. */
AOwlNodeSet
func AOwlReasoner_GetDisjointClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce)
{
	return 0;
}

/** Gets the data properties (AOwlDataProperty) that are disjoint with the specified data
	property expression pe. */
AOwlNodeSet
func AOwlReasoner_GetDisjointDataProperties(AOwlReasoner OwlReasoner, AOwlDataPropertyExpression pe)
{
	return 0;
}

/** Gets the simplified object property expressions (AOwlObjectPropertyExpression) that are
	disjoint with the specified object property expression pe. */
AOwlNodeSet
func AOwlReasoner_GetDisjointObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the set of named classes (AOwlClass) that are equivalent to the specified class
	expression with respect to the set of reasoner axioms. */
AOwlNode
func AOwlReasoner_GetEquivalentClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce)
{
	return 0;
}

/** Gets the set of named data properties (AOwlDataProperty) that are equivalent to the	specified
	data property expression with respect to the imports closure of the root ontology. */
AOwlNode
func AOwlReasoner_GetEquivalentDataProperties(AOwlReasoner OwlReasoner, AOwlDataProperty pe)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
	that are equivalent to the specified object property expression with respect to the set of
	reasoner axioms. */
AOwlNode
func AOwlReasoner_GetEquivalentObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the Fresh Entity Policy in use by this reasoner. */
AOwlReasonerFreshEntityPolicy
func AOwlReasoner_GetFreshEntityPolicy(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the IndividualNodeSetPolicy in use by this reasoner. */
AOwlReasonerIndividualNodeSetPolicy
func AOwlReasoner_GetIndividualNodeSetPolicy(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the individuals (AOwlNamedIndividual) which are instances of the specified
	class expression. */
AOwlNodeSet
func AOwlReasoner_GetInstances(AOwlReasoner OwlReasoner, AOwlClassExpression ce, ABoolean direct)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
	that are the inverses of the specified object property expression with respect to the
	imports closure of the root ontology. */
AOwlNode
func AOwlReasoner_GetInverseObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect domains of this
	property with respect to the imports closure of the root ontology. */
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyDomains(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe, ABoolean direct)
{
	return 0;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect ranges of this
	property with respect to the imports closure of the root ontology. */
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyRanges(AOwlReasoner OwlReasoner, AOwlObjectPropertyExpression pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the object property values for the specified individual (AOwlNamedIndividual)
	and object property expression. */
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyValues(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the axioms (AOwlAxiom) that as a result of ontology changes need to be added to the
	reasoner to synchronise it with the root ontology imports closure. */
AOwlEntitySet
func AOwlReasoner_GetPendingAxiomAdditions(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the axioms (AOwlAxiom) that as a result of ontology changes need to removed to the
	reasoner to synchronise it with the root ontology imports closure. */
AOwlEntitySet
func AOwlReasoner_GetPendingAxiomRemovals(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the pending changes (AOwlOntologyChange) which need to be taken into consideration by the
	reasoner so that it is up to date with the root ontology imports closure. */
AOwlEntityList
func AOwlReasoner_GetPendingChanges(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Returns the set of InferenceTypes (AOwlInferenceType) that are precomputable by reasoner. */
AOwlEntitySet
func AOwlReasoner_GetPrecomputableInferenceTypes(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the name of this reasoner. */
AError
func AOwlReasoner_GetReasonerName(AOwlReasoner OwlReasoner, AString Value)
{
	return -1;
}

/** Gets the version of this reasoner. */
AOwlVersion
func AOwlReasoner_GetReasonerVersion(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the "root" ontology that is loaded into this reasoner. */
AOwlOntology
func AOwlReasoner_GetRootOntology(AOwlReasoner OwlReasoner)
{
	return 0;
}
