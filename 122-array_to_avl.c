#include "binary_trees.h"

/**
 * avl_delete - Delete an entire AVL tree. If tree is NULL, do nothing.
 * @tree: A pointer to the root node of the AVL tree to delete
 * Return: Void
 */
void avl_delete(avl_t *tree)
{
	avl_t *left, *right;

	if (tree == NULL)
		return;
	left = tree->left;
	right = tree->right;
	free(tree);
	avl_delete(left);
	avl_delete(right);
}

/**
 * array_to_avl - Build an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The  number of element in the array
 *
 * Return: On success - A pointer to the root node of the created AVL tree
 *	   On failure - NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			for (j = 0; j < i; j++)
				if (array[j] == array[i])
					break;
			if (i == j)
			{
				if (root)
					avl_delete(root);
				return (NULL);
			}
		}
	}
	return (root);
}
