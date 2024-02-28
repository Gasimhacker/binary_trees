#include "binary_trees.h"

/**
 * recursive_is_full - Check if a binary tree is full using recursion
 *
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If a binary tree is full
 *	   0 - Otherwise
 */
int recursive_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if ((tree->left && tree->right == NULL)
			|| (tree->left == NULL && tree->right)
			|| recursive_is_full(tree->left) == 0
			|| recursive_is_full(tree->right) == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_full - Check if a binary tree is full
 *
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If a binary tree is full
 *	   0 - Otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_is_full(tree));
}
