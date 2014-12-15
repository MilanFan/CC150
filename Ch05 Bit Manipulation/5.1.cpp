/*
 * 5.1.cpp
 *
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
 * method to insert M into N such that M starts at bit j and ends at bit i. You can assume
 * that the bits j through i have enough space to fit all of M. That is, if M = 10011,
 * you can assume that there are at least 5 bits between j and i. You would not,
 * for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
 * EXAMPLE:
 * Input: N = 10000000000, M = 10011, i = 2, j = 6
 * Output: N = 10001001100
 *
 *  Created on: Dec 10, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <bitset>
using namespace std;

int insert(int N, int M, size_t i, size_t j)
{
	int mask = ~0;
	mask = mask << (j + 1);
	mask |= ((1 << i) - 1);
	N &= mask;
	N |= (M << i);

	return N;
}

int main()
{
	int N = 0b10000000000;
	int M = 0b10011;
	size_t i = 2;
	size_t j = 6;

	cout << "N = " << bitset<16>(N) << endl;
	cout << "M = " << bitset<8>(M) << endl;

	int ret = insert(N, M, i, j);
	cout << "ret " << bitset<16>(ret) << endl;

	return 0;
}


