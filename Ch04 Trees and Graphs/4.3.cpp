/*
 * 4.3.cpp
 *
 * Given a sorted (increasing order) array with unique integer elements,
 * write an algorithm to create a binary search tree with minimal height
 *
 *  Created on: Nov 24, 2014
 *      Author: Milan Fan
 */

#include <binary_tree.h>
using namespace std;

TreeNode* createMinimalBST(int a[], int start, int end)
{
	if (end < start) return NULL;
	int mid = (start + end) / 2;
	TreeNode n = new TreeNode(a[mid]);
	n.left = createMinimalBST(a, start, mid - 1);
	n.right = createMinimalBST(a, mid + 1, end);

	return n;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(a) / sizeof(a[0]);
	TreeNode *root = createMinimalBST(a, 0, len-1);

	return 0;
}


