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

/**
 * 1) Visiting and printing binary tree in preOrder
 */
void TreeNode::printPreOrder() {
	printElement();
	if (left_child != NULL) {
		left_child->printPreOrder();
	}
	if (right_child != NULL) {
		right_child->printPreOrder();
	}
}

/**
 * 1) Visiting and printing binary tree in inOrder
 */
void TreeNode::printInOrder() {
	if (left_child != NULL) {
		left_child->printInOrder();
	}
	printElement();
	if (right_child != NULL) {
		right_child->printInOrder();
	}
}

/**
 * 1) Visiting and printing binary tree in postOrder
 */
void TreeNode::printPostOrder() {
	if (left_child != NULL) {
		left_child->printPostOrder();
	}
	if (right_child != NULL) {
		right_child->printPostOrder();
	}
	printElement();
}

/**
 * 1) Printing element of current node to stdout
 */
void TreeNode::printElement() {
	std::cout << "(" << element->getKey() << ": " << element->getValue() << ")";
}

/**
 * 2) Searching the binary tree
 */
TreeNode* TreeNode::searchKey(int key_) {
	int node = element->getKey();
	if ((key_ < node) && (left_child != NULL)) {
		return left_child->searchKey(key_);
	} else if ((key_ > node) && (right_child != NULL)) {
		return right_child->searchKey(key_);
	}

	return this;
}

/**
 * 3) Inserting the element into a binary tree
 */
void TreeNode::add(KeyValuePair* element_) {
	int newKey = element_->getKey();

	TreeNode* found = searchKey(newKey);
	int foundKey = found->element->getKey();

	TreeNode* newChild = new TreeNode(element_->getKey(), element_->getValue());
	if (newKey < foundKey) {
		found->left_child = newChild;
	} else if (newKey > foundKey) {
		found->right_child = newChild;
	} else {
		std::cerr << "WARNING: node with same key already exists." << std::endl;
		delete newChild;
	}
}
