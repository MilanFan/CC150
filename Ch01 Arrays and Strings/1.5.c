/*
 * 1.5.c
 *
 * Implement a method to perform basic string compression using the counts of repeated characters
 *
 *  Created on: Oct 16, 2014
 *      Author: Milan Fan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int helper(char *s, const char c, const int count) {
	*s = c;
	sprintf(s+1, "%d", count);
	return (int)log10(count) + 2;
}

char* compression(char* str, const int len)
{
	char *s = (char *)calloc(len, sizeof(char));
	char c = 0;		// last char
	int count = 0;	// count of the consecutive same chars
	size_t pos = 0;	// position of the new string s
	size_t i = 0;
	while (i < len) {
		if (str[i] == c) {
			count++;
		} else {
			if (count > 0) pos += helper(s+pos, c, count);
			c = str[i];
			count = 1;
		}
		i++;
	}
	helper(s+pos, c, count);
	if (len <= strlen(s)) return str;

	return s;
}

int main()
{
	char str1[] = "aabcccccaaa";
	char str2[] = "aabcccccccccccaaa";
	char str3[] = "abc";

	printf("Origin: %s\t\tCompressed: %s\n", str1, compression(str1, strlen(str1)));
	printf("Origin: %s\tCompressed: %s\n", str2, compression(str2, strlen(str2)));
	printf("Origin: %s\t\t\tCompressed: %s\n", str3, compression(str3, strlen(str3)));

	return 0;
}


