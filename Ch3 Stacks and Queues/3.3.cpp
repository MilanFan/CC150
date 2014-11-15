/*
 * 3.3.cpp
 *
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack
 * exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
 * SetOfStacks should be composed of several stacks and should create a new stack
 * once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop()
 * should behave identically to a single stack (that is, pop() should return
 * the same values as it would if there were just a single stack).
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 *
 *  Created on: Nov 14, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SetOfStacks : public vector<stack<int>> {
#define CAPACITY	3
public:
	int count = 0;

	void add(int val)
	{
		stack<int> s;
		s.push(val);
		push_back(s);
	}

	void remove()
	{
		if (empty()) return;
		pop_back();
	}

	bool isfull()
	{
		if(empty()) return false;
		if (back().size() < CAPACITY) return false;
		return true;
	}

	void push(int val)
	{
		if (empty() || isfull())
			add(val);
		else
			back().push(val);
		count++;
	}

	void pop()
	{
		if (!empty()) {
			cout << "pop: " << back().top() << "\t";
			back().pop();
			if (back().empty()) remove();
			cout << "\t# of stacks: " << size();
			count--;
			cout << "\ttotal elements: " << count << endl;
		}
	}

	// roll over
	void popAt(int index)
	{
		size_t idx = index;
		if (empty() || idx < 0 || idx >= size()) return;
		cout << "pop(" << idx << "): " << at(idx).top();
		at(idx).pop();
		while (idx < size() - 1) {
			stack<int> s;
			idx++;
			while(!at(idx).empty()) {
				s.push(at(idx).top());
				at(idx).pop();
			}
			at(idx-1).push(s.top());
			s.pop();
			while(!s.empty()) {
				at(idx).push(s.top());
				s.pop();
			}
		}
		if (back().empty()) remove();
		cout << "\t# of stacks: " << size();
		count--;
		cout << "\ttotal elements: " << count << endl;
	}
};

int main()
{
	SetOfStacks sos;
	int cmd, val;

	while (true) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> val;
			sos.push(val);
		} else if (cmd == 2) {
			sos.pop();
		} else if (cmd == 3) {
			cin >> val;
			sos.popAt(val);
		} else {
			cout << "End" << endl;
			break;
		}
	}

	return 0;
}


