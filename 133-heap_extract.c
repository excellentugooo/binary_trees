#include "binary_trees.h"
#include <stdlib.h>

/**
 * trees_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t trees_height(const heap_t *tree)
{
	size_t height_lft = 0;
	size_t height_rit = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lft = 1 + trees_height(tree->left);

	if (tree->right)
		height_rit = 1 + trees_height(tree->right);

	if (height_lft > height_rit)
		return (height_lft);
	return (height_rit);
}
/**
 * tree_sum_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_sum_h(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rit = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lft = 1 + tree_sum_h(tree->left);

	if (tree->right)
		height_rit = 1 + tree_sum_h(tree->right);

	return (height_lft + height_rit);
}

/**
 * bt_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 */
void bt_preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	bt_preorder(tree->left, node, height);
	bt_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
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

	bt_preorder(heap_r, &node, trees_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
