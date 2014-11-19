/*
 * 2.6.cpp
 *
 * Given a circular linked list, implement an algorithm which
 * returns the node at the beginning of the loop
 *
 *  Created on: Nov 7, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <linked_list.h>
using namespace std;


ListNode* init(int a[], int len, int x)
{
	if (!a || len < 1) return NULL;
	ListNode **array = new ListNode*[len];
	ListNode *head = new ListNode(a[0]);
	ListNode *cur = head;
	array[0] = head;
	for (int i = 1; i < len; i++) {
		ListNode *p = new ListNode(a[i]);
		array[i] = p;
		cur->next = p;
		cur = cur->next;
	}
	cur->next = array[x];
	return head;
}

void output(ListNode *head)
{
	if (head) {
		cout << head->val;
		ListNode *cur = head->next;
		int count = 0;
		while (cur && count++ < 10) {
			cout << " -> " << cur->val;
			cur = cur->next;
		}
	}
	cout << endl;
}

ListNode* loopEntry(ListNode *head)
{
	ListNode* p1 = head;
	ListNode* p2 = head;

	// check if loop exists
	while (p2) {
		p1 = p1->next;
		p2 = p2->next;
		if (!p2) return NULL;
		p2 = p2->next;
		if (p1 == p2) break;
	}
	if (!p2) return NULL;

	// count nodes in the loop
	int n = 0;
	do {
		p1 = p1->next;
		n++;
	} while (p1 != p2);

	// find the entry of the loop
	p1 = p2 = head;
	for (int i = 0; i < n; i++) {
		p2 = p2->next;
	}
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ListNode *head = init(a, sizeof(a)/sizeof(a[0]), 8);
	output(head);
	ListNode *entry = loopEntry(head);

	if (entry)
		cout << entry->val << endl;

	return 0;
}
