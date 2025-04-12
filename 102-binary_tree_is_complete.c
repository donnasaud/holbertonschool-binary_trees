#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node.
 *
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0, size = 1024;
	int null_seen = 0;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current)
		{
			if (null_seen)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
		else
			null_seen = 1;
	}

	free(queue);
	return (1);
}

