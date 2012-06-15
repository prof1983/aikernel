/* AOwl reasoner functions
 * Author(Prof1983 prof1983@ya.ru)
 * Created(14.06.2012)
 * LastMod(15.06.2012)
 * Version(0.0)

 * Prototype: OwlApi
 * http://sourceforge.net/projects/owlapi/
 * http://owlapi.sourceforge.net/
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

/** Disposes of this reasoner.
 *
 *  This frees up any resources used by the reasoner and detaches the reasoner as an
 *  AOwlOntologyChangeListener from the AOwlOntologyManager that manages the
 *  ontologies contained within the reasoner.
 */
AInt
func AOwlReasoner_Dispose(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Flushes any changes stored in the buffer, which causes the reasoner to take into
 *  consideration the changes the current root ontology specified by the changes.
 *
 *  If the reasoner buffering mode is BufferingMode.NON_BUFFERING then this method will
 *  have no effect.
 */
AInt
func AOwlReasoner_Flush(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:Nothing) in the class hierarchy.
 *
 *  @return A Node containing owl:Nothing that is the bottom node in the class hierarchy.
 *      This Node is essentially equal to the Node that will be returned by calling
 *      GetEquivalentClasses(AOwlClassExpression) with a parameter of owl:Nothing.
 */
AOwlClass
func AOwlReasoner_GetBottomClassNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:bottomDataProperty) in the
 *  data property hierarchy.
 *
 *  @return A Node, containing owl:bottomDataProperty, that is the bottom node in the data
 *      property hierarchy. This Node is essentially equal to the Node that will be
 *      returned by calling GetEquivalentDataProperties(AOwlDataProperty) with a
 *      parameter of owl:bottomDataProperty.
 */
AOwlDataProperty
func AOwlReasoner_GetBottomDataPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node corresponding to the bottom node (containing owl:bottomObjectProperty) in the
 *  object property hierarchy.
 *
 *  @return A Node, containing owl:bottomObjectProperty, that is the bottom node in the object
 *      property hierarchy. This Node is essentially equal to the Node that will be returned by
 *      calling GetEquivalentObjectProperties(AOwlObjectPropertyExpression) with a
 *      parameter of owl:bottomObjectProperty.
 */
AOwlObjectPropertyExpression
func AOwlReasoner_GetBottomObjectPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the buffering mode of this reasoner.
 *
 *  @return The buffering mode of this reasoner.
 */
