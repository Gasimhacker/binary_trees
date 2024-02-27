#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* "Header files" */
#include <stdlib.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/* "Tree types" */
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* "Functions" */
/**
 * binary_tree_print - Print a visual representation of the binary tree
 * @root: A pointer to the parent node
 *
 * Return: void
 */
void binary_tree_print(const binary_tree_t *root);
/**
 * binary_tree_node - Create a binary tree node
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
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
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/**
 * binary_tree_insert_right - Insert a node as the right-child of another
 *			      node. If parent already has a right-child,
 *			      the new node must take its place, and the old
 *			      right-child must be set as the
 *			      right-child of the new node.
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node,
 *	   or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/**
 * binary_tree_delete - Delete an entire binary tree.
 *			If tree is NULL, do nothing.
 * @tree: A pointer to the root node of the tree to delete
 * Return: Void
 */
void binary_tree_delete(binary_tree_t *tree);
/**
 * binary_tree_is_leaf - Check if a node is a leaf.
 *			 If node is NULL return 0.
 * @node: A pointer to the node to check
 * Return: 1 - If node is a leaf
 *	   0 - otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node);
/**
 * binary_tree_is_root - Check if a node is a root.
 *			 If node is NULL, return 0.
 * @node: A pointer to the node to check
 * Return: 1 - If node is a root
 *	   0 - otherwise
 */
int binary_tree_is_root(const binary_tree_t *node);
/**
 * binary_tree_preorder - Go through a binary tree using pre-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_inorder - Go through a binary tree using in-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_postorder - Go through a binary tree using
 *			   post-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

#endif /* BINARY_TREES_H */
