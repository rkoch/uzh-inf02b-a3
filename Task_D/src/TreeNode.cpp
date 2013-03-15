/*
 * Assignment 3 - Algorithms and data structures
 *
 * University of Zurich
 * Department of Informatics
 * Vizualization and Multimedia Laboratory
 *
 * Author: Genc Mazlami
 */

#include <iostream>
#include <string>
#include "TreeNode.h"
#include "KeyValuePair.h"

TreeNode::TreeNode(KeyValuePair element_) {
	element = &element_;
	left_child = NULL;
	right_child = NULL;
}

TreeNode::TreeNode(int key_, std::string value_) {

	KeyValuePair* tmp_element = new KeyValuePair(key_, value_);
	element = tmp_element;
	left_child = NULL;
	right_child = NULL;
}

KeyValuePair* TreeNode::getPair() {
	return element;
}

void TreeNode::setLeftChild(TreeNode* node_pointer_) {
	left_child = node_pointer_;
}

void TreeNode::setRightChild(TreeNode* node_pointer_) {
	right_child = node_pointer_;
}

void TreeNode::printPreOrder() {
	//TODO: fill in your code here
}

void TreeNode::printInOrder() {
	//TODO: fill in your code here

}

void TreeNode::printPostOrder() {

	//TODO: fill in your code here
}

TreeNode* TreeNode::searchKey(int key_) {

	//TODO: fill in your code here

}

void TreeNode::add(KeyValuePair* element_) {

	//TODO: fill in your code here

}

