#include "binary_trees.h"
#include <stdlib.h> /* for abs() */
#include <limits.h> /* for INT_MIN and INT_MAX */

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The greater of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree. If tree is NULL, returns 0
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum valid value for the current subtree
 * @max: Maximum valid value for the current subtree
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	/* Check if it’s a valid BST */
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	lh = height(tree->left);
	rh = height(tree->right);

	/* Check AVL balance condition */
	if (abs(lh - rh) > 1)
		return (0);

	/* Recursively check if left and right subtrees are AVL */
	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);
	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

