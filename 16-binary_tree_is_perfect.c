#include "binary_trees.h"

/**
 * recursive_is_perfect - Check if a binary tree is perfect using recursion
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If it is a perfect binary tree
 *	   0 - Otherwise
 */
int recursive_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if ((tree->left == NULL) != (tree->right == NULL))
		return (0);
	if (tree->left == NULL)
		return (1);
	if ((tree->left->left == NULL) != (tree->right->left == NULL))
		return (0);
	return (recursive_is_perfect(tree->left) &&
			recursive_is_perfect(tree->right));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If it is a perfect binary tree
 *	   0 - Otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_is_perfect(tree));
}
