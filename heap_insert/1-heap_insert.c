#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * create_heap_node - create
 *
 * @value: int
 *
 * Return: binary_tree
 */
binary_tree_t *create_heap_node(int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node)
	{
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

/**
 * heapify_up - do it
 *
 * @node: pointer of node
 */
void heapify_up(binary_tree_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - insert node
 *
 * @root: pointer of node
 * @value: value
 *
 * Return: new node
 */
binary_tree_t *heap_insert(binary_tree_t **root, int value)
{
	binary_tree_t *new_node = create_heap_node(value);
	if (!new_node)
		return NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return new_node;
	}

	binary_tree_t *current = *root;
	while (current->left && current->right)
	{
		if (current->left->left && current->left->right)
			current = current->right;
		else
			current = current->left;
	}

	if (!current->left)
		current->left = new_node;
	else
		current->right = new_node;

	new_node->parent = current;

	heapify_up(new_node);

	return new_node;
}
