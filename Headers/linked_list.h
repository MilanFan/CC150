/*
 * linked_list.h
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

#include <iostream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif /* LINKED_LIST_H_ */
