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
#include "KeyValuePair.h"

int KeyValuePair::getKey() {
	return key;
}

std::string KeyValuePair::getValue() {
	return value;
}

KeyValuePair::KeyValuePair(int key_, std::string value_) {
	key = key_;
	value = value_;
}
