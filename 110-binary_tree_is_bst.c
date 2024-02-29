#include "binary_trees.h"

/**
 * recursive_is_bst - Check if a binary tree is a BST using recursion
 * @tree: A pointer a pointer to the root node of the tree to check
 * @max: The maximum value that should be in the current node (excluded)
 * @min: The minimum value that should be in the current node (excluded)
 *
 * Return: If the binary tree is BST - 1
 *	   Otherwise - 0
 */
int recursive_is_bst(const binary_tree_t *tree, int max, int min)
{
	if (tree == NULL ||
		(tree->n < max && tree->n > min
		&& recursive_is_bst(tree->left, tree->n, min)
		&& recursive_is_bst(tree->right, max, tree->n)))
		return (1);
	return (0);
}

/**
 * binary_tree_is_bst - Check if a binary tree is a BST
 * @tree: A pointer a pointer to the root node of the tree to check
 *
 * Return: If the binary tree is BST - 1
 *	   Otherwise - 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_is_bst(tree, INT_MAX, INT_MIN));
}
