#include "binary_trees.h"

/**
 * bst_delete - Delete an entire BST. If tree is NULL, do nothing.
 * @tree: A pointer to the root node of the BST to delete
 * Return: Void
 */
void bst_delete(bst_t *tree)
{
	bst_t *left, *right;

	if (tree == NULL)
		return;
	left = tree->left;
	right = tree->right;
	free(tree);
	bst_delete(left);
	bst_delete(right);
}

/**
 * array_to_bst - Build a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The  number of element in the array
 *
 * Return: On success - A pointer to the root node of the created BST
 *	   On failure - NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i, j;
	bst_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			for (j = 0; j < i; j++)
				if (array[j] == array[i])
					break;
			if (i == j)
			{
				if (root)
					bst_delete(root);
				return (NULL);
			}
		}
	}
	return (root);
}
