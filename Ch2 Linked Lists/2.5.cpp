/*
 * 2.5.cpp
 *
 * You have two numbers represented by a linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * FOLLOW UP
 * Suppose the digits are stored in forward order. Repeat the above problem
 *
 *  Created on: Nov 6, 2014
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

ListNode *add(ListNode *l1, ListNode *l2)
{
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	int carry = 0;
	while (l1 && l2) {
		int sum = l1->val + l2->val + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	ListNode *l3 = l1 ? l1 : l2;
	while (l3) {
		int sum = l3->val + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		l3 = l3->next;
		cur = cur->next;
	}
	return head->next;
}

ListNode *reverse(ListNode* head)
{
	ListNode *prev =NULL;
	ListNode *cur = head;

	while (cur) {
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;
}

int main()
{
	int a[] = {3, 4, 1};
	int b[] = {7, 5, 8, 3};
	ListNode *l1 = init(a, sizeof(a)/sizeof(a[0]));
	ListNode *l2 = init(b, sizeof(b)/sizeof(b[0]));
	cout << "Reverse order: ";
	output(add(l1, l2));
	cout << "Forward order: ";
	output(reverse(add(reverse(l1), reverse(l2))));
}


