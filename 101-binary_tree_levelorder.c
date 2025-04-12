#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_node - Queue node for holding binary_tree_t pointers
 * @node: The tree node
 * @next: Pointer to the next queue node
 */
typedef struct queue_node
{
	binary_tree_t *node;
	struct queue_node *next;
} queue_node_t;

/**
 * enqueue - Adds a new node to the end of the queue
 * @tail: Double pointer to the tail of the queue
 * @node: Tree node to enqueue
 */
void enqueue(queue_node_t **tail, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));
	if (!new_node)
		return;
	new_node->node = node;
	new_node->next = NULL;
	if (*tail)
		(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * dequeue - Removes a node from the front of the queue
 * @head: Double pointer to the head of the queue
 * Return: The dequeued tree node
 */
binary_tree_t *dequeue(queue_node_t **head)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (!head || !*head)
		return (NULL);
	temp = *head;
	node = temp->node;
	*head = (*head)->next;
	free(temp);
	return (node);
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Function to call for each node’s value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_node_t *head = NULL, *tail = NULL;
	binary_tree_t *current;

	if (!tree || !func)
		return;

	enqueue(&tail, (binary_tree_t *)tree);
	head = tail;

	while (head)
	{
		current = dequeue(&head);
		func(current->n);
		if (current->left)
			enqueue(&tail, current->left);
		if (current->right)
			enqueue(&tail, current->right);
	}
}

