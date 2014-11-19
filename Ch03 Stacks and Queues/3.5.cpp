/*
 * 3.5.cpp
 *
 * Implement a MyQueue class which implements a queue using two stacks
 *
 *  Created on: Nov 17, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue : public stack<int> {
	stack<int> f;
	stack<int> b;
	int count = 0;

	void move2f()
	{
		while(!b.empty()) {
			f.push(b.top());
			b.pop();
		}
	}

	void move2b()
	{
		while(!f.empty()) {
			b.push(f.top());
			f.pop();
		}
	}

public:
	bool empty()
	{
		return (count == 0);
	}

	int size()
	{
		return count;
	}

	int front()
	{
		if (f.empty()) move2f();

		if (f.empty()) {
			cout << "queue is empty." << endl;
			return -1;
		}
		return f.top();
	}

	int back()
	{
		if (!b.empty()) return b.top();

		if (!f.empty()) move2b();

		if (b.empty()) {
			cout << "queue is empty.";
			return -1;
		}
		return b.top();
	}

	void push_back(int val)
	{
		b.push(val);
		count++;
	}

	void pop_front()
	{
		if (f.empty()) move2f();

		if (f.empty())
			cout << "Queue is empty." << endl;
		else {
			f.pop();
			count--;
		}
	}
};

int main()
{
	MyQueue q;
	int cmd, val;

	while (true) {
		cin >> cmd;
		if (cmd < 1 || cmd > 6) break;
		switch (cmd) {
		case 1:	// push_back
			cin >> val;
			q.push_back(val);
			cout << "push: " << val << endl;
			break;
		case 2:	// pop_front
//			cout << "pop: " << q.front() << endl;
			q.pop_front();
			break;
		case 3:	// front
			cout << "front: " << q.front() << endl;
			break;
		case 4:	// back
			cout << "back: " << q.back() << endl;
			break;
		case 5:	// empty
			if (q.empty())
				cout << "empty" << endl;
			else
				cout << "not empty" << endl;
			break;
		case 6:	// size
			cout << "size: " << q.size() << endl;
			break;
		default:
			break;
		}
		cout << endl;
	}
	cout << "End" << endl;

	return 0;
}

