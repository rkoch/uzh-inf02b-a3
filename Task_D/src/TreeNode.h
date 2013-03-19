/*
 * Assignment 3 - Algorithms and data structures
 *
 * University of Zurich
 * Department of Informatics
 * Vizualization and Multimedia Laboratory
 *
 * Author: Genc Mazlami
 *
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a3
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "KeyValuePair.h"

class TreeNode {

private:

	KeyValuePair* element;

	TreeNode* left_child;

	TreeNode* right_child;

	/**
	 * 1) Printing element of current node to stdout
	 */
	void printElement();

public:

	TreeNode(KeyValuePair element_);

	TreeNode(int key_, std::string value_);

	TreeNode();

	KeyValuePair* getPair();

	TreeNode* searchKey(int key_);

	void setLeftChild(TreeNode* node_pointer_);

	void setRightChild(TreeNode* node_pointer_);

	void add(KeyValuePair* element_);

	void printPreOrder();

	void printPostOrder();

	void printInOrder();

};
