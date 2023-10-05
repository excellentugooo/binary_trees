#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_nodes = 0;

	if (tree)
	{
		count_nodes += (tree->left || tree->right) ? 1 : 0;
		count_nodes += binary_tree_nodes(tree->left);
		count_nodes += binary_tree_nodes(tree->right);
	}
	return (count_nodes);
}
