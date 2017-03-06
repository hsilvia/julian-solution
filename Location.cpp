/*
 *  Location.cpp
 *
 *  Created on: Feb 25, 2017
 *  Author: Julian Sniffen
 */

#include "Location.h"
#include "stdlib.h"

Location::Location() {}

Location::Location(int x, int y){
	coordinates[0] = x;
	coordinates[1] = y;
}

int Location::distance(Location loc){
	//the difference between two locations is the absolute value of the difference
	//between thier respective x and y coordinates
	return abs(coordinates[0] - loc.coordinates[0]) + abs(coordinates[1] - loc.coordinates[1]);
}

