#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_rebalance - Rebalances an AVL subtree
 * @node: The subtree root to rebalance
 *
 * Return: Pointer to new subtree root after rotation
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance;

	balance = binary_tree_balance(node);

	if (balance > 1 && binary_tree_balance(node->left) >= 0)
		return (binary_tree_rotate_right(node));

	if (balance > 1 && binary_tree_balance(node->left) < 0)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance < -1 && binary_tree_balance(node->right) <= 0)
		return (binary_tree_rotate_left(node));

	if (balance < -1 && binary_tree_balance(node->right) > 0)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		new_node = avl_insert(&(*tree)->left, value);
		if (!new_node)
			return (NULL);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = avl_insert(&(*tree)->right, value);
		if (!new_node)
			return (NULL);
		(*tree)->right->parent = *tree;
	}
	else
		return (NULL); /* No duplicates allowed */

	*tree = avl_rebalance(*tree);

	return (new_node);
}

