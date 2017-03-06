ouput: Main.o Location.o LocationSolver.o
	g++ Main.o Location.o LocationSolver.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

Location.o: Location.cpp Location.h
	g++ -c Location.cpp

LocationSolver.o: LocationSolver.cpp LocationSolver.h
	g++ -c LocationSolver.cpp

clean:
	rm *.o output