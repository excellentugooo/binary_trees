#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t count_depth(const binary_tree_t *tree);
const binary_tree_t *get_leaves(const binary_tree_t *tree);
int is_perfect_recurs(const binary_tree_t *tree,
		size_t depth, size_t lev);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * count_depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t count_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + count_depth(tree->parent) : 0);
}

/**
 * get_leaves - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaves(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaves(tree->left) : get_leaves(tree->right));
}

/**
 * is_perfect_recurs - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @depth: The depth of one leaf in the binary tree.
 * @lev: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recurs(const binary_tree_t *tree,
		size_t depth, size_t lev)
{
	if (is_leaf(tree))
		return (lev == depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recurs(tree->left, depth, lev + 1) &&
		is_perfect_recurs(tree->right, depth, lev + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recurs(tree, count_depth(get_leaves(tree)), 0));
}
