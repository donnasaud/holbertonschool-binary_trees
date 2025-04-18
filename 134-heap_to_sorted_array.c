#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Pointer to store the size of the array
 * Return: Pointer to the array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t count = 0, total;
	
	if (!heap || !size)
		return (NULL);

	/* Get total nodes for allocation */
	total = binary_tree_size(heap);
	array = malloc(sizeof(int) * total);
	if (!array)
		return (NULL);

	while (heap)
		array[count++] = heap_extract(&heap);

	*size = count;
	return (array);
}

