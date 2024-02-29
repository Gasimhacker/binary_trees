#include "binary_trees.h"

/**
 * bst_insert - Insert a value in a Binary Search Tree
 * @tree: A pointer to pointer to the root node of the tree
 * @value: The value to store in the node to be inserted
 *
 * Return: On success - A pointer to the created node m
 *	   On failure - NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	if (value > (*tree)->n && (*tree)->right == NULL)
	{
		new = (binary_tree_node(*tree, value));
		(*tree)->right = new;
	}
	else if (value > (*tree)->n)
		return (bst_insert(&((*tree)->right), value));
	else if (value < (*tree)->n && (*tree)->left == NULL)
	{
		new = (binary_tree_node(*tree, value));
		(*tree)->left = new;
	}
	else if (value < (*tree)->n)
		return (bst_insert(&((*tree)->left), value));
	return (new);
}
