/*
 * 1.1.cpp
 *
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 *
 *  Created on: Sep 21, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <string>
using namespace std;

#define MAX_CHAR 256

bool isUnique(string &s)
{
	bool code[MAX_CHAR] = {false};
	if (s.length() > MAX_CHAR) return false;
	for (size_t i = 0; i < s.length(); i++) {
		size_t idx = s[i] - '\0';
		if (code[idx]) return false;
		code[idx] = true;
	}
	return true;
}

int main()
{
	string s1 = "abcdsejfhra1";
	string s2 = "abcdefghi123";

	cout << s1 << " " << isUnique(s1) << endl;
	cout << s2 << " " << isUnique(s2) << endl;

	return 0;
}


