//
//  vectors.cpp
//  Vectors
//
//  Created by Loc Nguyen on 24.02.12.
//  Copyright (c) 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#include "vectors.h"

template<typename Object>
ArrayVector<Object>::ArrayVector(int initCap)
		: capacity(initCap), numberOfElements(0) {
	array = new Object[capacity];
}

template<typename Object>
ArrayVector<Object>::~ArrayVector() {
	delete[] array;
}

template<typename Object>
int ArrayVector<Object>::size() const {
	return numberOfElements;
}

template<typename Object>
bool ArrayVector<Object>::isEmpty() const {
	return numberOfElements == 0;
}

template<typename Object>
Object& ArrayVector<Object>::elemAtRank(int r) {
	return array[r];
}

template<typename Object>
void ArrayVector<Object>::replaceAtRank(int r, const Object& e) {
	array[r] = e;
}

template<typename Object>
void ArrayVector<Object>::removeAtRank(int r) {
	for (int i = r; i < numberOfElements - 1; i++) {
		array[i] = array[i + 1];
	}
	numberOfElements--;
}

template<typename Object>
void ArrayVector<Object>::insertAtRank(int r, const Object& e) {
	if ((r < 0) || (r > numberOfElements)) {
		// Could throw an index out of range exception
		return;
	}

	// Check for available storage
	if (numberOfElements == capacity) {
		overflow();
	}

	// Insert element
	for (int i = numberOfElements - 1; i >= r; i--) {
		array[i + 1] = array[i];
	}
	array[r] = e;
	numberOfElements++;
}

template<typename Object>
void ArrayVector<Object>::overflow() {
	// This doubles the capacity of the storage array
	capacity *= 2;
	Object* tmp = new Object[capacity];

	for (int i = 0; i < numberOfElements; i++) {
		tmp[i] = array[i];
	}

	delete[] array;
	array = tmp;
}

