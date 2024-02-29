#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotate a binary tree to the left
 * @tree: A pointer to the node to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r, *p;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	r = tree->right;
	p = tree->parent;

	tree->right = r->left;
	if (r->left)
		r->left->parent = tree;
	r->left = tree;
	tree->parent = r;
	r->parent = p;

	if (p)
	{
		if (p->left == tree)
			p->left = r;
		else
			p->right = r;
	}
	return (r);
}
