main: main.cpp libcrosswordsolver.so
	g++ main.cpp -o main -L. -lcrosswordsolver
	mkdir --parents ${COMPONENT_ROOT}/bin
	cp -f main ${COMPONENT_ROOT}/bin

libcrosswordsolver.so: Board.o Rack.o Dictionary.o Solver.o Solution.o SolutionSet.o Constraint.o Permute.o WordOrientation.o Scorer.o
	g++ Board.o Rack.o Dictionary.o Solver.o Solution.o SolutionSet.o Constraint.o Permute.o WordOrientation.o Scorer.o -shared -fPIC -o libcrosswordsolver.so
	mkdir --parents ${COMPONENT_ROOT}/lib
	cp -f libcrosswordsolver.so ${COMPONENT_ROOT}/lib

Board.o: Board.h Board.cpp
	g++ -fPIC -c Board.cpp -o Board.o

Rack.o: Rack.h Rack.cpp Permute.h
	g++ -fPIC -c Rack.cpp -o Rack.o

Dictionary.o: Dictionary.h Dictionary.cpp
	g++ -fPIC -c Dictionary.cpp -o Dictionary.o

Solution.o: Solution.h Solution.cpp
	g++ -fPIC -c Solution.cpp -o Solution.o

SolutionSet.o: SolutionSet.h SolutionSet.cpp Solution.h
	g++ -fPIC -c SolutionSet.cpp -o SolutionSet.o

Solver.o: Solver.h Solver.cpp Board.h Rack.h Dictionary.h Solution.h SolutionSet.h
	g++ -fPIC -c Solver.cpp -o Solver.o

Constraint.o: Constraint.h Constraint.cpp Dictionary.h
	g++ -fPIC -c Constraint.cpp -o Constraint.o

Permute.o: Permute.h Permute.cpp
	g++ -fPIC -c Permute.cpp -o Permute.o

WordOrientation.o: WordOrientation.h WordOrientation.cpp
	g++ -fPIC -c WordOrientation.cpp -o WordOrientation.o

Scorer.o: Scorer.h Scorer.cpp
	g++ -fPIC -c Scorer.cpp -o Scorer.o

clean:
	rm -f *.o
	rm -f *.so
	rm -f main
