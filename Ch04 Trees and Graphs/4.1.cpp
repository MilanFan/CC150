/*
 * 4.1.cpp
 *
 * Implement a function to check if a binary tree is balanced. For the purposes of
 * this question, a balanced tree is defined to be a tree such that the heights of
 * the two subtrees of any node never differ by more than one.
 *
 * SOLUTION
 * - isBalanced_c is O(n^2)
 * - isBalanced is O(n)
 *
 *  Created on: Nov 18, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
#include <algorithm>
using namespace std;

int height_c(TreeNode *r)
{
	if (!r) return 0;
	return max(height_c(r->left), height_c(r->right)) + 1;
}

bool isBalanced_c(TreeNode *r)
{
	return !r || (isBalanced_c(r->left) && isBalanced_c(r->right) &&
			abs(height_c(r->left) - height_c(r->right)) <= 1);
}

int height(TreeNode *r)
{
	if (!r) return 0;
	int lh = height(r->left);
	if (lh < 0) return -1;
	int rh = height(r->right);
	if (rh < 0) return -1;
	if (abs(lh - rh) > 1) return -1;
	return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *r)
{
	if (height(r) < 0) return -1;
	return true;
}

int main()
{
	return 0;
}

