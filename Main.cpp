/*
 *  Main.cpp
 *
 *  Created on: Feb 25, 2017
 *  Author: Julian Sniffen
 */


#include <iostream>
#include "LocationSolver.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
vector<LocationSolver> solvers;

    //check that a filename argument is given
    if(argv[1]){
        string line;
        ifstream myfile(argv[1]);
        if(myfile.is_open()){
            while(getline(myfile, line)){
                //if the first char in the line is '0' we are done
                if(line[0] != '0'){
                    solvers.push_back(LocationSolver(line));
                }
            }
            myfile.close();
        }
        //print out the solutions case by case
        for(int i = 0; i < solvers.size(); i++){
            cout << "Case " << (i + 1) << ": " << solvers[i].getSolution() << " "<< solvers[i].getDistance() << endl;
        }
    }else{
        cout << "Please enter a filename" << endl;
    }
}

