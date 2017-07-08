main: Makefile Main.cpp ExampleTestCase.o PermuteTestCase.o DictionaryTestCase.o BoardTestCase.o RackTestCase.o ConstraintTestCase.o SolutionTests.o SolutionSetTests.o SolverTests.o ScorerTests.o
	g++ Main.cpp PermuteTestCase.o DictionaryTestCase.o BoardTestCase.o RackTestCase.o ConstraintTestCase.o ScorerTests.o SolverTests.o SolutionTests.o SolutionSetTests.o -o test -ldl -lcppunit -L../src -lcrosswordsolver

ExampleTestCase.o: ExampleTestCase.h ExampleTestCase.cpp
	g++ -c ExampleTestCase.cpp -o ExampleTestCase.o

PermuteTestCase.o: PermuteTestCase.h PermuteTestCase.cpp
	g++ -c PermuteTestCase.cpp -o PermuteTestCase.o -I../src

DictionaryTestCase.o: DictionaryTestCase.h DictionaryTestCase.cpp
	g++ -c DictionaryTestCase.cpp -o DictionaryTestCase.o -I../src

BoardTestCase.o: BoardTestCase.h BoardTestCase.cpp
	g++ -c BoardTestCase.cpp -o BoardTestCase.o -I../src

RackTestCase.o: RackTestCase.h RackTestCase.cpp
	g++ -c RackTestCase.cpp -o RackTestCase.o -I../src

ConstraintTestCase.o: ConstraintTestCase.h ConstraintTestCase.cpp
	g++ -c ConstraintTestCase.cpp -o ConstraintTestCase.o -I../src

SolutionTests.o: SolutionTests.h SolutionTests.cpp
	g++ -c SolutionTests.cpp -o SolutionTests.o -I../src

SolutionSetTests.o: SolutionSetTests.h SolutionSetTests.cpp
	g++ -c SolutionSetTests.cpp -o SolutionSetTests.o -I../src

SolverTests.o: SolverTests.h SolverTests.cpp
	g++ -c SolverTests.cpp -o SolverTests.o -I../src

ScorerTests.o: ScorerTests.h ScorerTests.cpp
	g++ -c ScorerTests.cpp -o ScorerTests.o -I../src

clean:
	rm *.o
	rm test
