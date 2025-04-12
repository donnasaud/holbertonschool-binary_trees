#include "binary_trees.h"
#include <stdlib.h>

/**
 * level_order_insert - Inserts a node in level-order fashion
 * @tree: Pointer to current node
 * @value: Value to insert
 * Return: Pointer to newly inserted node
 */
static heap_t *level_order_insert(heap_t *tree, int value)
{
	heap_t *new = NULL;
	heap_t *queue[1024];
	int front = 0, rear = 0;
	heap_t *current;

	if (!tree)
		return (NULL);

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];

		if (!current->left)
		{
			current->left = binary_tree_node(current, value);
			new = current->left;
			break;
		}
		else
			queue[rear++] = current->left;

		if (!current->right)
		{
			current->right = binary_tree_node(current, value);
			new = current->right;
			break;
		}
		else
			queue[rear++] = current->right;
	}

	return (new);
}

/**
 * heapify_up - Restores the Max Heap order by swapping up
 * @node: Pointer to the inserted node
 * Return: Pointer to final position
 */
static heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *inserted;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	inserted = level_order_insert(*root, value);
	if (!inserted)
		return (NULL);

	return (heapify_up(inserted));
}

