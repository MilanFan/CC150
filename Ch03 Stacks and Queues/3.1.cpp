/*
 * 3.1.cpp
 *
 * Describe how you could use a single array to implement three stacks
 *
 * SOLUTION
 * stack all nodes together, with each nodes pointing to its previous nodes
 * in the stack: top_idx; top_idx[0] pointing to the next available empty space.
 *
 *
 *  Created on: Nov 10, 2014
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define MAX_SIZE	100
#define MAX_STACK	3

struct StackNode {
	int val;
	int prev;
	StackNode() : val(0), prev(0) {}
};

StackNode a[MAX_SIZE];		// the array
int top_idx[MAX_STACK+1];	// index of the top of each stack in the array
int count[MAX_STACK+1];		// number elements in each stack


void push(int num, int val)
{
	if (top_idx[0] >= MAX_SIZE) {
		cout << "Exceed array max size" << endl;
		return;
	}

	int idx = top_idx[0];
	if (a[idx].prev == 0)
		top_idx[0] = idx + 1;
	else
		top_idx[0] = a[idx].prev;
	a[idx].val = val;
	a[idx].prev = top_idx[num];
	top_idx[num] = idx;
	count[num]++;
	count[0]++;
}

void pop(int num)
{
	int idx = top_idx[num];
	if (idx < 0) {
		cout << "No data in stack " << num << endl;
		return;
	}
	top_idx[num] = a[idx].prev;
	a[idx].prev = top_idx[0];
	top_idx[0] = idx;
	count[num]--;
	count[0]--;
}

int top(int num)
{
	if (top_idx[num] < 0) {
		cout << "No data in stack " << num << endl;
		return -1;
	}
	return a[top_idx[num]].val;
}

bool empty(int num)
{
	if (count[num] > 0) return false;
	return true;
}

int size(int num)
{
	return count[num];
}

void output()
{
	for (int i = 1; i <= MAX_STACK; i++) {
		cout << "Stack " << i << " : ";
		int idx = top_idx[i];
		while (idx >= 0) {
			cout << a[idx].val << "->";
			idx = a[idx].prev;
		}
		cout << endl;
	}
}

int main()
{
	int cmd, num, val;	// input: command, stack number and value

	top_idx[0] = count[0] = 0;
	for (int i = 1; i <= MAX_STACK; i++) {
		top_idx[i] = -1;
		count[i] = 0;
	}

	while (true) {
		cin >> cmd;
		if (cmd < 1 || cmd > 5) break;
		cin >> num;
		if (num < 0 || num > 3 || (num == 0 && cmd != 5)) break;
		if (cmd == 1) cin >> val;
		switch (cmd) {
		case 1:	// push
			push(num, val);
			output();
			break;
		case 2:	// pop
			pop(num);
			output();
			break;
		case 3:	// top
			cout << "Stack " << num << " top: " << top(num) << endl;
			break;
		case 4:	// empty
			cout << "Stack " << num << " is ";
			if (empty(num))
				cout << "empty" << endl;
			else
				cout << "not empty" << endl;
			break;
		case 5:	// size
			if (num == 0)
				cout << "The size of all stacks is ";
			else
				cout << "The size of Stack " << num << " is ";
			cout << size(num) << endl;
			break;
		default:
			break;
		}
		cout << endl;
	}
	cout << "End" << endl;
}


