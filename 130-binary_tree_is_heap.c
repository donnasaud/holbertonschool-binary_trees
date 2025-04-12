#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node.
 *
 * Return: Number of nodes.
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node.
 * @index: Index of the current node.
 * @total_nodes: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes)
{
	if (!tree)
		return (1);
	if (index >= total_nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, total_nodes) &&
		is_complete(tree->right, 2 * index + 2, total_nodes));
}

/**
 * is_max_heap - Checks if the tree satisfies the Max-Heap property.
 * @tree: Pointer to the root node.
 *
 * Return: 1 if it's a valid Max-Heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left)
	{
		if (tree->n < tree->left->n || !is_max_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (tree->n < tree->right->n || !is_max_heap(tree->right))
			return (0);
	}

	return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t total_nodes;

	if (!tree)
		return (0);

	total_nodes = count_nodes(tree);

	if (!is_complete(tree, 0, total_nodes))
		return (0);

	return (is_max_heap(tree));
}


