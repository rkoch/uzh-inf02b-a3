#include <iostream>
#include <cassert>

#include "DoublyLinkedList.hpp" 

// standard constructor
DoublyLinkedList::DoublyLinkedList()
		: head(0), tail(0) {
}

DoublyLinkedListNode* DoublyLinkedList::get_head() {
	return head;
}

DoublyLinkedListNode* DoublyLinkedList::get_tail() {
	return tail;
}

// insert node at front of list
void DoublyLinkedList::push_front(double value) {
	// TODO
	// complete this method
	// use the properties of the DoublyLinkedListNode class
}

// insert node at back of list
void DoublyLinkedList::push_back(double value) {
	// TODO
	// complete this method
	// use the properties of the DoublyLinkedListNode class
}

// delete node from front of list
void DoublyLinkedList::pop_front() {
	// TODO
	// complete this method
	// use the properties of the DoublyLinkedListNode class
}

// delete node from back of list
void DoublyLinkedList::pop_back() {
	// TODO
	// complete this method
	// use the properties of the DoublyLinkedListNode class
}

bool DoublyLinkedList::is_empty() {
	// TODO
	// complete this method
}

void DoublyLinkedList::print_list() {
	// TODO
	// complete this method
	// if the list is empty, print out "The list is empty"
}
