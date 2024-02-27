#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as the left-child of another node
 *			     If parent already has a left-child, the new
 *			     node must take its place, and the old
 *			     left-child must be set as the left-child
 *			     of the new node.
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node,
 *	   or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	if (parent->left)
	{
		new->left = parent->left;
		new->left->parent = new;
	}
	parent->left = new;

	return (new);
}
