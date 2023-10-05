#include "binary_trees.h"

/**
 * tree_sizes - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_sizes(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rit = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lft = 1 + tree_sizes(tree->left);

	if (tree->right)
		height_rit = 1 + tree_sizes(tree->right);

	return (height_lft + height_rit);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *arr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_sizes(heap) + 1;

	arr = malloc(sizeof(int) * (*size));

	if (!arr)
		return (NULL);

	for (i = 0; heap; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
