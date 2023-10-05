#include "binary_trees.h"

bst_t *inorder_child(bst_t *root);
bst_t *delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recurs(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_child - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_child(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *child = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	child = inorder_child(node->right);
	node->n = child->n;

	return (delete(root, child));
}

/**
 * bst_remove_recurs - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recurs(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete(root, node));
		if (node->n > value)
			return (bst_remove_recurs(root, node->left, value));
		return (bst_remove_recurs(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recurs(root, root, value));
}
