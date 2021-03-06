/* AOwlNodeSet functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 14.06.2012
 * LastMod 16.07.2012
 * Version 0.0

 * Prototype: OwlApi
 * http://sourceforge.net/projects/owlapi/
 * http://owlapi.sourceforge.net/
 */

#include "AOwl"

// --- NodeSet ---

/** A convenience method that determines if this NodeSet contains a specific entity.
 *
 *  @param Entity - The entity to test for
 *
 *  @return true if this NodeSet contains a Node that contains the entity, and false if
 *      this NodeSet does not contain a Node that contains the entity.
 */
ABoolean
func AOwlNodeSet_ContainsEntity(AOwlNodeSet NodeSet, AOwlEntity Entity)
{
	return AFalse;
}

/** A convenience method that gets all of the entities contained in the Nodes in this NodeSet.
 *
 *  @return The union of the entities contained in the Nodes in this NodeSet.
 */
AOwlEntitySet
func AOwlNodeSet_GetFlattened(AOwlNodeSet NodeSet)
{
	return 0;
}

/** Return entity iterator */
AOwlEntityIterator
func AOwlNodeSet_GetIteartor(AOwlNodeSet NodeSet)
{
	return 0;
}

/** Gets the Nodes (AOwlNode) contained in this NodeSet.
 *  @return The set of Nodes contained in this NodeSet. Note that this set will be an
 *      unmodifiable set.
 */
AOwlEntitySet
func AOwlNodeSet_GetNodes(AOwlNodeSet NodeSet)
{
	return 0;
}

/** Determies if this NodeSet is a singleton that only contains the bottom node (in a hierarchy).
 *  @return true if this NodeSet is a singleton that only contains a node that is the bottom node,
 *      otherwise false
 *  @see AOwlNode_IsBottomNode()
 */
ABoolean
func AOwlNodeSet_IsBottomSingleton(AOwlNodeSet NodeSet)
{
	return AFalse;
}

ABoolean
func AOwlNodeSet_IsEmpty(AOwlNodeSet NodeSet)
{
	return AFalse;
}

/** Determines if this NodeSet is a singleton.
 *  A NodeSet is a singleton if it contains only one Node.
 *  @return true if this NodeSet is a singleton, otherwise false.
 */
ABoolean
func AOwlNodeSet_IsSingleton(AOwlNodeSet NodeSet)
{
	return AFalse;
}

/** Determines if this NodeSet is a singleton node that only contains the top node (in a hierarchy).
 *  Returns: true if this NodeSet is a singleton that contains only the top node, and false otherwise.
 *  @see Also: AOwlNode_IsTopNode()
 */
ABoolean
func AOwlNodeSet_IsTopSingleton(AOwlNodeSet NodeSet)
{
	return AFalse;
}
