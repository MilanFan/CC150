/*
 * 4.6.cpp
 *
 * Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
 * a binary search tree. You may assume that each node has a link to its parent
 *
 * SOLUTION
 * - with parent pointer
 * - without parent pointer
 *
 *  Created on: Dec 4, 2014
 *      Author: Milan Fan
 */


#include <binary_tree.h>
using namespace std;

/* tree node with parent pointer */
struct TreeNodePP {
	int val;
	TreeNodePP *left;
	TreeNodePP *right;
	TreeNodePP *parent;
	TreeNodePP(int x): val(x), left(NULL), right(NULL), parent(NULL) {}
};

TreeNodePP *nextNodePP(TreeNodePP *n)
{
	if (!n) return NULL;

	/* if there is a right tree, return the left most of the RT */
	if (n->right) {
		n = n->right;
		while (n->left) {
			n = n->left;
		}
		return n;
	}
	/* otherwise, backtracking until the node is the LT of its parent
	 * it will be the root if the given node is the right most of the LT of the root
	 * it will be NULL if the given node is the right most of the RT of the root
	 */
	while (n == n->parent->right) {
		n = n->parent;
	}
	return n->parent;
}

TreeNode *nextNode(TreeNode *root, TreeNode *n)
{
	if (!n) return NULL;

	/* the same, return the left most of the RT */
	if (n->right) {
		n = n->right;
		while (n->left) {
			n = n->left;
		}
		return n;
	}
	/* search from the root */
	TreeNode * ret = NULL;
	TreeNode * cur = root;
	while (cur) {
		if (cur == n) return ret;
		if (n->val > cur->val)
			cur = cur->right;
		else {
			ret = cur;
			cur = cur->left;
		}
	}
	return NULL;
}

int main()
{
	return 0;
}
