/*
 * 4.8.cpp
 *
 * You have two very large binary trees: T1, with millions of nodes, and T2,
 * with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is
 * identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
 *
 *  Created on: Dec 8, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
using namespace std;

bool isIdentical(TreeNode *r, TreeNode *n)
{
	if (!r && !n) return true;
	if (!r || !n) return false;
	return (r->val == n->val) &&
			isIdentical(r->left, n->left) &&
			isIdentical(r->right, n->right);
}

bool isFound(TreeNode *r, TreeNode *n)
{
	if (!r) return false;
	if (r->val == n->val)
		if (isIdentical(r, n)) return true;
	return (isFound(r->left, n) || isFound(r->right, n));
}

bool isSubTree(TreeNode *T1, TreeNode *T2)
{
	if (!T2) return true;
	return isFound(T1, T2);
}

int main()
{
	return 0;
}


