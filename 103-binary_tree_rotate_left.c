#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivots, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivots = tree->right;
	temp = pivots->left;
	pivots->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivots;
	pivots->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivots;
		else
			temp->right = pivots;
	}

	return (pivots);
}
