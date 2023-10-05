#include "binary_trees.h"

levelorder_queue_t *creates_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *heads);
void push(binary_tree_t *node, levelorder_queue_t *heads,
		levelorder_queue_t **tails);
void pops(levelorder_queue_t **heads);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * creates_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *creates_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @heads: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *heads)
{
	levelorder_queue_t *temp;

	while (heads != NULL)
	{
		temp = heads->next;
		free(heads);
		heads = temp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @heads: A double pointer to the head of the queue.
 * @tails: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *heads,
		levelorder_queue_t **tails)
{
	levelorder_queue_t *new;

	new = creates_node(node);
	if (new == NULL)
	{
		free_queue(heads);
		exit(1);
	}
	(*tails)->next = new;
	*tails = new;
}

/**
 * pops - Pops the head of a levelorder_queue_t queue.
 * @heads: A double pointer to the head of the queue.
 */
void pops(levelorder_queue_t **heads)
{
	levelorder_queue_t *temp;

	temp = (*heads)->next;
	free(*heads);
	*heads = temp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *heads, *tails;
	unsigned char flags = 0;

	if (tree == NULL)
		return (0);

	heads = tails = creates_node((binary_tree_t *)tree);
	if (heads == NULL)
		exit(1);

	while (heads != NULL)
	{
		if (heads->node->left != NULL)
		{
			if (flags == 1)
			{
				free_queue(heads);
				return (0);
			}
			push(heads->node->left, heads, &tails);
		}
		else
			flags = 1;
		if (heads->node->right != NULL)
		{
			if (flags == 1)
			{
				free_queue(heads);
				return (0);
			}
			push(heads->node->right, heads, &tails);
		}
		else
			flags = 1;
		pops(&heads);
	}
	return (1);
}
