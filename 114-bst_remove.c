#include "binary_trees.h"

/**
 * delete_node - Delete the current node in the BST
 * @node: A pointer to the node to be deleted
 *
 * Return: A pointer to the new root node
 */
bst_t *delete_node(bst_t *node)
{
	bst_t *temp, *succ_parent, *succ;

	if (node->left == NULL)
	{
		temp = node->right;
		if (node->right)
			node->right->parent = node->parent;
		free(node);
		return (temp);
	}
	else if (node->right == NULL)
	{
		temp = node->left;
		if (node->left)
			node->left->parent = node->parent;
		free(node);
		return (temp);
	}
	else
	{
		succ_parent = node;
		succ = node->right;
		while (succ->left != NULL)
		{
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent != node)
			succ_parent->left = succ->right;
		else
			succ_parent->right = succ->right;
		if (succ->right)
			succ->right->parent = succ_parent;
		node->n = succ->n;
		free(succ);
	}
	return (node);
}

/**
 * bst_remove - Remove a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree
 *	   after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (root);
	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	else if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}
	return (delete_node(root));
}
