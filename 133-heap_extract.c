#include "binary_trees.h"
#include <stdlib.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height
 */
int height(heap_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	return ((left > right ? left : right) + 1);
}

/**
 * get_last_node - Finds the last node in a level-order traversal
 * @root: Pointer to the root node
 * @h: Height to look for
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, int h)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);

	if (h == 1)
		return (root);

	left = get_last_node(root->left, h - 1);
	right = get_last_node(root->right, h - 1);
	return (right ? right : left);
}

/**
 * heapify_down - Fixes the max heap property going downward
 * @root: Pointer to the root node
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temp;

	while (root)
	{
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int h, value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	h = height(*root);
	last = get_last_node(*root, h);

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	(*root)->n = last->n;
	free(last);
	heapify_down(*root);

	return (value);
}

