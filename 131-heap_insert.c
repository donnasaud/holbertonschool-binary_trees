#include "binary_trees.h"
#include <stdlib.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height or 0 if NULL
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);
	return ((left > right ? left : right) + 1);
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root
 * Return: 1 if perfect, 0 otherwise
 */
static int is_perfect(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (!tree->left || !tree->right)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return (left_h == right_h &&
		is_perfect(tree->left) &&
		is_perfect(tree->right));
}

/**
 * insert_node - Recursively inserts a new node in the proper place
 * @root: Pointer to current root
 * @value: Value to insert
 * Return: Pointer to inserted node
 */
static heap_t *insert_node(heap_t *root, int value)
{
	heap_t *inserted = NULL;

	if (!root->left)
	{
		root->left = binary_tree_node(root, value);
		inserted = root->left;
	}
	else if (!root->right)
	{
		root->right = binary_tree_node(root, value);
		inserted = root->right;
	}
	else if (!is_perfect(root))
		inserted = insert_node(root->left, value);
	else
		inserted = insert_node(root->right, value);

	while (inserted && inserted->parent && inserted->n > inserted->parent->n)
	{
		int tmp = inserted->n;

		inserted->n = inserted->parent->n;
		inserted->parent->n = tmp;
		inserted = inserted->parent;
	}

	return (inserted);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	return (insert_node(*root, value));
}

