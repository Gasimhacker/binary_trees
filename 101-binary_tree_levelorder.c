#include "binary_trees.h"

/**
 * recursive_levelorder - Go through a binary tree using
 *			  level-order traversal recursively
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void recursive_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	recursive_levelorder(tree->left, func);
	recursive_levelorder(tree->right, func);
}

/**
 * binary_tree_levelorder - Go through a binary tree using
 *			    level-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	recursive_levelorder(tree, func);
}
