/*
 * 1.4.c
 *
 * Write a method to replace all spaces in a string with'%20'
 *
 *  Created on: Oct 9, 2014
 *      Author: Milan Fan
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN	256
void replace(char* s, int len)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < len; i++) {
		if (s[i] == ' ') count++;
	}
	s[len+count*2] = '\0';
	for (i = len - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			s[i+count*2] = '0';
			s[i+count*2-1] = '2';
			count--;
			s[i+count*2] = '%';
		} else {
			s[i+count*2] = s[i];
		}
	}
}

int main()
{
	char str[MAX_LEN];
	strcpy(str, "Mr John Smith");
	printf("%s\n", str);
	replace(str, strlen(str));
	printf("%s\n", str);

	return 0;
}

