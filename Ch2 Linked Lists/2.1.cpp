/*
 * 2.1.cpp
 *
 * Write code to remove duplicates from an unsorted linked list.
 * How would you solve this problem if a temporary buffer is not allowed?
 *
 *  Created on: Oct 24, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <unordered_map>
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

void removeDuplicates_Hash(ListNode *head)
{
	if (!head) return;
	unordered_map<int, bool> hash;
	ListNode *cur = head;

	// true or false will return the same results
	// it is just a flag meaning corresponding val exists
	hash[head->val] = true;
	while (cur->next) {
		ListNode *nxt = cur->next;
		if (hash.find(nxt->val) != hash.end()) {
			cur->next = nxt->next;
			delete nxt;
		} else {
			hash[nxt->val] = true;
			cur = cur->next;
		}
	}
}

void removeDuplicates_NoBuffer(ListNode *head)
{
	if (!head) return;

	ListNode *p1 = head;
	while (p1) {
		ListNode *prev = p1;
		ListNode *p2 = prev->next;
		while (p2) {
			if (p2->val == p1->val) {
				prev->next = p2->next;
				delete p2;
				p2 = prev->next;
			} else {
				prev = p2;
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}
}

int main()
{
	int a[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	ListNode *h1 = init(a, sizeof(a)/sizeof(a[0]));
	ListNode *h2 = init(a, sizeof(a)/sizeof(a[0]));

	cout << "Origin:\t\t";
	output(h1);
	removeDuplicates_Hash(h1);
	cout << "Hash:\t\t";
	output(h1);
	removeDuplicates_NoBuffer(h2);
	cout << "NoBuffer:\t";
	output(h2);

	return 0;
}

