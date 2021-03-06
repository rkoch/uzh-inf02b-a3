//
//  Passenger.h
//  Busdriver
//
//  Created by Fabian Hofstetter on 23.02.12.
//  Copyright 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#ifndef Busdriver_Passenger_h
#define Busdriver_Passenger_h

#include <string>

class Passenger {

public:
	Passenger(int enterStation_, int leaveStation_);

	int getEnterStation();
	int getLeaveStation();
	bool isSitting();

private:
	int enterStation;
	int leaveStation;
	bool sitting;

};

#endif
