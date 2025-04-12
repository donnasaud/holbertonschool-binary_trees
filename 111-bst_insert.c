#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree (BST)
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
			return (bst_insert(&((*tree)->left), value));

		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right != NULL)
			return (bst_insert(&((*tree)->right), value));

		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}

	return (NULL); /* Duplicate value */
}

