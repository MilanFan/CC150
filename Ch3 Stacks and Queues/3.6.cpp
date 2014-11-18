/*
 * 3.6.cpp
 *
 * Write a program to sort a stack in ascending order (with biggest items on top).
 * You may use at most one additional stack to hold items, but you may not copy
 * the elements into any other data structure (such as an array). The stack supports
 * the following operations: push, pop, peek, and isEmpty
 *
 *  Created on: Nov 18, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <stack>
using namespace std;

void sort(stack<int> &s)
{
	stack<int> t;

	while (!s.empty()) {
		int tmp = s.top();
		s.pop();
		while (!t.empty() && tmp > t.top()) {
			s.push(t.top());
			t.pop();
		}
		t.push(tmp);
	}
	while (!t.empty()) {
		s.push(t.top());
		t.pop();
	}
}

int main()
{
	int a[] = {8, 3, 5, 2, 7, 5, 9, 10, 6, 4};
	stack<int> s;
	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++) s.push(a[i]);
	sort(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	return 0;
}
