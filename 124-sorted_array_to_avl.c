#include "binary_trees.h"

/**
 * sorted_array_to_avl - Build an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0 || array == NULL)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);
	if (root == NULL)
		return (NULL);
	root->left = sorted_array_to_avl(array, middle);
	if (root->left)
		root->left->parent = root;
	root->right = sorted_array_to_avl(array + middle + 1, size / 2);
	if (root->right)
		root->right->parent = root;

	return (root);
}
