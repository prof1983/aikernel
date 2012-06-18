/* OwlOntology functions
 * Author Prof1983 prof1983@ya.ru
 * Created 18.06.2012
 * LastMod 18.06.2012
 * Version 0.0
 *
 * Prototype: org.semanticweb.owlapi.model OWLOntology.java
 */

#include "../AOwl.h"

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
func AOwlOntology_GetAxioms(AOwlOntology Ontology, AOwlClass Cls)
{
	return 0;
}

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
func AOwlOntology_GetAxioms2(AOwlOntology Ontology, AOwlObjectPropertyExpression Prop)
{
	return 0;
}

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
func AOwlOntology_GetAxioms3(AOwlOntology Ontology, AOwlDataProperty Prop)
{
	return 0;
}

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
func AOwnOntology_GetAxioms4(AOwlOntology Ontology, AOwlIndividual Individual)
{
	return 0;
}

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
func AOwlOntology_GetAxioms5(AOwlOntology Ontology, AOwlAnnotationProperty Property)
{
	return 0;
}

/** Gets the datatype definition axioms for the specified datatype
 *
 *  @param Datatype - The datatype
 *  @return The set of datatype definition axioms for the specified datatype
 */
AOwlDatatypeDefinitionAxiomSet
func AOwlOntology_GetAxioms6(AOwlOntology Ontology, AOwlDatatype Datatype)
{
	return 0;
}
