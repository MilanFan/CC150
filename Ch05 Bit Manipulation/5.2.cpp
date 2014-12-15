/*
 * 5.2.cpp
 *
 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
 * print the binary representation. If the number cannot be represented accurately
 * in binary with at most 32 characters, print "ERROR."
 *
 *  Created on: Dec 12, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_DIGITS	32

void binaryFloat(double n)
{
	cout << n << ": ";
	if (n <= 0 || n >= 1) {
		cout << "ERROR" << endl;
		return;
	}

	char ret[MAX_DIGITS + 1] = "";	// set all char to '\0'
	ret[0] = '0';
	ret[1] = '.';
	int pos = 2;
	while (pos < MAX_DIGITS && n > 0) {
		float tmp = pow(2, 1 - pos);
		if (n >= tmp) {
			ret[pos] = '1';
			n -= tmp;
		} else
			ret[pos] = '0';
		pos++;
	}
	if (n == 0) {
		printf("%s\n", ret);
	}
	else cout << "ERROR" << endl;
}

int main()
{
	binaryFloat(0.5);
	binaryFloat(0.75);
	binaryFloat(0.625);
	binaryFloat(0.342);
	binaryFloat(0.343);
	return 0;
}
