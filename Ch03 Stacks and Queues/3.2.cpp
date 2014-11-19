/*
 * 3.2.cpp
 *
 * How would you design a stack which, in addition to push and pop,
 * also has a function min which returns the minimum element?
 * Push, pop and min should all operate in O(1) time.
 *
 *  Created on: Nov 12, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class StackNode {
public:
	int val;
	int min;
	StackNode(int v, int m) : val(v), min(m) {}
};

class StackWithMin : public stack<StackNode> {
public:
	void push(int val) {
		if (this->empty())
			stack::push(StackNode(val, val));
		else
			stack::push(StackNode(val, std::min(val, this->top().min)));
	}

	int min() {
		if (this->empty()) return INT_MAX;
		return this->top().min;
	}

	void output() {
		if (this->empty()) return;
		cout << "Min: " << this->top().min << endl;
	}
};

int main()
{
	StackWithMin s;
	int cmd, val;

	while (true) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> val;
			s.push(val);
		} else if (cmd == 2) {
			s.pop();
		} else {
			cout << "End" << endl;
			break;
		}
		s.output();
	}

	return 0;
}



