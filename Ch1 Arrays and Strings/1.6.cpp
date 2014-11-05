/*
 * 1.6.cpp
 *
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees. Can you do this in place?
 *
 *  Created on: Oct 16, 2014
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define N	4

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void transpose(int array[][N])
{
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N; j++)
			swap(array[i][j], array[N - i - 1][j]);
	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			swap(array[i][j], array[j][i]);
}

int main()
{
    int array[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    transpose(array);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }

    return 0;
}
