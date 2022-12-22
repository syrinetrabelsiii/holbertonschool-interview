#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node for the node to create
 * @value: the value for the new node
 *
 * Return: pointer to the newly created node, or NULL if failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	
	new->n = value;
	new->parent = parent;
	
	new->left = NULL;
	new->right = NULL;
    
	return (new);
}
