#include "binary_trees.h"

/**
 * tree_size - Calculate the size of the tree
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: Size or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Convert a Binary Max Heap
 *			  to a sorted array of integers
 *
 * @heap: A pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: A pointer to array sorted in descending order
 *	   NULL On failure
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap);

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
