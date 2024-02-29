#include "binary_trees.h"

/**
 * create_node - Create a `queue_t` node
 * @node: The binary_tree_t node to be inserted in the `queue_t` node
 *
 * Return: A pointer to the created node or NULL if failed
 */
queue_t *create_node(binary_tree_t *node)
{
	queue_t *new;

	new = malloc(sizeof(queue_t));
	if (new == NULL)
		return (new);
	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * pop - Pop the head of the queue
 * @head: A pointer to the head of the queue
 *
 * Return: void
 */
void pop(queue_t **head)
{
	queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * free_queue - Free a `queue_t` queue
 * @head: A pointer to the head of the queue
 *
 * Return: void
 */
void free_queue(queue_t *head)
{
	while (head)
		pop(&head);
}

/**
 * push - Push a node into the queue
 * @head: A pointer to the head of the queue
 * @tail: A pointer to the tail of the queue
 * @bt_node: The node of the binary tree to be
 *	     inserted into the queue's node
 *
 * Return: Void
 */
void push(queue_t *head, queue_t **tail, binary_tree_t *bt_node)
{
	queue_t *new = create_node(bt_node);

	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	new->node = bt_node;
	(*tail)->next = new;
	*tail = new;
}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If it is a complete binary tree
 *	   0 - Otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *head, *tail;
	unsigned char is_null_found = 0;

	if (tree == NULL)
		return (0);
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);
	while (head)
	{
		if (head->node->left)
		{
			if (is_null_found)
			{
				free_queue(head);
				return (0);
			}
			push(head, &tail, head->node->left);
		}
		else
			is_null_found = 1;
		if (head->node->right)
		{
			if (is_null_found)
			{
				free_queue(head);
				return (0);
			}
			push(head, &tail, head->node->right);
		}
		else
			is_null_found = 1;
		pop(&head);
	}
	return (1);
}
