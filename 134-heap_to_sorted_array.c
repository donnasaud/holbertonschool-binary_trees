#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to sorted array
 * @heap: Pointer to the root node
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, heap_size;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	array = malloc(sizeof(int) * heap_size);
	if (!array)
		return (NULL);

	for (i = 0; i < heap_size; i++)
		array[i] = heap_extract(&heap);

	*size = heap_size;
	return (array);
}

