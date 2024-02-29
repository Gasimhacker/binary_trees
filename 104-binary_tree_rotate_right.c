#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotate a binary tree to the right
 * @tree: A pointer to the node to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *l, *p;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	l = tree->left;
	p = tree->parent;

	tree->left = l->right;
	if (l->right)
		l->right->parent = tree;
	l->right = tree;
	tree->parent = l;
	l->parent = p;

	if (p)
	{
		if (p->left == tree)
			p->left = l;
		else
			p->right = l;
	}
	return (l);
}
