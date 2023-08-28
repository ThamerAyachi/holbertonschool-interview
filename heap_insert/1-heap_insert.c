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
 * heap_insert_recursive - insert
 *
 * @node: pointer
 * @value: value
 *
 * Return: Pointer
 */
binary_tree_t *heap_insert_recursive(binary_tree_t *node, int value)
{
	if (node == NULL)
	{
		return create_heap_node(value);
	}

	if (node->right == NULL)
	{
		node->right = heap_insert_recursive(node->right, value);
		node->right->parent = node;
		heapify_up(node->right);
	}
	else if (node->left == NULL)
	{
		node->left = heap_insert_recursive(node->left, value);
		node->left->parent = node;
		heapify_up(node->left);
	}
	else
	{
		if (node->right->right && node->right->left)
		{
			node->left = heap_insert_recursive(node->left, value);
			node->left->parent = node;
			heapify_up(node->left);
		}
		else
		{
			node->right = heap_insert_recursive(node->right, value);
			node->right->parent = node;
			heapify_up(node->right);
		}
	}

	heapify_up(node);

	return node;
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
	if (*root == NULL)
	{
		*root = create_heap_node(value);
		return *root;
	}

	return heap_insert_recursive(*root, value);
}
