/*
 * 4.7.cpp
 *
 * Design an algorithm and write code to find the first common ancestor of two nodes
 * in a binary tree. Avoid storing additional nodes in a data structure.
 * NOTE: This is not necessarily a binary search tree
 *
 * SOLUTION
 * - find() function is added for cases one or two nodes are not in the tree
 * - if additional buffer allowed, could use tree traverse for both nodes,
 *   store paths to arrays and then comparing the two paths until not match
 *
 *  Created on: Dec 4, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
using namespace std;

TreeNode *commonAncestor(TreeNode *r, int p, int q)
{
	if (!r) return NULL;
	if (r->val == p || r->val == q) return r;
	TreeNode *nl = commonAncestor(r->left, p, q);
	TreeNode *nr = commonAncestor(r->right, p, q);
	if (nl && nr) return r;
	return nl ? nl : nr;
}

int find(TreeNode *r, int p, int q)
{
	int ret = 0;
	if (!r) return 0;
	if (r->val == p) ret++;
	if (r->val == q) ret++;
	ret += find(r->left, p, q) + find(r->right, p, q);
	return ret;
}

TreeNode* LCA(TreeNode *r, int p, int q)
{
	if (find(r, p, q) < 2) return NULL;
	return commonAncestor(r, p, q);
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	cout << "LCA(4, 6) = " << LCA(root, 4, 6)->val << endl;
	cout << "LCA(6, 7) = " << LCA(root, 6, 7)->val << endl;
	cout << "LCA(2, 4) = " << LCA(root, 2, 4)->val << endl;
	TreeNode *ret = LCA(root, 5, 9);
	cout << "LCA(5, 9) = ";
	if (ret) cout << ret->val << endl;
	else cout << "not exist" << endl;

	return 0;
}

