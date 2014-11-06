/*
 * 2.3.cpp
 *
 * Implement an algorithm to delete a node in the middle of a singly linked list,
 * given only access to that node.
 *
 *  Created on: Nov 5, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <linked_list.h>
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

void deleteNode (ListNode* p)
{
	if (!p) return;
	if (!p->next) {
		cout << "The last node cannot be deleted" << endl;
		return;
	}

	ListNode *cur = p;
	while (cur->next->next) {
		cur->val = cur->next->val;
		cur = cur->next;
	}
	cur->val = cur->next->val;
	delete cur->next;
	cur->next = NULL;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	ListNode *head = init(a, sizeof(a)/sizeof(a[0]));

	cout << "Origin:\t\t";
	output(head);
	int k = 1;
	ListNode *p = head;
	while (--k) {
		p = p->next;
	}
	deleteNode(p);
	cout << "After:\t\t";
	output(head);

	return 0;
}

