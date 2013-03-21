//
//  main.cpp
//  Busdriver
//
//  Created by Fabian Hofstetter on 23.02.12.
//  Copyright 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include "Passenger.h"

using std::string;
using std::cout;
using std::endl;
using std::flush;

#define SIZEOFBUS 30
#define NUMBEROFSTATIONS 8
#define TIMEBETWEENSTATIONS 1

/**
 * Defining the iterator for the map
 */
typedef std::map<string, Passenger*>::iterator passenger_iterator;

std::map<std::string, Passenger*> onTheBus;
void init();
void wait(int seconds);
void print();
void letPassengersOut();
int getNumberOfPassengers();

int startStation = 1;
int currentStation;

std::string seats[SIZEOFBUS] = { "Row 1, seat A", "Row 1, seat B", "Row 1, seat C", "Row 2, seat A", "Row 2, seat B", "Row 2, seat C", "Row 3, seat A", "Row 3, seat B",
		"Row 3, seat C", "Row 4, seat A", "Row 4, seat B", "Row 4, seat C", "Row 5, seat A", "Row 5, seat B", "Row 5, seat C", "Row 6, seat A", "Row 6, seat B", "Row 6, seat C",
		"Row 7, seat A", "Row 7, seat B", "Row 7, seat C", "Row 8, seat A", "Row 8, seat B", "Row 8, seat C", "Row 9, seat A", "Row 9, seat B", "Row 9, seat C", "Row 10, seat A",
		"Row 10, seat B", "Row 10, seat C" };

int main(int argc, const char * argv[]) {
	init();

	currentStation = startStation;

	for (int i = 0; i < NUMBEROFSTATIONS; i++) {
		letPassengersOut();

		print();
		currentStation = (currentStation + 1);
		wait(TIMEBETWEENSTATIONS);
		cout << endl;
	}

	return 0;
}

/*
 * 1) create a new Passenger an add it to the map
 */
void init() {
	for (int i = 0; i < SIZEOFBUS; i++) {
		int enterStation = (rand() % NUMBEROFSTATIONS) + 1;
		int leaveStation = (rand() % NUMBEROFSTATIONS) + 1;

		Passenger* p = new Passenger(enterStation, leaveStation);
		onTheBus.insert(std::pair<string, Passenger*>(seats[i], p));
	}
}

/*
 * 2) write a function so the process waits for the given seconds till he continues
 */
void wait(int seconds) {
	// I don't know if this works on windows as this sleep() function depends on the compiler.
	// There is a possibility to implement with portability in mind.
	// The code would probably look like that (not tested):
	// #include <time.h>
	// clock_t goal = seconds * 1000 + clock();
	// while (goal > clock());
	// ATTN: This would take 100% CPU usage while waiting and that is not really great.

	sleep(seconds);
}

/*
 * 3) write a function so bus stops an delete the passengers in the map, which want to leave the bus at the current station
 */
void letPassengersOut() {
	int count = 0;

	passenger_iterator itr = onTheBus.begin();
	while (itr != onTheBus.end()) {
		Passenger* p = itr->second;
		if ((p != NULL) && (p->getLeaveStation() == currentStation)) {
			count++;
			onTheBus.erase(itr++);
			delete p;
		} else {
			itr++;
		}
	}
	cout << count << " persons left the bus at current station " << currentStation << "." << endl;
}

/*
 * 4) write a function that prints a list with the passengers on the bus
 */
void print() {
	cout << getNumberOfPassengers() << " persons are still on the bus." << flush;
	if (getNumberOfPassengers() > 0) {
		cout << " Current taken seats are:" << endl;
		for (passenger_iterator itr = onTheBus.begin(); itr != onTheBus.end(); itr++) {
			if (itr != onTheBus.begin()) {
				cout << "; " << flush;
			}
			cout << itr->first << flush;
		}
	}
	cout << endl;
}

/*
 * 5) write a function that returns how many passengers are currently on the bus
 */
int getNumberOfPassengers() {
	return onTheBus.size();
}
