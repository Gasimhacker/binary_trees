#include "binary_trees.h"

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: A double pointer to the root node of the AVL tree to insert into
 * @parent: The parent node of the current working node
 * @new: A double pointer to store the new node
 * @value: The value to insert into the AVL tree
 *
 * Return: A pointer to the new root after insertion, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int balance;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = (avl_insert_recursive(&((*tree)->right),
					*tree, new, value));
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	balance = binary_tree_balance(*tree);
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
	return (*tree);
}

/**
 * avl_insert - Insert a value in a AVL Tree
 * @tree: A pointer to pointer to the root node of the tree
 * @value: The value to store in the node to be inserted
 *
 * Return: On success - A pointer to the created node
 *	   On failure - NULL
 */
avl_t *avl_insert(bst_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
