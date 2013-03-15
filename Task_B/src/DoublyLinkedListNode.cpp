#include "DoublyLinkedListNode.hpp"

#include <cassert>

// constructor of a doubly linked list node. The previous and next pointer are initialized with
// null and the value member is initialized with provided argument.
DoublyLinkedListNode::DoublyLinkedListNode(double value)
		: node_value(value), previous_node(0), next_node(0) {
}

DoublyLinkedListNode* DoublyLinkedListNode::get_next() {
	return next_node;
}

void DoublyLinkedListNode::set_next(DoublyLinkedListNode* next) {
	next_node = next;
}

DoublyLinkedListNode* DoublyLinkedListNode::get_prev() {
	return previous_node;
}

void DoublyLinkedListNode::set_prev(DoublyLinkedListNode* prev) {
	previous_node = prev;
}

void DoublyLinkedListNode::set_value(double value) {
	node_value = value;
}

double DoublyLinkedListNode::get_value() {
	return node_value;
}

void DoublyLinkedListNode::insert_as_next_node(DoublyLinkedListNode* new_next) {
	// TODO
	// complete this method
	// use the assert method to check if the properness of the used pointers
}

void DoublyLinkedListNode::insert_as_previous_node(DoublyLinkedListNode* new_prev) {
	// TODO
	// complete this method
	// use the assert method to check if the properness of the used pointers
}
