/* AOwlNode functions
 * Author(Prof1983 prof1983@ya.ru)
 * Created(14.06.2012)
 * LastMod(14.06.2012)
 * Version(0.0)
 *
 * Prototype: OwlApi
 * http://sourceforge.net/projects/owlapi/
 * http://owlapi.sourceforge.net/
 */

#include "AOwl.h"

// --- Node ---

/** Determines if this node contains the specified entity.
 *
 *  @param Entity - The entity to check for
 *
 *  @return true if this node contains entity, or false if this node does not contain entity
 */
ABoolean
func AOwlNode_Contains(AOwlNode OwlNode, AOwlEntity Entity)
{
	return AFalse;
}

/** Gets the number of entities contained in this Node. */
AInt
func AOwlNode_GetCount()
{
	return 0;
}

/** Gets the entities contained in this node.
 *
 *  The entities are equivalent to each other.
 *
 *  @return The set of entities contained in this Node.
 */
AOwlEntitySet
func AOwlNode_GetEntities(AOwlNode OwlNode)
{
	return 0;
}

/** Gets the entities contained in this node minus the specified entitie.
 *
 *  This essentially returns the entities that are returned by GetEntities() minus the
 *  specified entity.
 *
 *  @param Entity - The entity that, is contained within this node, but should not be included in the
 *      return set.
 *
 *  @return The set of entities that are contained in this node minus the specified entity.
 *      If Entity is not contained within this node then the full set of entities returned is the
 *      same as that returned by GetEntities().
 */
AOwlEntitySet
func AOwlNode_GetEntitiesMinus(AOwlNode OwlNode, AOwlEntity Entity)
{
	return 0;
}

/** Gets the entities contained in this node minus the bottom entity.
 *
 *  For a node of named classes the bottom entity is owl:Nothing.
 *  For a node of object properties the bottom entity is owl:bottomObjectProperty.
 *  For a node of data properties the bottom entity is owl:bottomDataProperty.
 *
 *  @return The set of entities contained within this node minus the bottom entity.
 *      If this node does not contain the bottom entity then the set of entities
 *      returned is the same as that returned by getEntities().
 */
AOwlEntitySet
func AOwlNode_GetEntitiesMinusBottom(AOwlNode OwlNode)
{
	return 0;
}

/** Gets the entities contained in this node minus the top entity.
 *
 *  For a node of named classes the top entity is owl:Thing.
 *  For a node of object properties the top entity is owl:topObjectProperty.
 *  For a node of data properties the top entity is owl:topDataProperty.
 *
 *  @return The set of entities contained within this node minus the top entity.
 *      If this node does not contain the top entity then the set of entities returned is
 *      the same as that returned by GetEntities().
 */
AOwlEntitySet
func AOwlNode_GetEntitiesMinusTop()
{
	return 0;
}

AOwlEntityIterator
func AOwlNode_GetIterator()
{
	return 0;
}

/** Gets one of the entities contained in this entity set.
 *
 *  If this is a singleton set it will be the one and only entity.
 *
 *  @return An entity from the set of entities contained within this node.
 */
AOwlEntity
func AOwlNode_GetRepresentativeElement()
{
	return 0;
}

/** Gets the number of entities contained in this Node.
 *
 *  @deprecated Use GetCount()
 *
 *  @return The number of entities contained in this node.
 */
AInt
func AOwlNode_GetSize()
{
	return AOwlNode_GetCount();
}

/** Determines if this node represents the bottom node (in a hierarchy).
 *
 *  For a named class node, the bottom node is the node that contains owl:Nothing.
 *  For an object property node, the bottom node is the node that contains owl:bottomObjectProperty.
 *  For a data property node, the bottom node is the node that contains owl:bottomDataProperty.
 *
 *  @return true if this node is an OwlClass node and it contains owl:Nothing.
 *  @return true if this node is an OwlObjectProperty node and it contains owl:bottomObjectProperty.
 *  @return true if this node is an OwlDataProperty node and it contains owl:bottomDataProperty.
 *  @return false if none of the above.
 */
ABoolean
func AOwlNode_IsBottomNode()
{
	return AFalse;
}

/** Determines if this Node contains just one entity.
 *
 *  @return true if this Node contains just one entity, otherwise false
 */
ABoolean
func AOwlNode_IsSingleton()
{
	return AFalse;
}

/** Determines if this node represents the top node (in a hierarchy).
 *
 *  For a named class node, the top node is the node that contains owl:Thing.
 *  For an object property node, the top node is the node that contains owl:topObjectProperty.
 *  For a data property node, the top node is the node that contains owl:topDataProperty.
 *
 *  @return true if this node is an OwlClass node and it contains owl:Thing.
 *  @return true if this node is an OwlObjectProperty node and it contains owl:topObjectProperty.
 *  @return true if this node is an OwlDataProperty node and it contains owl:topDataProperty.
 *  @return false if none of the above.
 */
ABoolean
func AOwlNode_IsTopNode()
{
	return AFalse;
}
