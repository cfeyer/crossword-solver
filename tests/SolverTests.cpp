#include "SolverTests.h"

#include "Solver.h"
#include "Board.h"
#include "Rack.h"
#include "Dictionary.h"
#include "Solution.h"
#include "SolutionSet.h"

#include <sstream>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION( SolverTests );

void SolverTests::setUp()
{
}


void SolverTests::test_solver_ctor()
{
   Solver solver;
}


void SolverTests::test_solve_simple_board_1()
{
   bool verbose = false;

   Board board;
   std::istringstream board_stream( "3 3\n- - -\n- w -\n - - -" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "e" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "ew" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "0w" );
   expected_constraint_1.tag_location( 0, 1, ORIENT_DOWN );

   Constraint expected_constraint_2( "0w" );
   expected_constraint_2.tag_location( 1, 0, ORIENT_RIGHT );

   Solution expected_solution_1( expected_constraint_1, "e" );
   Solution expected_solution_2( expected_constraint_2, "e" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
   // TODO Fix efficiency CPPUNIT_ASSERT_EQUAL( 4, dict.hit_count() );
}


void SolverTests::test_solve_simple_board_2()
{
   bool verbose = false;

   Board board;
   std::istringstream board_stream( "3 3\n- - -\n- w -\n - - -" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "e" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "we" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "w0" );
   expected_constraint_1.tag_location( 1, 1, ORIENT_DOWN );

   Constraint expected_constraint_2( "w0" );
   expected_constraint_2.tag_location( 1, 1, ORIENT_RIGHT );

   Solution expected_solution_1( expected_constraint_1, "e" );
   Solution expected_solution_2( expected_constraint_2, "e" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
}


void SolverTests::test_solve_simple_board_3()
{
   bool verbose = false;

   Board board;
   std::istringstream board_stream( "3 3\n- - -\n- w -\n - - -" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "e" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "ew\nwe" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "0w" );
   expected_constraint_1.tag_location( 0, 1, ORIENT_DOWN );

   Constraint expected_constraint_2( "0w" );
   expected_constraint_2.tag_location( 1, 0, ORIENT_RIGHT );

   Constraint expected_constraint_3( "w0" );
   expected_constraint_3.tag_location( 1, 1, ORIENT_RIGHT );

   Constraint expected_constraint_4( "w0" );
   expected_constraint_4.tag_location( 1, 1, ORIENT_DOWN );

   Solution expected_solution_1( expected_constraint_1, "e" );
   Solution expected_solution_2( expected_constraint_2, "e" );
   Solution expected_solution_3( expected_constraint_3, "e" );
   Solution expected_solution_4( expected_constraint_4, "e" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );
   expected_solution_set.add( expected_solution_3 );
   expected_solution_set.add( expected_solution_4 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
}


void SolverTests::test_solve_simple_board_4()
{
   bool verbose = false;

   Board board;
   std::istringstream board_stream( "3 3\nm - -\n- - -\n - - -" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "y o w a n" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "man\nmy" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "m0" );
   expected_constraint_1.tag_location( 0, 0, ORIENT_RIGHT );

   Constraint expected_constraint_2( "m01" );
   expected_constraint_2.tag_location( 0, 0, ORIENT_RIGHT );

   Constraint expected_constraint_3( "m0" );
   expected_constraint_3.tag_location( 0, 0, ORIENT_DOWN );

   Constraint expected_constraint_4( "m01" );
   expected_constraint_4.tag_location( 0, 0, ORIENT_DOWN );

   Solution expected_solution_1( expected_constraint_1, "y" );
   Solution expected_solution_2( expected_constraint_2, "an" );
   Solution expected_solution_3( expected_constraint_3, "y" );
   Solution expected_solution_4( expected_constraint_4, "an" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );
   expected_solution_set.add( expected_solution_3 );
   expected_solution_set.add( expected_solution_4 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
}


void SolverTests::test_solve_simple_board_5()
{
   bool verbose = false;

   Board board;
   std::istringstream board_stream( "3 3\n- - -\n- - -\n - - t" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "b u a" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "at\nbut" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "01t" );
   expected_constraint_1.tag_location( 0, 2, ORIENT_DOWN );

   Constraint expected_constraint_2( "0t" );
   expected_constraint_2.tag_location( 1, 2, ORIENT_DOWN );

   Constraint expected_constraint_3( "01t" );
   expected_constraint_3.tag_location( 2, 0, ORIENT_RIGHT );

   Constraint expected_constraint_4( "0t" );
   expected_constraint_4.tag_location( 2, 1, ORIENT_RIGHT );

   Solution expected_solution_1( expected_constraint_1, "bu" );
   Solution expected_solution_2( expected_constraint_2, "a" );
   Solution expected_solution_3( expected_constraint_3, "bu" );
   Solution expected_solution_4( expected_constraint_4, "a" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );
   expected_solution_set.add( expected_solution_3 );
   expected_solution_set.add( expected_solution_4 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
}


void SolverTests::test_solve_medium_board_1()
{
   bool verbose = true;

   Board board;
   std::istringstream board_stream( "3 3\nd o g\n- - -\nb u t" );
   board_stream >> board;

   Rack rack;
   std::istringstream rack_stream( "u" );
   rack_stream >> rack;

   Dictionary dict;
   std::istringstream dict_stream( "bud\ngut" );
   dict_stream >> dict;

   Constraint expected_constraint_1( "b0d" );
   expected_constraint_1.tag_location( 0, 0, ORIENT_DOWN );

   Constraint expected_constraint_2( "0t" );
   expected_constraint_2.tag_location( 1, 2, ORIENT_DOWN );

   Constraint expected_constraint_3( "01t" );
   expected_constraint_3.tag_location( 2, 0, ORIENT_RIGHT );

   Constraint expected_constraint_4( "0t" );
   expected_constraint_4.tag_location( 2, 1, ORIENT_RIGHT );

   Solution expected_solution_1( expected_constraint_1, "bu" );
   Solution expected_solution_2( expected_constraint_2, "a" );
   Solution expected_solution_3( expected_constraint_3, "bu" );
   Solution expected_solution_4( expected_constraint_4, "a" );

   SolutionSet expected_solution_set;
   expected_solution_set.add( expected_solution_1 );
   expected_solution_set.add( expected_solution_2 );
   expected_solution_set.add( expected_solution_3 );
   expected_solution_set.add( expected_solution_4 );

   verbose && std::cout << "Board:\n" << board << std::endl;
   verbose && std::cout << "Rack:\n" << rack << std::endl;
   verbose && std::cout << "Dictionary:\n" << dict << std::endl;

   SolutionSet actual_solution_set;

   Solver solver;

   solver.solve( board, rack, dict, actual_solution_set );

   verbose && std::cout << "Expected solution set:\n" << expected_solution_set << std::endl;
   verbose && std::cout << "Actual solution set:\n" << actual_solution_set << std::endl;

   CPPUNIT_ASSERT( actual_solution_set == expected_solution_set );
}
