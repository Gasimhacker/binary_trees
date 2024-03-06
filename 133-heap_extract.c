#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_left_height - Count the height to the leftmost child
 * @node: A pointer to the root node
 *
 * Return: The height to the leftmost child
 */
int get_left_height(heap_t *node)
{
	int c = 0;

	if (node == NULL)
		return (0);
	while (node->left)
	{
		c++;
		node = node->left;
	}
	return (c);
}

/**
 * get_right_most_element - Find the last element in a complete binary tree
 * @node: A pointer to the root node
 *
 * Return: A pointer to the last node in the complete binary tree
 */
heap_t *get_right_most_element(heap_t *node)
{
	int h = get_left_height(node);

	if (h == 0)
		return (node);
	else if (node->right && (h - 1) == get_left_height(node->right))
		return (get_right_most_element(node->right));
	else
		return (get_right_most_element(node->left));
}

/**
 * heapify - Heapify max binary heap
 * @root: A pointer to binary heap
 *
 * Return: void
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - Extract the root node from a Max Binary Heap
 * @root: A pointer to the heap root
 *
 * Return: The value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	node = get_right_most_element(heap_r);

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	return (value);
}
