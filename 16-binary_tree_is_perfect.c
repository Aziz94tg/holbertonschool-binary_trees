#include "binary_trees.h"

/**
 * get_depth - Computes the depth of the leftmost path
 * @tree: Pointer to the tree
 * Return: Depth as a size_t
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_recursive - Checks recursively for perfection
 * @tree: Pointer to current node
 * @depth: Expected depth for leaf nodes
 * @level: Current level
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (!tree)
		return (1);

	/* Leaf node check */
	if (!tree->left && !tree->right)
		return (depth == level + 1);

	/* One child only? Not perfect */
	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = get_depth(tree);
	return (is_perfect_recursive(tree, depth, 0));
}

