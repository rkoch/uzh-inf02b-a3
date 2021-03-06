//
//  Passenger.cpp
//  Busdriver
//
//  Created by Fabian Hofstetter on 23.02.12.
//  Copyright 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#include <iostream>
#include "Passenger.h"

Passenger::Passenger(int enterStation_, int leaveStation_)
		: enterStation(enterStation_), leaveStation(leaveStation_) {
}

int Passenger::getEnterStation() {
	return enterStation;
}

int Passenger::getLeaveStation() {
	return leaveStation;
}

bool Passenger::isSitting() {
	return isSitting();
}
