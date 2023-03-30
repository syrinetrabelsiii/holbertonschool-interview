#include "binary_trees.h"

/**
 * newNode - create node
 * @parent: parent
 * @n: Size
 * Return: node
 */
avl_t *newNode(avl_t *parent, size_t n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}

/**
 * createAvlTree - build an AVL tree
 * @array: array
 * @start: start
 * @end: end
 * @parent: parent
 * Return: root
 */
avl_t *createAvlTree(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = newNode(parent, array[mid]);
	if (!root)
		return (NULL);

	if (start != mid)
		root->left = createAvlTree(array, start, mid - 1, root);
	if (end != mid)
		root->right = createAvlTree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: array
 * @size: size
 * Return: root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);

	return (root = createAvlTree(array, 0, size - 1, NULL));
}
