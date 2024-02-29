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
 * binary_tree_levelorder - Go through a binary tree using
 *			    level-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head, *tail;

	if (!tree || !func)
		return;
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;
	while (head)
	{
		func(head->node->n);
		if (head->node->left)
			push(head, &tail, head->node->left);
		if (head->node->right)
			push(head, &tail, head->node->right);
		pop(&head);
	}
}
