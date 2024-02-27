#include "binary_trees.h"

/**
 * binary_tree_delete - Delete an entire binary tree.
 *			If tree is NULL, do nothing.
 * @tree: A pointer to the root node of the tree to delete
 * Return: Void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return;
	left = tree->left;
	right = tree->right;
	free(tree);
	binary_tree_delete(left);
	binary_tree_delete(right);
}
