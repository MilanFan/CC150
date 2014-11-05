/*
 * 1.2.c
 *
 * Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string
 *
 *  Created on: Oct 4, 2014
 *      Author: Milan Fan
 */

#include <stdio.h>	// printf
#include <string.h>	// strlen

void reverse(char* str)
{
	int i = 0;
	int len = strlen(str);

	for (i = 0; i < len / 2; i++) {
		char c = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = c;
	}
}

int main()
{
	char s[] = "this is a dog.";

	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);

	return 0;
}
