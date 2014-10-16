/*
 * 1.7.cpp
 *
 * Write an algorithm such that if an element in an MxN matrix is 0,
 * its entire row and column are set to 0
 *
 *  Created on: Oct 16, 2014
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define M	4
#define N	4

void zero(int array[M][N])
{
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        	if (array[i][j] == 0) array[i][0] = array[0][j] = 0;

    for (int i = 0; i < M; ++i)
    	if (array[i][0] == 0)
    		for (int j = 1; j < N; ++j)
    			array[i][j] = 0;

    for (int j = 0; j < N; ++j)
    	if (array[0][j] == 0)
    		for (int i = 1; i < M; ++i)
    			array[i][j] = 0;
}

int main()
{
    int array[M][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 11, 12},
        {13, 14, 0, 16}
    };
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    zero(array);
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
	return 0;
}


