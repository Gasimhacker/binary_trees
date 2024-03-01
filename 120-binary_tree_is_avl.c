#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + height(tree->left) : 1;
	height_r = tree->right ? 1 + height(tree->right) : 1;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * recursive_is_avl - Check if a binary tree is a AVL using recursion
 * @tree: A pointer a pointer to the root node of the tree to check
 * @max: The maximum value that should be in the current node (excluded)
 * @min: The minimum value that should be in the current node (excluded)
 *
 * Return: If the binary tree is AVL - 1
 *	   Otherwise - 0
 */
int recursive_is_avl(const binary_tree_t *tree, int max, int min)
{
	size_t l_height, r_height, diff;

	if (tree == NULL)
		return (1);
	if (tree->n < max && tree->n > min)
	{
		l_height = height(tree->left);
		r_height = height(tree->right);

		diff = l_height > r_height ? l_height - r_height : r_height - l_height;

		if (diff > 1)
			return (0);
		return (recursive_is_avl(tree->left, tree->n, min)
			&& recursive_is_avl(tree->right, max, tree->n));
	}
	return (0);
}

/**
 * binary_tree_is_avl - Check if a binary tree is a AVL
 * @tree: A pointer a pointer to the root node of the tree to check
 *
 * Return: If the binary tree is AVL - 1
 *	   Otherwise - 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_is_avl(tree, INT_MAX, INT_MIN));
}
