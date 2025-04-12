#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps values between two heap nodes
 * @a: first node
 * @b: second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

/**
 * get_insert_position - Finds the first available spot using BFS
 * @root: root of the heap
 * Return: pointer to parent where new node can be inserted
 */
heap_t *get_insert_position(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *curr = queue[front++];

		if (!curr->left || !curr->right)
			return (curr);

		queue[rear++] = curr->left;
		queue[rear++] = curr->right;
	}

	return (NULL);
}

/**
 * bubble_up - Restores the heap after insertion by swapping
 * @node: node to start bubbling from
 */
void bubble_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a new value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 * Return: Pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = get_insert_position(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	bubble_up(new_node);

	return (new_node);
}

