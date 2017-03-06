/*
 *  LocationSolver.cpp
 *
 *  Created on: Feb 25, 2017
 *  Author: Julian Sniffen
 */

#include "LocationSolver.h"
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

LocationSolver::LocationSolver() {}

LocationSolver::LocationSolver(string line){
    vector<string> tokens;
    vector<int> xs, ys;
    istringstream iss(line);
    string token;
    int xmedian, ymedian, size;

    //split the line into tokens based off of spaces
    while(getline(iss, token, ' ')){
        tokens.push_back(token);
    }

    //loop through the tokens ignoring the first chraracter
    //we increment by two because there are two chars for every location
    for(int i = 1; i < tokens.size(); i += 2){
        //create a location for each set of coordinates
        locations.push_back(Location(atof(tokens[i].c_str()), atof(tokens[i + 1].c_str())));
        //create a separate vector for the x coordinates
        xs.push_back(atof(tokens[i].c_str()));
        //create a separate vector for the y coordinates
        ys.push_back(atof(tokens[i + 1].c_str()));
    }

    //sort the x and y coordinate vectors
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    //find the median of each vector
    size = xs.size();
    if(!size%2){
        xmedian = (xs[(size/2) - 1] + xs[size/2])/2;
        ymedian = (ys[(size/2) - 1] + ys[size/2])/2;
    }else{
        xmedian = xs[size/2];
        ymedian = ys[size/2];
    }
    
    //the answer is the location with x component: x-median and y component: y-median
    solution = Location(xmedian, ymedian);
    distance = 0;

    //sum up the distance from all locations to the solution
    for(int i = 0; i < locations.size(); i++){
        distance += locations[i].distance(solution);
    }
}

int LocationSolver::getDistance(){
    return distance;
}

Location LocationSolver::getSolution(){
    return solution;
}
