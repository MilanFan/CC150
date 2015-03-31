/*
 * 5.3.cpp
 *
 * Given a positive integer, print the next smallest and the next largest number that
 * have the same number of 1 bits in their binary representation
 *
 *  Created on: Dec 15, 2014
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define MAX_BIT 16

/* find the first digit (0 or 1) in number n starts from pos */
int findPos(int n, int digit, int pos)
{
	while (pos < MAX_BIT) {
		if (((n & (1 << pos)) >> pos) == digit) return pos;
		pos++;
	}
	return -1;
}

int nextSmallest(int n)
{
	int pos0 = findPos(n, 0, 0);
	if (pos0 >= 0) {
		int pos1 = findPos(n, 1, pos0 + 1);
		if (pos1 > 0) {
			cout << "The next smallest number of " << n;
			n &= ~(1 << pos1);
			n |= (1 << (pos1 - 1));
			cout << " is " << n << endl;
			return n;
		}
	}
	cout << "No number is smaller than " << n << endl;

	return 0;
}

int nextLargest(int n)
{
	int pos1 = findPos(n, 1, 0);
	if (pos1 >= 0) {
		int pos0 = findPos(n, 0, pos1 + 1);
		if (pos0 > 0) {
			cout << "The next largest number of " << n;
			n &= ~(1 << (pos0 - 1));
			n |= (1 << pos0);
			cout << " is " << n << endl;
			return n;
		}
	}
	cout << "No number is larger than " << n << endl;

	return 0;
}

int main()
{
	int n;

	cin >> n;
	if (n <= 0 || n >= (1 << MAX_BIT))
		cout << "Invalid input" << endl;
	else {
		nextSmallest(n);
		nextLargest(n);
	}

	return 0;
}


