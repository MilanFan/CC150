/*
 * 4.9.cpp
 *
 * You are given a binary tree in which each node contains a value.
 * Design an algorithm to print all paths which sum to a given value.
 * The path does not need to start or end at the root or a leaf.
 *
 * Example
 * 			10
 * 		   /  \
 * 		  5   12
 * 		 / \	\
 * 		9	7	 10
 * 	   /	 \
 * 	 -2	 	  -7
 * 	 /		   \
 * 	5	 	    22
 *
 * Paths (val = 22)
 * - 10 -> 5 -> 9 -> -2
 * - 10 -> 5 -> 7
 * - 10 -> 12
 * - 12 -> 10
 * - 7 -> -7 -> 22
 * - 22
 *
 *  Created on: Dec 10, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
#include <vector>
using namespace std;

void printPath(vector<int> path, int start, int end)
{
	cout << path[start];
	while (++start <= end)
		cout << "->" << path[start];
	cout << endl;
}

void findPath(TreeNode *r, int sum, vector<int> path, size_t level)
{
	if (!r) return;
	if (path.size() <= level)
		path.push_back(r->val);
	else
		path[level] = r->val;
	int s = 0;
	for (int i = level; i >= 0; i--) {
		s += path[i];
		if (s == sum)
			printPath(path, i, level);
	}
	findPath(r->left, sum, path, level + 1);
	findPath(r->right, sum, path, level + 1);
}

int main()
{
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(7);
	root->right->right = new TreeNode(10);
	root->left->left->left = new TreeNode(-2);
	root->left->right->right = new TreeNode(-7);
	root->left->left->left->left = new TreeNode(5);
	root->left->right->right->right = new TreeNode(22);

	vector<int> path;
	findPath(root, 22, path, 0);

	return 0;
}


