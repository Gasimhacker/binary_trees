#include "binary_trees.h"

/**
 * bst_search - Search for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: If the value is found - A pointer to the node containing the value
 *	   Otherwise - NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
