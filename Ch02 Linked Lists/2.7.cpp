/*
 * 2.7.cpp
 *
 * Implement a function to check if a linked list is a palindrome
 *
 *  Created on: Nov 7, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <linked_list.h>
#include <stack>
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

bool isPalindrome(ListNode *head)
{
	if (!head) return false;

	stack<ListNode*> s;
	ListNode *cur = head;
	int n = 0;
	while (cur) {
		cur = cur->next;
		n++;
	}
	cur = head;
	for (int i = 0; i < (n + 1) / 2; i++) {
		s.push(cur);
		cur = cur->next;
	}
	if (n % 2) s.pop();
	while (cur && !s.empty()) {
		ListNode *p = s.top();
		if (cur->val != p->val) return false;
		s.pop();
		cur = cur->next;
	}
	return true;
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
	ListNode *head = init(a, sizeof(a)/sizeof(a[0]));
	output(head);

	if (isPalindrome(head))
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}



