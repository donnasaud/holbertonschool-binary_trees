#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Checks if a binary tree is a valid BST
 * @tree: pointer to the node
 * @min: minimum allowed value
 * @max: maximum allowed value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: pointer to the root node
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	left_h = (int)binary_tree_height(tree->left);
	right_h = (int)binary_tree_height(tree->right);

	if (abs(left_h - right_h) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}

