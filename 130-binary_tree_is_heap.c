#include "binary_trees.h"

/**
 * count_nodes - Count the number of nodes in a binary tree
 * @root: A pointer to the root node of the binary tree
 *
 * Return: The number of nodes in the tree
 */
unsigned int count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Check if a binary tree is a complete binary tree
 * @root: A pointer to the root node of the binary tree
 * @index: The index of the current node
 * @num_nodes: The number of nodes in the tree
 *
 * Return: If the binary tree is a complete binary tree - 1
 *	   Otherwise - 0
 */
int is_complete(const binary_tree_t *root, unsigned int index,
		unsigned int num_nodes)
{
	if (root == NULL)
		return (1);

	if (index >= num_nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, num_nodes)
		&& is_complete(root->right, 2 * index + 2, num_nodes));
}

/**
 * check_max - Check for the max heap property inside a binary tree
 * @tree: A pointer to the root of the tree
 *
 * Return: If the max heap property is satisfied - 1
 *	   Otherwise - 0
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);
	else if ((tree->left && tree->n <= tree->left->n) ||
			(tree->right && tree->n <= tree->right->n))
		return (0);
	else if (tree->left)
		tmp1 = check_max(tree->left);
	if (tree->right)
		tmp2 = check_max(tree->right);
	return (tmp1 && tmp2);
}

/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, count_nodes(tree))
		&& check_max(tree));
}
