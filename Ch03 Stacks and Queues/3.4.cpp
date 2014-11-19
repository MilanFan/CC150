/*
 * 3.4.cpp
 *
 * In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes
 * which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from
 * top to bottom (i.e., each disk sits on top of an even larger one). You have the following constraints:
 * (1) Only one disk can be moved at a time.
 * (2) A disk is slid off the top of one tower onto the next rod.
 * (3) A disk can only be placed on top of a larger disk.
 * Write a program to move the disks from the first tower to the last using Stacks.
 *
 *  Created on: Nov 14, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <stack>
using namespace std;

int N;

class StackWithIndex : public stack<int> {
private:
	char index;
public:
	StackWithIndex(char i) : index(i) {};
	char Index() {
		return index;
	}
};

void Hanoi(int n, StackWithIndex &s1, StackWithIndex &s2, StackWithIndex &s3)
{
	if (n <= 0) return;
	Hanoi(n-1, s1, s3, s2);
	s3.push(s1.top());
	cout << s1.top() << ":\t" << s1.Index() << " -> " << s3.Index() << endl;
	s1.pop();
	Hanoi(n-1, s2, s1, s3);
}

int main()
{
	StackWithIndex s1('A'), s2('B'), s3('C');

	cin >> N;
	if (N > 0) {
		for (int i = N; i >= 1; i--) s1.push(i);
		Hanoi(N, s1, s2, s3);
	}
	cout << "End" << endl;

	return 0;
}




