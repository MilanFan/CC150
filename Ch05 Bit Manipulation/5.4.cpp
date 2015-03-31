/*
 * 5.4.cpp
 *
 * Explain what the following code does: ((n & (n-1)) == 0
 *
 * ANSWER:
 * ((n & (n-1)) == 0) checks if n is a power of 2 (or if n is 0).
 *
 *  Created on: Mar 31, 2015
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cout << "n\t" << "((n & (n-1)) == 0" << endl;
	for (int i = 0; i <= 16; i++) {
		cout << n << "\t\t" << (((n & (n-1)) == 0)) << endl;
		n = (1 << i);
	}

	return 0;
}


