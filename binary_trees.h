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
/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the node to measures the depth
 *
 * Return: The depth of the tree starting at @tree
 */
size_t binary_tree_depth(const binary_tree_t *tree);
/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @tree
 */
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_leaves - Count the leaves in a binary tree
 *
 * @tree: Pointer to the node to measures the leaves of it
 *
 * Return: The leaves of the tree starting at @tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree);
/**
 * binary_tree_nodes - Count the nodes with at least 1 child in a binary tree
 *
 * @tree: Pointer to the node to start from
 *
 * Return: The number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree);
/**
 * binary_tree_balance - Measure the balance factor of a binary tree
 * @tree: Pointer to the node to measures its balance factor
 *
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree);
/**
 * binary_tree_is_full - Check if a binary tree is full
 *
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If a binary tree is full
 *	   0 - Otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the node to start from
 *
 * Return: 1 - If it is a perfect binary tree
 *	   0 - Otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * binary_tree_sibling - Find the sibling of a node.
 * @node: A pointer to the node to to find the sibling
 * Return: If node has a sibling - A pointer to the sibling node
 *	   Otherwise - NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/**
 * binary_tree_uncle - Find the uncle of a node.
 * @node: A pointer to the node to to find the uncle
 * Return: If node has an uncle - A pointer to the uncle node
 *	   Otherwise - NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor
 *	   If no common ancestor was found return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
/**
 * binary_tree_levelorder - Go through a binary tree using
 *			    level-order traversal
 * @tree: A pointer a pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

#endif /* BINARY_TREES_H */
