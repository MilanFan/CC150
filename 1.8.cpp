/*
 * 1.8.cpp
 *
 * Assume you have a method isSubstring which checks if one word is a substring of another.
 * Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only
 * one call to isSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
 *
 *  Created on: Oct 16, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string s1, const string s2)
{
	if(s1.find(s2) == string::npos) return false;
	return true;
}

bool isRotation(const string s1, const string s2)
{
	if (s1.length() != s2.length() || s1.length() <= 0) return false;
	return isSubstring(s1 + s1, s2);
}

int main()
{
	string s1 = "waterbottLe";
	string s2 = "erbottLewat";
	cout << isRotation(s1, s2) << endl;
	s2 = "erbottLewa";
	cout << isRotation(s1, s2) << endl;
	s2 = "erbottLevat";
	cout << isRotation(s1, s2) << endl;

	return 0;
}



