#include "binary_trees.h"

/**
 * rebalance_tree - Return the tree to the balanced state
 * @tree: A double pointer to the unbalanced tree
 * @value: The new inserted value
 *
 * Return: void
 */
void rebalance_tree(avl_t **tree, int value)
{
	int balance = binary_tree_balance(*tree);

	if (balance > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * avl_insert - Insert a value in an AVL Tree
 * @tree: A pointer to pointer to the root node of the tree
 * @value: The value to store in the node to be inserted
 *
 * Return: On success - A pointer to the created node m
 *	   On failure - NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	if (value > (*tree)->n && (*tree)->right == NULL)
	{
		new = (binary_tree_node(*tree, value));
		(*tree)->right = new;
	}
	else if (value > (*tree)->n)
		new = (avl_insert(&((*tree)->right), value));
	else if (value < (*tree)->n && (*tree)->left == NULL)
	{
		new = (binary_tree_node(*tree, value));
		(*tree)->left = new;
	}
	else if (value < (*tree)->n)
		new = (avl_insert(&((*tree)->left), value));
	rebalance_tree(tree, value);
	return (new);
}
