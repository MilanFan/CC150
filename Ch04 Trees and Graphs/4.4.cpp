/*
 * 4.4.cpp
 *
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at
 * each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 *
 *  Created on: Nov 24, 2014
 *      Author: Milan Fan
 */


#include <linked_list.h>
#include <binary_tree.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<ListNode *> lists;
vector<ListNode *> heads;

TreeNode* createBT(int depth)
{
	int count = 0;
	TreeNode *r = new TreeNode(++count);
	queue<TreeNode *> q;
	q.push(r);

	while (count < pow(2, depth) - 1) {
		TreeNode *cur = q.front();
		TreeNode *left = new TreeNode(++count);
		TreeNode *right = new TreeNode(++count);
		cur->left = left;
		cur->right = right;
		q.pop();
		q.push(left);
		q.push(right);
	}

	return r;
}

void output()
{
	for (size_t i = 0; i < heads.size(); i++) {
		ListNode *cur = heads[i];
		cout << "Level " << i << ": " << cur->val;
		cur = cur->next;
		while (cur) {
			cout << " -> " << cur->val;
			cur = cur->next;
		}
		cout << endl;
	}

}

void BTList(TreeNode *r, size_t level)
{
	if (!r) return;
	if (lists.size() < level + 1) {
		lists.push_back(new ListNode(r->val));
		heads.push_back(lists.back());
	} else {
		lists[level]->next = new ListNode(r->val);
		lists[level] = lists[level]->next;
	}
	BTList(r->left, level + 1);
	BTList(r->right, level + 1);
}

int main()
{
	int depth = 0;
	cin >> depth;
	if (depth > 0) {
		TreeNode *root = createBT(depth);
		BTList(root, 0);
		output();
	}

	return 0;
}


