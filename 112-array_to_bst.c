#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, j;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (j = 0; j < x; j++)
		{
			if (array[j] == array[x])
				break;
		}
		if (j == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
