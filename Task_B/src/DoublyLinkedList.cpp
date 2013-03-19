//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#include <iostream>
#include <cassert>

#include "DoublyLinkedList.hpp" 

using std::cout;
using std::endl;

// standard constructor
DoublyLinkedList::DoublyLinkedList()
		: head(0), tail(0) {
}

/*
 * 1) destructor to remove list nodes (unfortunately they had to be invoked with new -.-)
 */
DoublyLinkedList::~DoublyLinkedList() {
	DoublyLinkedListNode* node = head;
	while (node != NULL) {
		DoublyLinkedListNode* old = node;
		node = old->get_next();
		delete old;
	}
}

DoublyLinkedListNode* DoublyLinkedList::get_head() {
	return head;
}

DoublyLinkedListNode* DoublyLinkedList::get_tail() {
	return tail;
}

/*
 * 1) insert node at front of list
 */
void DoublyLinkedList::push_front(double value) {
	DoublyLinkedListNode* node = new DoublyLinkedListNode(value);
//	DoublyLinkedListNode tmp = DoublyLinkedListNode(value);
//	DoublyLinkedListNode* node = &tmp;

	if (head == NULL) {          // If list was empty before
		tail = node;
		head = node;
	} else {					 // Otherwise add new node to list
		head->insert_as_previous_node(node);
		head = node;
	}
}

/*
 * 1) insert node at back of list
 */
void DoublyLinkedList::push_back(double value) {
	DoublyLinkedListNode* node = new DoublyLinkedListNode(value);
//	DoublyLinkedListNode tmp = DoublyLinkedListNode(value);
//	DoublyLinkedListNode* node = &tmp;

	if (tail == NULL) {          // If list was empty before
		tail = node;
		head = node;
	} else {					 // Otherwise add new node to list
		tail->insert_as_next_node(node);
		tail = node;
	}
}

/*
 * 1) delete node from front of list
 */
void DoublyLinkedList::pop_front() {
	DoublyLinkedListNode* oldHead = head;
	if (oldHead != NULL) {
		DoublyLinkedListNode* node = head->get_next();

		if (node != NULL) {
			node->set_prev(NULL);
		} else {
			tail = NULL;
		}

		head = node;
		delete oldHead;
	}
}

/*
 * 1) delete node from back of list
 */
void DoublyLinkedList::pop_back() {
	DoublyLinkedListNode* oldTail = tail;
	if (oldTail != NULL) {
		DoublyLinkedListNode* node = tail->get_prev();

		if (node != NULL) {
			node->set_next(NULL);
		} else {
			head = NULL;
		}

		tail = node;
		delete oldTail;
	}
}

/*
 * 1) check if list is empty
 */
bool DoublyLinkedList::is_empty() {
	return (head == NULL) && (tail == NULL);
}

/*
 * 1) Print out list
 */
void DoublyLinkedList::print_list() {
	if (is_empty()) {
		cout << "The list is empty" << endl;
	} else {
		DoublyLinkedListNode* node = head;
		while (node != NULL) {
			cout << "Node value: " << node->get_value() << endl;
			node = node->get_next();
		}
	}
}
