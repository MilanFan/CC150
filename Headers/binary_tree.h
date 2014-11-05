/*
 * binary_tree.h
 *
 *  Created on: May 31, 2014
 *      Author: MilanFan
 */

#include <iostream>

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif /* BINARY_TREE_H_ */
