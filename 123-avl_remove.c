#include "binary_trees.h"

/**
 * rebalance_tree - Return the tree to the balanced state
 * @tree: A double pointer to the unbalanced tree
 * @value: The new inserted value
 *
 * Return: A pointer to the new root
 */
avl_t *rebalance(avl_t *tree)
{
	int balance = binary_tree_balance(tree);

	if (balance > 1 && tree->left->left)
		tree = binary_tree_rotate_right(tree);
	else if (balance < -1 && tree->right->right)
		tree = binary_tree_rotate_left(tree);
	else if (balance > 1 && tree->left->right)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (balance < -1 && tree->right->left)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		tree = binary_tree_rotate_left(tree);
	}
	return (tree);
}

/**
 * delete_node - Delete the current node in the AVL tree
 * @node: A pointer to the node to be deleted
 *
 * Return: A pointer to the new root node
 */
avl_t *delete_node(avl_t *node)
{
	avl_t *temp, *succ_parent, *succ;

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
 * avl_remove - Remove a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree
 *	   after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (root);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
		root = delete_node(root);
	root = rebalance(root);
	return (root);
}
