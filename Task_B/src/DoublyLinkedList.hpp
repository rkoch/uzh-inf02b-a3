//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "DoublyLinkedListNode.hpp" 

class DoublyLinkedList {

public:
	DoublyLinkedList();          // constructor
	~DoublyLinkedList();         // destructor

	void push_front(double value);
	void push_back(double value);

	void pop_front();
	void pop_back();

	DoublyLinkedListNode* get_head();
	DoublyLinkedListNode* get_tail();
	bool is_empty();
	void print_list();

protected:
	DoublyLinkedListNode* head;          // pointer to first node
	DoublyLinkedListNode* tail;          // pointer to last node

};

#endif
