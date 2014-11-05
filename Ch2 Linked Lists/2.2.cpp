/*
 * 2.2.cpp
 *
 * Implement an algorithm to find the kth to last element of a singly linked list
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

ListNode *kthLast(ListNode *head, int k)
{
	ListNode *p1 = head;
	ListNode *p2 = head;

	int n = 0;
	while (n++ < k) {
		if (!p1) return NULL;
		p1 = p1->next;
	}

	while (p1) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	ListNode *head = init(a, sizeof(a)/sizeof(a[0]));

	cout << "Origin:\t\t";
	output(head);
	ListNode *p = kthLast(head, 0);
	if (p)
		cout << "kth to last:\t" << p->val << endl;
	else
		cout << "invalid input" << endl;

	return 0;
}


