#include "binary_trees.h"

/**
 * heapify_up - Reorders nodes to maintain heap property after insertion.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root.
 * Return: Size (number of nodes).
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_insert_parent - Finds the parent where the new node should be inserted.
 * @root: Pointer to the root node.
 * @index: Index of the new node in level order.
 * Return: Pointer to the parent node.
 */
heap_t *get_insert_parent(heap_t *root, size_t index)
{
	size_t path[64], depth = 0;
	heap_t *parent = root;
	size_t i;

	while (index > 1)
	{
		path[depth++] = index % 2;
		index /= 2;
	}

	for (i = depth - 1; i > 0; i--)
		parent = (path[i] == 0) ? parent->left : parent->right;

	return (parent);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: Double pointer to root node.
 * @value: Value to insert.
 * Return: Pointer to created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	size_t index;

	if (!root)
		return (NULL);

	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	index = tree_size(*root) + 1;
	parent = get_insert_parent(*root, index);
	if (!parent)
		return (NULL);

	if (!(index % 2))
		parent->left = binary_tree_node(parent, value);
	else
		parent->right = binary_tree_node(parent, value);

	new = (index % 2) ? parent->right : parent->left;

	if (!new)
		return (NULL);

	heapify_up(new);

	return (new);
}

