/*
 *  Location.h
 *
 *  Created on: Feb 25, 2017
 *  Author: Julian Sniffen
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <iostream>

using namespace std;

class Location {
public:
	/*
	 * Default Constructor
	 */
	Location();

	/*
	 * Parameterized Constructor
	 */
	Location(int x, int y);

	/*
	 * Find the distance between this location and the one passed in
	 */
	int distance(Location loc);

	/*
	 * Overload the << operator for easy printing
	 */
	friend ostream& operator<<(ostream& os, const Location& location) {
	    os << "(" << location.coordinates[0] << "," << location.coordinates[1] << ")";
	    return os;
	}
private:
	/*
	 * stores the coordinates of a location
	 */
	int coordinates[2];
};

#endif /* LOCATION_H_ */
