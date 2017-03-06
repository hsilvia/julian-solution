/*
 *  LocationSolver.h
 *
 *  Created on: Feb 25, 2017
 *  Author: Julian Sniffen
 */

#ifndef LOCATIONSOLVER_H_
#define LOCATIONSOLVER_H_

#include "Location.h"
#include <vector>
#include <string>

using namespace std;

class LocationSolver {
public:
	/*
	 * Default Constructor
	 */
	LocationSolver();

	/*
	 * Parameterized Constructor
	 */
	LocationSolver(string line);

	/*
	 * accessor for private variable distance
	 */
	int getDistance();

	/*
	 * accessor for private variable solution
	 */
	Location getSolution();
private:
	/*
	 * stores the locations we're finding the median of
	 */
	vector<Location> locations;

	/*
	 * stores the solution location
	 */
	Location solution;

	/*
	 * stores the aggregate distance from all locations to the solution location
	 */
	int distance;
};

#endif /* LOCATIONSOLVER_H_ */
