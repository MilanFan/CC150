/*
 * 5.5.cpp
 *
 * Write a function to determine the number of bits required to convert integer A to integer B
 *
 *  Created on: Mar 31, 2015
 *      Author: Milan Fan
 */


#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int count = 0;

	cin >> a >> b;

	for (int c = a ^ b; c > 0;  c = c >> 1) {
		count += (c & 1);
	}

	cout << count << endl;

	return 0;
}
