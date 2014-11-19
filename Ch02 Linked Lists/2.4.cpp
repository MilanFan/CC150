/*
 * 2.4.cpp
 *
 * Write code to partition a linked list around a value x, such that all nodes
 * less than x come before all nodes greater than or equal to x
 *
 *  Created on: Nov 6, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <linked_list.h>
#include <queue>
using namespace std;


ListNode* init(int a[], int len)
{
	if (!a || len < 1) return NULL;
	ListNode *head = new ListNode(a[0]);
	ListNode *cur = head;
	for (int i = 1; i < len; i++) {
		ListNode *p = new ListNode(a[i]);
		cur->next = p;
		cur = cur->next;
	}
	return head;
}

void output(ListNode *head)
{
	if (head) {
		cout << head->val;
		ListNode *cur = head->next;
		while (cur) {
			cout << " -> " << cur->val;
			cur = cur->next;
		}
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

// unstable sorting
void partition_swapval(ListNode *head, int x)
{
	queue<ListNode *> q;
	ListNode *cur = head;

	while (cur) {
		if (cur->val >= x) {
			q.push(cur);
		} else if (!q.empty()) {
			ListNode *front = q.front();
			swap(front->val, cur->val);
			q.pop();
			q.push(cur);	// push to queue for future possible swap
		}
		cur = cur->next;
	}
}

// stable sorting
ListNode* partition_twolists(ListNode *head, int x)
{
	ListNode *h = NULL;
	ListNode *cur = head;
	queue<ListNode *> q1, q2;

	while (cur) {
		if (cur->val < x) {
			q1.push(cur);
		} else {
			q2.push(cur);
		}
		cur = cur->next;
	}

	if (!q1.empty()) {
		h = q1.front();
		q1.pop();
		cur = h;
		while (!q1.empty()) {
			cur->next = q1.front();
			q1.pop();
			cur = cur->next;
		}
	}
	if (h) {
		cur->next = q2.front();
	} else {
		h = q2.front();
		cur = h;
	}
	while (!q2.empty())
	{
		cur = cur->next;
		q2.pop();
		cur->next = q2.front();
	}
	cur->next = NULL;
	return h;
}

int main()
{
	int a[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	ListNode *h1 = init(a, sizeof(a)/sizeof(a[0]));
	ListNode *h2 = init(a, sizeof(a)/sizeof(a[0]));

	cout << "Origin:\t\t";
	output(h1);
	partition_swapval(h1, 4);
	cout << "SwapVal:\t";
	output(h1);
	h2 = partition_twolists(h2, 4);
	cout << "TwoList:\t";
	output(h2);

	return 0;
}

