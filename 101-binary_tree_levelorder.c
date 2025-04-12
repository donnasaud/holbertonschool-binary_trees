#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Function to call for each node’s value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0, size = 0;

	if (!tree || !func)
		return;

	/* Allocate initial space for the queue */
	size = 1024;
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}

