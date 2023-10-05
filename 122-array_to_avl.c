#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, x;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < i; x++)
		{
			if (array[x] == array[i])
				break;
		}
		if (x == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
