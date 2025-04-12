#include "binary_trees.h"
#include <stdlib.h>

/**
 * min_value_node - Finds the node with the smallest value in a tree
 * @node: Pointer to the root node
 *
 * Return: Pointer to the node with the smallest value
 */
avl_t *min_value_node(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root after deletion and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;

			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			free(temp);
		}
		else
		{
			temp = min_value_node(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (!root)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}

