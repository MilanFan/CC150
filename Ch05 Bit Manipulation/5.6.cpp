/*
 * 5.6.cpp
 *
 * Write a program to swap odd and even bits in an integer with as few instructions as
 * possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
 *
 *  Created on: Mar 31, 2015
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define ODD_MASK 0xAAAAAAAA
#define EVEN_MASK 0x55555555

int swapOddEvenBits(int n)
{
	return (((n & ODD_MASK) >> 1) | ((n & EVEN_MASK) << 1));
}

int main()
{
	int a;

	cin >> a;
	cout << swapOddEvenBits(a) << endl;

	return 0;
}



