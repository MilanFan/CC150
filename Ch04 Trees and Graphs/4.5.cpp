/*
 * 4.5.cpp
 *
 * Implement a function to check if a binary tree is a binary search tree
 *
 *
 *  Created on: Dec 1, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
#include <climits>
using namespace std;

bool isBST(TreeNode *r, int min, int max)
{
	if (!r) return true;
	// the val is left of max and right of min,
	// thus it CANNOT = min, but COULD = max
	if (r->val <= min || r->val > max) return false;
	return isBST(r->left, min, r->val) && isBST(r->right, r->val, max);
}

int main()
{
	TreeNode *r = new TreeNode(20);
	r->left = new TreeNode(15);
	r->left->right = new TreeNode(15);
	r->right = new TreeNode(40);
	r->right->left = new TreeNode(40);

	if (isBST(r, INT_MIN, INT_MAX)) cout << "BST" << endl;
	else cout << "Not BST" << endl;

	return 0;
}


