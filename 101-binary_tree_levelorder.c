#include "binary_trees.h"

levelorder_queue_t *creates_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *heads);
void pints_push(binary_tree_t *node, levelorder_queue_t *heads,
		levelorder_queue_t **tails, void (*func)(int));
void pops(levelorder_queue_t **heads);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

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
		tmp = heads->next;
		free(heads);
		heads = temp;
	}
}

/**
 * pints_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @heads: A double pointer to the head of the queue.
 * @tails: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pints_push(binary_tree_t *node, levelorder_queue_t *heads,
		levelorder_queue_t **tails, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = creates_node(node->left);
		if (new == NULL)
		{
			free_queue(heads);
			exit(1);
		}
		(*tails)->next = new;
		*tails = new;
	}
	if (node->right != NULL)
	{
		new = creates_node(node->right);
		if (new == NULL)
		{
			free_queue(heads);
			exit(1);
		}
		(*tails)->next = new;
		*tails = new;
	}
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
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *heads, *tails;

	if (tree == NULL || func == NULL)
		return;

	heads = tails = creates_node((binary_tree_t *)tree);
	if (heads == NULL)
		return;

	while (heads != NULL)
	{
		pints_push(head->node, heads, &tails, func);
		pops(&head);
	}
}
