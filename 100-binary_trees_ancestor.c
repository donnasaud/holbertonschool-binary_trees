#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node
 * @node: pointer to the node to measure depth
 * Return: depth from the root
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node && node->parent)
	{
		node = node->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to lowest common ancestor, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d1, d2;

	if (!first || !second)
		return (NULL);

	d1 = binary_tree_depth(first);
	d2 = binary_tree_depth(second);

	/* Align both nodes at the same depth */
	while (d1 > d2)
	{
		first = first->parent;
		d1--;
	}
	while (d2 > d1)
	{
		second = second->parent;
		d2--;
	}

	/* Move both up until they meet */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