AOwlReasonerBufferingMode
func AOwlReasoner_GetBufferingMode(AOwlReasoner OwlReasoner)
{
	return AOwlReasonerBufferingMode_Buffering;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect domains of this
 *  property with respect to the imports closure of the root ontology.
 *
 *  The classes are returned as a NodeSet.
 *
 *  @param pe - The property expression whose domains are to be retrieved.
 *  @param direct - Specifies if the direct domains should be retrieved (true), or if all
 *      domains should be retrieved (false).
 *  @return Let N = getEquivalentClasses(DataSomeValuesFrom(pe rdfs:Literal)).
 *  @return If direct is true: then if N is not empty then the return value is N, else the return
 *      value is the result of getSuperClasses(DataSomeValuesFrom(pe rdfs:Literal), true).
 *  @return If direct is false: then the result of
 *      GetSuperClasses(DataSomeValuesFrom(pe rdfs:Literal), false) together with N if N is
 *      non-empty. (Note, rdfs:Literal is the top datatype).
 */
/*	Throws:
 *		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
 *		FreshEntitiesException - if the signature of the object property expression is not
 *			contained within the signature of the imports closure of the root ontology and the
 *			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *		ReasonerInterruptedException - if the reasoning process was interrupted for any
 *			particular reason (for example if reasoning was cancelled by a client process)
 *		TimeOutException - if the reasoner timed out during a basic reasoning
 *			operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetDataPropertyDomains(AOwlReasoner OwlReasoner, AOwlDataProperty pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the data property values (AOwlLiteral) for the specified individual and data
 *  property expression.
 *
 *  The values are a set of literals. Note that the results are not guaranteed to be complete
 *  for this method. The reasoner may also return canonical literals or they may be	in a form
 *  that bears a resemblance to the syntax of the literals in the root ontology imports closure.
 *
 *  @param ind - The individual that is the subject of the data property values
 *  @param pe - The data property expression whose values are to be retrieved for the
 *      specified individual
 *
 *  @return A set of OWLLiterals containing literals such that for each literal l in the set,
 *      the set of reasoner axioms entails DataPropertyAssertion(pe ind l).
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the individual and property expression is
 *      not contained within the signature of the imports closure of the root ontology and
 *      the undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException (-4) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-5) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 *
 *  @see AOwlReasonerIndividualNodeSetPolicy
 */
AOwlEntitySet
func AOwlReasoner_GetDataPropertyValues(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind,
	AOwlDataProperty pe)
{
    return 0;
}

/** Gets the individuals (AOwlNamedIndividual) which are entailed to be different from the
 *  specified individual.
 *
 *  The individuals are returned as a NodeSet.
 *
 *  @param ind - The individual whose different individuals are to be returned.
 *  @return A NodeSet containing OWLNamedIndividuals such that for each individual i in the NodeSet
 *      the set of reasoner axioms entails DifferentIndividuals(ind, i).
*/
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the individual is not contained within the
			signature of the imports closure of the root ontology and the undeclared entity
			policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetDifferentIndividuals(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind)
{
	return 0;
}

/** Gets the classes (AOwlClass) that are disjoint with the specified class expression ce.
 *
 *  The classes are returned as a NodeSet.
 *
 *  @param ce - The class expression whose disjoint classes are to be retrieved.
 *  @return The return value is a NodeSet such that for each class D in the NodeSet the set of
 *      reasoner axioms entails EquivalentClasses(D, ObjectComplementOf(ce)) or
 *      StrictSubClassOf(D, ObjectComplementOf(ce)).
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if classExpression is not within the profile
			that is supported by this reasoner.
		FreshEntitiesException - if the signature of the classExpression is not contained
			within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetDisjointClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce)
{
	return 0;
}

/** Gets the data properties (AOwlDataProperty) that are disjoint with the specified data
 *  property expression pe.
 *
 *  The data properties are returned as a NodeSet.
 *
 *  @param pe - The data property expression whose disjoint data properties are to be retrieved.
 *  @return The return value is a NodeSet such that for each data property P in the NodeSet the set
 *      of reasoner axioms entails EquivalentDataProperties(P, DataPropertyComplementOf(pe)) or
 *      StrictSubDataPropertyOf(P, DataPropertyComplementOf(pe)).
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if data propertyExpression is not within the
			profile that is supported by this reasoner.
		FreshEntitiesException - if the signature of pe is not contained within the
			signature of the imports closure of the root ontology and the undeclared entity
			policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetDisjointDataProperties(AOwlReasoner OwlReasoner, AOwlDataPropertyExpression pe)
{
	return 0;
}

/** Gets the simplified object property expressions (AOwlObjectPropertyExpression) that are
 *  disjoint with the specified object property expression pe.
 *
 *  The object properties are returned as a NodeSet.
 *
 *  @param pe - The object property expression whose disjoint object properties are to be retrieved.
 *  @return	The return value is a NodeSet of simplified object property expressions, such that for
 *      each simplified object property expression, P, in the NodeSet the set of reasoner
 *      axioms entails EquivalentObjectProperties(P, ObjectPropertyComplementOf(pe)) or
 *      StrictSubObjectPropertyOf(P, ObjectPropertyComplementOf(pe)).
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if object propertyExpression is not within the
			profile that is supported by this reasoner.
		FreshEntitiesException - if the signature of pe is not contained within the
			signature of the imports closure of the root ontology and the undeclared entity
			policy of this reasoner is set to FreshEntityPolicy.DISALLOW.and the undeclared
			entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetDisjointObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the set of named classes (AOwlClass) that are equivalent to the specified class
 *  expression with respect to the set of reasoner axioms.
 *
 *  The classes are returned as a Node.
 *
 *  @param ce - The class expression whose equivalent classes are to be retrieved.
 *  @return A node containing the named classes such that for each named class C in the
 *      node the root ontology imports closure entails EquivalentClasses(ce C).
 *      If ce is not a class name (i.e. it is an anonymous class expression) and there
 *      are no such classes C then the node will be empty.
 *
 *      If ce is a named class then ce will be contained in the node.
 *
 *      If ce is unsatisfiable with respect to the set of reasoner axioms then the node
 *      representing and containing owl:Nothing, i.e. the bottom node, will be returned.
 *
 *      If ce is equivalent to owl:Thing with respect to the set of reasoner axioms then the
 *      node representing and containing owl:Thing, i.e. the top node, will be returned.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if classExpression is not within the profile
			that is supported by this reasoner.
		FreshEntitiesException - if the signature of the classExpression is not contained
			within the signature of the imports closure of the root ontology and the undeclared
			entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNode
func AOwlReasoner_GetEquivalentClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce)
{
	return 0;
}

/** Gets the set of named data properties (AOwlDataProperty) that are equivalent to the	specified
 *  data property expression with respect to the imports closure of the root ontology.
 *
 *  The properties are returned as a Node.
 *
 *  @param pe - The data property expression whose equivalent properties are to be retrieved.
 *
 *  @return A node containing the named data properties such that for each named data
 *      property P in the node, the set of reasoner axioms entails EquivalentDataProperties(pe P).
 *
 *      If pe is a named data property then pe will be contained in the node.
 *
 *      If pe is unsatisfiable with respect to the set of reasoner axioms then the node
 *      representing and containing owl:bottomDataProperty, i.e. the bottom node, will be returned.

 *      If ce is equivalent to owl:topDataProperty with respect to the set of reasoner
 *      axioms then the node representing and containing owl:topDataProperty,
 *      i.e. the top node, will be returned.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the data property expression is not
			contained within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNode
func AOwlReasoner_GetEquivalentDataProperties(AOwlReasoner OwlReasoner, AOwlDataProperty pe)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
 *  that are equivalent to the specified object property expression with respect to the set of
 *  reasoner axioms.
 *
 *  The properties are returned as a Node.
 *
 *  @param pe - The object property expression whose equivalent properties are to be retrieved.
 *  @return A node containing the simplified object property expressions such that for each
 *      simplified object property expression, P, in the node, the set of reasoner axioms
 *      entails EquivalentObjectProperties(pe P).
 *
 *
 *      If pe is a simplified object property expression then pe will be contained in the node.
 *
 *      If pe is unsatisfiable with respect to the set of reasoner axioms then the node
 *      representing and containing owl:bottomObjectProperty, i.e. the bottom node, will be returned.
 *
 *      If pe is equivalent to owl:topObjectProperty with respect to the set of reasoner
 *      axioms then the node representing and containing owl:topObjectProperty,
 *      i.e. the top node, will be returned.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the object property expression is not
			contained within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNode
func AOwlReasoner_GetEquivalentObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the Fresh Entity Policy in use by this reasoner.
 *
 * The policy is set at reasoner creation time.
 *
 * @return The policy.
 */
AOwlReasonerFreshEntityPolicy
func AOwlReasoner_GetFreshEntityPolicy(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the IndividualNodeSetPolicy in use by this reasoner.
 *
 * The policy is set at reasoner creation time.
 * @return The policy.
 */
AOwlReasonerIndividualNodeSetPolicy
func AOwlReasoner_GetIndividualNodeSetPolicy(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the individuals (AOwlNamedIndividual) which are instances of the specified
 *  class expression.
 *
 *  The individuals are returned a a NodeSet.
 *
 *  @param ce - The class expression whose instances are to be retrieved.
 *  @param direct - Specifies if the direct instances should be retrieved (true), or if all
 *      instances should be retrieved (false).
 *  @return If direct is true, a NodeSet containing named individuals such that for each named
 *      individual j in the node set, the set of reasoner axioms entails DirectClassAssertion(ce, j).
 *
 *      If direct is false, a NodeSet containing named individuals such that for each named
 *      individual j in the node set, the set of reasoner axioms entails ClassAssertion(ce, j).
 *
 *      If ce is unsatisfiable with respect to the set of reasoner axioms then the
 *      empty NodeSet is returned.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if the class expression ce is not in the
			profile that is supported by this reasoner.
		FreshEntitiesException - if the signature of the class expression is not contained
			within the signature of the imports closure of the root ontology and the undeclared
			entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
	See Also:
		AOwlReasonerIndividualNodeSetPolicy
*/
AOwlNodeSet
func AOwlReasoner_GetInstances(AOwlReasoner OwlReasoner, AOwlClassExpression ce, ABoolean direct)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
 *  that are the inverses of the specified object property expression with respect to the
 *  imports closure of the root ontology.
 *
 *  The properties are returned as a NodeSet
 *
 *  @param pe - The property expression whose inverse properties are to be retrieved.
 *  @return	A NodeSet of simplified object property expressions, such that for each simplified
 *      object property expression P in the nodes set, the set of reasoner axioms entails
 *      InverseObjectProperties(pe, P).
 */
/*
   Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the object property expression is not
			contained within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNode
func AOwlReasoner_GetInverseObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect domains of this
 *  property with respect to the imports closure of the root ontology.
 *
 *  The classes are returned as a NodeSet.
 *
 *  @param pe - The property expression whose domains are to be retrieved.
 *  @param direct - Specifies if the direct domains should be retrieved (true), or if all
 *      domains should be retrieved (false).
 *  @return Let N = getEquivalentClasses(ObjectSomeValuesFrom(pe owl:Thing)).
 *
 *  If direct is true: then if N is not empty then the return value is N, else the
 *  return value is the result of getSuperClasses(ObjectSomeValuesFrom(pe owl:Thing), true).
 *
 *  If direct is false: then the result of GetSuperClasses(ObjectSomeValuesFrom(pe owl:Thing), false)
 *  together with N if N is non-empty.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the object property expression is not
			contained within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyDomains(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe, ABoolean direct)
{
	return 0;
}

/** Gets the named classes (AOwlClass) that are the direct or indirect ranges of this
 *  property with respect to the imports closure of the root ontology.
 *
 *  The classes are returned as a NodeSet.
 *
 *  @param pe - The property expression whose ranges are to be retrieved.
 *  @param direct - Specifies if the direct ranges should be retrieved (true), or if all
 *      ranges should be retrieved (false).
 *
 *  @return	Let N = getEquivalentClasses(ObjectSomeValuesFrom(ObjectInverseOf(pe) owl:Thing)).
 *  @return If direct is true: then if N is not empty then the return value is N, else the
 *      return value is the result of
 *      getSuperClasses(ObjectSomeValuesFrom(ObjectInverseOf(pe) owl:Thing), true).
 *  @return If direct is false: then the result of
 *      getSuperClasses(ObjectSomeValuesFrom(ObjectInverseOf(pe) owl:Thing), false)
 *      together with N if N is non-empty.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the object property expression is not
			contained within the signature of the imports closure of the root ontology and the
			undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyRanges(AOwlReasoner OwlReasoner, AOwlObjectPropertyExpression pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the object property values for the specified individual (AOwlNamedIndividual)
 *  and object property expression.
 *
 *  The individuals are returned as a NodeSet.
 *
 *  @param ind - The individual that is the subject of the object property values
 *  @param pe - The object property expression whose values are to be retrieved for the
 *      specified individual
 *  @return	A NodeSet containing named individuals such that for each individual j in the node set,
 *      the set of reasoner axioms entails ObjectPropertyAssertion(pe ind j).
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the individual and property expression is
			not contained within the signature of the imports closure of the root ontology and
			the undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
	See Also:
		AOwlReasonerIndividualNodeSetPolicy
*/
AOwlNodeSet
func AOwlReasoner_GetObjectPropertyValues(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind,
	AOwlObjectPropertyExpression pe)
{
	return 0;
}

/** Gets the axioms (AOwlAxiom) that as a result of ontology changes need to be added to the
 *  reasoner to synchronise it with the root ontology imports closure.
 *
 *  If the buffering mode is BufferingMode.NON_BUFFERING then there will be no pending
 *  axiom additions.
 *
 *  @return The set of axioms that need to added to the reasoner to the reasoner to
 *      synchronise it with the root ontology imports closure.
 */
AOwlEntitySet
func AOwlReasoner_GetPendingAxiomAdditions(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the axioms (AOwlAxiom) that as a result of ontology changes need to removed to the
 *  reasoner to synchronise it with the root ontology imports closure.
 *
 *  If the buffering mode is BufferingMode.NON_BUFFERING then there will be no pending
 *  axiom additions.
 *
 *  @return The set of axioms that need to added to the reasoner to the reasoner to
 *      synchronise it with the root ontology imports closure.
*/
AOwlEntitySet
func AOwlReasoner_GetPendingAxiomRemovals(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the pending changes (AOwlOntologyChange) which need to be taken into consideration by the
 *  reasoner so that it is up to date with the root ontology imports closure.
 *
 *  After the flush() method is called the set of pending changes will be empty.
 *
 *  @return A set of changes. Note that the changes represent the raw changes as applied to the
 *      imports closure of the root ontology.
 */
AOwlEntityList
func AOwlReasoner_GetPendingChanges(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Returns the set of InferenceTypes (AOwlInferenceType) that are precomputable by reasoner.
 *
 *  @return A set of InferenceTypes that can be precomputed by this reasoner.
 */
AOwlEntitySet
func AOwlReasoner_GetPrecomputableInferenceTypes(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the name of this reasoner.
 *
 *  @return A string that represents the name of this reasoner.
 */
AError
func AOwlReasoner_GetReasonerName(AOwlReasoner OwlReasoner, AString Value)
{
	return -1;
}

/** Gets the version of this reasoner.
 *
 *  @return The version of this reasoner. Not null.
 */
AOwlVersion
func AOwlReasoner_GetReasonerVersion(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the "root" ontology that is loaded into this reasoner.
 *
 *  The reasoner takes into account the axioms in this ontology and its imports closure,
 *  plus the axioms returned by GetPendingAxiomRemovals(), minus the axioms returned by
 *  GetPendingAxiomAdditions() when reasoning. Note that the root ontology is set at reasoner
 *  creation time and cannot be changed thereafter. Clients that want to add ontologies
 *  to and remove ontologies from the reasoner after creation time should create a "dummy"
 *  ontology that imports the "real" ontologies and then specify the dummy ontology as the
 *  root ontology at reasoner creation time.
 *
 *  @return The root ontology that is loaded into the reasoner.
 */
AOwlOntology
func AOwlReasoner_GetRootOntology(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the individuals (AOwlNamedIndividual) that are the same as the specified individual.
 *
 * @param ind - The individual whose same individuals are to be retrieved.
 *
 * @return A node containing individuals such that for each individual j in the node, the root
 *     ontology imports closure entails SameIndividual(j, ind). Note that the node will contain j.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		FreshEntitiesException - if the signature of the individual is not contained within the
			signature of the imports closure of the root ontology and the undeclared entity
			policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNode
func AOwlReasoner_GetSameIndividuals(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind)
{
	return 0;
}

/** Gets the set of named classes (AOwlClass) that are the strict (potentially direct)
 *  subclasses of the specified class expression with respect to the reasoner axioms.
 *
 *  Note that the classes are returned as a NodeSet.
 *
 *  @param ce - The class expression whose strict (direct) subclasses are to be retrieved.
 *  @param direct - Specifies if the direct subclasses should be retrived (true) or if the all
 *      subclasses (descendant) classes should be retrieved (false).
 *
 *  @return If direct is true, a NodeSet such that for each class C in the NodeSet the set of
 *      reasoner axioms entails DirectSubClassOf(C, ce).
 *      If direct is false, a NodeSet such that for each class C in the NodeSet the set of
 *      reasoner axioms entails StrictSubClassOf(C, ce).
 *      If ce is equivalent to owl:Nothing then the empty NodeSet will be returned.
 */
/*
	Throws:
		InconsistentOntologyException - if the imports closure of the root ontology is inconsistent
		ClassExpressionNotInProfileException - if classExpression is not within the profile
			that is	supported by this reasoner.
		FreshEntitiesException - if the signature of the classExpression is not contained
			within the signature of the imports closure of the root ontology and the undeclared
			entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
		ReasonerInterruptedException - if the reasoning process was interrupted for any
			particular reason (for example if reasoning was cancelled by a client process)
		TimeOutException - if the reasoner timed out during a basic reasoning
			operation. See GetTimeOut().
*/
AOwlNodeSet
func AOwlReasoner_GetSubClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce, ABoolean direct)
{
	return 0;
}

/** Gets the set of named data properties (AOwlDataProperty) that are the strict
 *  (potentially direct) subproperties of the specified data property expression with
 *  respect to the imports closure of the root ontology.
 *
 *  Note that the properties are returned as a NodeSet.
 *
 *  @param pe - The data property whose strict (direct) subproperties are to be retrieved.
 *  @param direct - Specifies if the direct subproperties should be retrived (true) or if the all
 *      subproperties (descendants) should be retrieved (false).
 *
 *  @return If direct is true, a NodeSet such that for each property P in the NodeSet the set of
 *      reasoner axioms entails DirectSubDataPropertyOf(P, pe).
 *  @return If direct is false, a NodeSet such that for each property P in the NodeSet the set of
 *      reasoner axioms entails StrictSubDataPropertyOf(P, pe).
 *  @return If pe is equivalent to owl:bottomDataProperty then the empty NodeSet will be returned.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the data property is not contained within the
 *      signature of the imports closure of the root ontology and the undeclared entity
 *      policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @param ReasonerInterruptedException (-4) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @param TimeOutException (-5) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetSubDataProperties(AOwlReasoner OwlReasoner, AOwlDataProperty pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
 *  that are the strict (potentially direct) subproperties of the specified object property
 *  expression with respect to the imports closure of the root ontology.
 *
 *  Note that the properties are returned as a NodeSet.
 *
 *  @param pe - The object property expression whose strict (direct) subproperties are to be retrieved.
 *  @param direct - Specifies if the direct subproperties should be retrived (true) or if the all
 *      subproperties (descendants) should be retrieved (false).
 *  @return If direct is true, a NodeSet of simplified object property expressions, such that for
 *      each simplified object property expression, P, in the NodeSet the set of reasoner
 *      axioms entails DirectSubObjectPropertyOf(P, pe).
 *  @return If direct is false, a NodeSet of simplified object property expressions, such that for
 *      each simplified object property expression, P, in the NodeSet the set of reasoner
 *      axioms entails StrictSubObjectPropertyOf(P, pe).
 *  @return If pe is equivalent to owl:bottomObjectProperty then the empty NodeSet will be returned.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the object property expression is not
 *      contained within the signature of the imports closure of the root ontology and the
 *      undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetSubObjectProperties(AOwlReasoner OwlReasoner, AOwlObjectPropertyExpression pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the set of named classes (AOwlClass) that are the strict (potentially direct) super classes
 *  of the specified class expression with respect to the imports closure of the root ontology.
 *
 *  Note that the classes are returned as a NodeSet.
 *
 *  @param ce - The class expression whose strict (direct) super classes are to be retrieved.
 *  @param direct - Specifies if the direct super classes should be retrived (true) or if the all
 *      super classes (ancestors) classes should be retrieved (false).
 *  @return If direct is true, a NodeSet such that for each class C in the NodeSet the set of
 *      reasoner axioms entails DirectSubClassOf(ce, C).
 *      If direct is false, a NodeSet such that for each class C in the NodeSet the set of
 *      reasoner axioms entails StrictSubClassOf(ce, C).
 *      If ce is equivalent to owl:Thing then the empty NodeSet will be returned.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return ClassExpressionNotInProfileException (-3) - if classExpression is not within the profile
 *      that is supported by this reasoner.
 *  @return FreshEntitiesException (-4) - if the signature of the classExpression is not contained
 *      within the signature of the imports closure of the root ontology and the
 *      undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetSuperClasses(AOwlReasoner OwlReasoner, AOwlClassExpression ce, ABoolean direct)
{
	return 0;
}

/** Gets the set of named data properties (AOwlDataProperty) that are the strict
 *  (potentially direct) super properties of the specified data property with
 *  respect to the imports closure of the root ontology.
 *
 *  Note that the properties are returned as a NodeSet.
 *
 *  @param pe - The data property whose strict (direct) super properties are to be retrieved.
 *  @param direct - Specifies if the direct super properties should be retrived (true) or if the
 *      all super properties (ancestors) should be retrieved (false).
 *
 *  @return If direct is true, a NodeSet such that for each property P in the NodeSet the set of
 *      reasoner axioms entails DirectSubDataPropertyOf(pe, P).
 *  @return If direct is false, a NodeSet such that for each property P in the NodeSet the set of
 *      reasoner axioms entails StrictSubDataPropertyOf(pe, P).
 *  @return If pe is equivalent to owl:topDataProperty then the empty NodeSet will be returned.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the data property is not contained within
 *      the signature of the imports closure of the root ontology and the undeclared entity
 *      policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetSuperDataProperties(AOwlReasoner OwlReasoner, AOwlDataProperty pe,
	ABoolean direct)
{
	return 0;
}

/** Gets the set of simplified object property expressions (AOwlObjectPropertyExpression)
 *  that are the strict (potentially direct) super properties of the specified object property
 *  expression with respect to the imports closure of the root ontology.
 *
 *  Note that the properties are returned as a NodeSet.
 *
 *  @param pe - The object property expression whose strict (direct) super properties
 *      are to be retrieved.
 *  @param direct - Specifies if the direct super properties should be retrived (true)
 *      or if the all super properties (ancestors) should be retrieved (false).
 *  @return If direct is true, a NodeSet of simplified object property expressions, such that for
 *      each simplified object property expression, P, in the NodeSet, the set of reasoner
 *      axioms entails DirectSubObjectPropertyOf(pe, P).
 *  @return	If direct is false, a NodeSet of simplified object property expressions, such that
 *      for each simplified object property expression, P, in the NodeSet, the set of
 *      reasoner axioms entails StrictSubObjectPropertyOf(pe, P).
 *  @return If pe is equivalent to owl:topObjectProperty then the empty NodeSet will be returned.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the object property expression is not
 *      contained within the signature of the imports closure of the root ontology and the
 *      undeclared entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException (-4) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-5) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetSuperObjectProperties(AOwlReasoner OwlReasoner,
	AOwlObjectPropertyExpression pe, ABoolean direct)
{
	return 0;
}

/** Gets the time out (in milliseconds) for the most basic reasoning operations.
 *
 *  That is the maximum time for a satisfiability test, subsumption test etc.
 *  The time out should be set at reasoner creation time. During satisfiability (subsumption)
 *  checking the reasoner will check to see if the time it has spent doing the single check is
 *  longer than the value returned by this method. If this is the case, the reasoner will
 *  throw a TimeOutException in the thread that is executing the reasoning process.
 *
 *  Note that clients that want a higher level timeout, at the level of classification for
 *  example, should start their own timers and request that the reasoner interrupts the current
 *  process using the interrupt() method.
 *
 *  @return The time out in milliseconds for basic reasoner operation.
 *      By default this is the value of Long.MAX_VALUE.
 */
AInt
func AOwlReasoner_GetTimeOut(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node (AOwlClass) corresponding to the top node
 *  (containing owl:Thing) in the class hierarchy.
 *
 *  @return A Node containing owl:Thing that is the top node in the class hierarchy.
 *      This Node is essentially equal to the Node returned by calling
 *      GetEquivalentClasses(AOwlClassExpression) with a parameter of owl:Thing.
 */
AOwlNode
func AOwlReasoner_GetTopClassNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node (AOwlDataProperty) corresponding to the top node
 *  (containing owl:topDataProperty) in the data property hierarchy.
 *
 *  @return A Node, containing owl:topDataProperty, that is the top node in the data property
 *      hierarchy. This Node is essentially equal to the Node returned by calling
 *      GetEquivalentDataProperties(org.semanticweb.owlapi.model.OWLDataProperty)
 *      with a parameter of owl:topDataProperty.
 */
AOwlNode
func AOwlReasoner_GetTopDataPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the Node (AOwlObjectPropertyExpression) corresponding to the top node
 *  (containing owl:topObjectProperty) in the object property hierarchy.
 *
 *  @return A Node containing owl:topObjectProperty that is the top node in the object
 *      property hierarchy. This Node is essentially equivalent to the Node returned by
 *      calling GetEquivalentObjectProperties(AOwlObjectPropertyExpression) with a
 *      parameter of owl:topObjectProperty.
 */
AOwlNode
func AOwlReasoner_GetTopObjectPropertyNode(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Gets the named classes (AOwlClass) which are (potentially direct) types of the
 *  specified named individual.
 *
 *  The classes are returned as a NodeSet.
 *
 *  @param ind - The individual whose types are to be retrieved.
 *  @param direct - Specifies if the direct types should be retrieved (true), or if all types
 *      should be retrieved (false).
 *  @return If direct is true, a NodeSet containing named classes such that for each named class C
 *      in the node set, the set of reasoner axioms entails DirectClassAssertion(C, ind).
 *  @return If direct is false, a NodeSet containing named classes such that for each named class C
 *      in the node set, the set of reasoner axioms entails ClassAssertion(C, ind).
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root ontology is inconsistent
 *  @return FreshEntitiesException (-3) - if the signature of the individual is not contained within the
 *      signature of the imports closure of the root ontology and the undeclared entity
 *      policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException - if the reasoner timed out during a basic reasoning
 *      operation. See getTimeOut().
 */
AOwlNodeSet
func AOwlReasoner_GetTypes(AOwlReasoner OwlReasoner, AOwlNamedIndividual ind, ABoolean direct)
{
	return 0;
}

/** A convenience method that obtains the classes (AOwlClass) in the signature of the root
 *  ontology that are unsatisfiable.
 *
 *  @return A Node that is the bottom node in the class hierarchy. This node
 *      represents owl:Nothing and contains owl:Nothing itself plus classes that are
 *      equivalent to owl:Nothing.
 */
AOwlNode
func AOwlReasoner_GetUnsatisfiableClasses(AOwlReasoner OwlReasoner)
{
	return 0;
}

/** Asks the reasoner to interrupt what it is currently doing.
 *
 *  An ReasonerInterruptedException will be thrown in the thread that invoked the last reasoner
 *  operation. The AOwl is not thread safe in general, but it is likely that this method
 *  will be called from another thread than the event dispatch thread or the thread in
 *  which reasoning takes place. Note that the reasoner will periodically check for interupt
 *  requests. Asking the reasoner to interrupt the current process does not mean that it
 *  will be interrupted immediately. However, clients can expect to be able to interupt
 *  individual consistency checks, satisfiability checks etc.
 *
 *  @return AError value
 */
AError
func AOwlReasoner_Interrupt(AOwlReasoner OwlReasoner)
{
	return -1;
}

/** Determines if the set of reasoner axioms is consistent.
 *
 *  Note that this method will NOT throw an InconsistentOntologyException even if the
 *  root ontology imports closure is inconsistent.
 *
 *  @return true if the imports closure of the root ontology is consistent,
 *      or false if the imports closure of the root ontology is inconsistent.
 *  @return ReasonerInterruptedException (-2) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process).
 *  @return TimeOutException (-3) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AError
func AOwlReasoner_IsConsistent(AOwlReasoner OwlReasoner)
{
	return -1;
}

/** A convenience method that determines if the specified axiom is entailed by the
 *  set of reasoner axioms.
 *
 *  @param axiom - The axiom
 *  @return true if axiom is entailed by the reasoner axioms or false if axiom is not entailed
 *      by the reasoner axioms. true if the set of reasoner axioms is inconsistent.
 *  @return FreshEntitiesException (-2) - if the signature of the axiom is not contained within
 *      the signature of the imports closure of the root ontology.
 *  @return ReasonerInterruptedException (-3) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-4) - if the reasoner timed out during a basic reasoning
 *      operation. See getTimeOut().
 *  @return UnsupportedEntailmentTypeException (-5) - if the reasoner cannot perform a check to
 *      see if the specified axiom is entailed
 *  @return AxiomNotInProfileException (-6) - if axiom is not in the profile that is supported by
 *      this reasoner.
 *  @return InconsistentOntologyException (-7) - if the set of reasoner axioms is inconsistent
 *  @see IsEntailmentCheckingSupported(AOwlAxiomType)
 */
AError
func AOwlReasoner_IsEntailed(AOwlReasoner OwlReasoner, AOwlAxiom Axiom)
{
	return -1;
}

/** Determines if the specified set of axioms is entailed by the reasoner axioms.
 *
 *  @param axioms - The set of axioms to be tested
 *  @return true if the set of axioms is entailed by the axioms in the imports closure of the root
 *      ontology, otherwise false. If the set of reasoner axioms is inconsistent then true.
 *  @return FreshEntitiesException (-2) - if the signature of the set of axioms is not contained
 *      within the signature of the imports closure of the root ontology and the undeclared
 *      entity policy of this reasoner is set to FreshEntityPolicy.DISALLOW.
 *  @return ReasonerInterruptedException (-3) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-4) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 *  @return UnsupportedEntailmentTypeException (-5) - if the reasoner cannot perform a check to
 *      see if the specified axiom is entailed
 *  @return AxiomNotInProfileException (-6) - if axiom is not in the profile that is
 *      supported by this reasoner.
 *  @return InconsistentOntologyException (-7) - if the set of reasoner axioms is inconsistent
 *  @see IsEntailmentCheckingSupported(AOwlAxiomType)
 */
AError
func AOwlReasoner_IsEntailed2(AOwlReasoner OwlReasoner, AOwlAxiomSet Axioms)
{
	return -1;
}

/** Determines if entailment checking for the specified axiom type is supported.
 *
 *  @param axiomType - The axiom type
 *  @return true if entailment checking for the specified axiom type is supported, otherwise false.
 *      If true then asking IsEntailed(AOwlAxiom) will not throw an exception of
 *      UnsupportedEntailmentTypeException. If false then asking IsEntailed(AOwlAxiom) will
 *      throw an UnsupportedEntailmentTypeException.
 */
AError
func AOwlReasoner_IsEntailmentCheckingSupported(AOwlReasoner OwlReasoner, AOwlAxiomType AxiomType)
{
	return -1;
}

/** Determines if a specific set of inferences have been precomputed.
 *
 *  @param InferenceType - The type of inference to check for.
 *  @return true if the specified type of inferences have been precomputed, otherwise false.
 */
AError
func AOwlReasoner_IsPrecomputed(AOwlReasoner OwlReasoner, AOwlInferenceType InferenceType)
{
	return -1;
}

/** A convenience method that determines if the specified class expression is satisfiable
 *  with respect to the reasoner axioms.
 *
 *  @param classExpression - The class expression
 *  @return true if classExpression is satisfiable with respect to the set of axioms,
 *      or false if classExpression is unsatisfiable with respect to the axioms.
 *  @return InconsistentOntologyException (-2) - if the set of reasoner axioms is inconsistent
 *  @return ClassExpressionNotInProfileException (-3) - if classExpression is not within the
 *      profile that is supported by this reasoner.
 *  @return FreshEntitiesException (-4) - if the signature of the classExpression is not
 *      contained within the signature of the set of reasoner axioms.
 *  @return ReasonerInterruptedException (-5) - if the reasoning process was interrupted for any
 *      particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-6) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
ABoolean
func AOwlReasoner_IsSatisfiable(AOwlReasoner OwlReasoner, AOwlClassExpression ClassExpression)
{
	return AFalse;
}

/** Asks the reasoner to precompute certain types of inferences.
 *
 *  Note that it is NOT necessary to call this method before asking any other queries - the
 *  reasoner will answer all queries correctly regardless of whether inferences are
 *  precomputed or not. For example, if the imports closure of the root ontology entails
 *  SubClassOf(A B) then the result of getSubClasses(B) will contain A, regardless of
 *  whether PrecomputeInferences(AOwlInferenceType_ClassHierarchy) has been called.
 *  If the reasoner does not support the precomputation of a particular type of inference
 *  then it will silently ignore the request.
 *
 *  @param inferenceTypes - Suggests a list of the types of inferences that should be
 *      precomputed. If the list is empty then the reasoner will determine which types of
 *      inferences are precomputed. Note that the order of the list is unimportant - the
 *      reasoner will determine the order in which inferences are computed.
 *  @return InconsistentOntologyException (-2) - if the imports closure of the root
 *      ontology is inconsistent
 *  @return ReasonerInterruptedException (-3) - if the reasoning process was interrupted
 *      for any particular reason (for example if reasoning was cancelled by a client process)
 *  @return TimeOutException (-4) - if the reasoner timed out during a basic reasoning
 *      operation. See GetTimeOut().
 */
AError
func AOwlReasoner_PrecomputeInferences(AOwlReasoner OwlReasoner, AOwlInferenceTypeSet inferenceTypes)
{
	return -1;
}

