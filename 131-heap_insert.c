#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (
		1 +
		binary_tree_size(tree->left) +
		binary_tree_size(tree->right)
	);
}

/**
 * get_parent - Finds the parent of the new node to insert
 * @root: Pointer to root of the tree
 * @size: Size of the tree before insertion
 * Return: Pointer to the parent node
 */
heap_t *get_parent(heap_t *root, size_t size)
{
	heap_t *parent = root;
	size_t path[64], depth = 0, i;

	while (size > 1)
	{
		path[depth++] = size % 2;
		size /= 2;
	}

	for (i = depth - 1; i > 0; i--)
	{
		if (path[i] == 0)
			parent = parent->left;
		else
			parent = parent->right;
	}

	return (parent);
}

/**
 * heapify_up - Swaps values up to maintain max-heap property
 * @node: Pointer to inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = get_parent(*root, size + 1);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);
	return (new_node);
}

