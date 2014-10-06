/*
 * 1.3.cpp
 *
 * Given two strings, write a method to decide if one is a permutation of the other
 *
 * NULL string
 *
 *  Created on: Oct 6, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <string>
using namespace std;

#define MAX_CHAR 256

bool isPermutation(string &s1, string &s2)
{
	if (s1.empty() )
	if (s1.length() != s2.length()) return false;
	int count[MAX_CHAR] = {0};

	for (size_t i = 0; i < s1.length(); i++) {
		count[s1[i] - '\0']++;
		count[s2[i] - '\0']--;
	}
	for (size_t i = 0; i < MAX_CHAR; i++) {
		if (count[i] != 0) return false;
	}

	return true;
}

int main()
{
	string s1 = "aaabbb";
	string s2 = "ababab";
	string s3 = "aabbaa";
	string s4 = "ab";

	cout << isPermutation(s1, s2) << endl;
	cout << isPermutation(s1, s3) << endl;
	cout << isPermutation(s1, s4) << endl;

	return 0;
}


