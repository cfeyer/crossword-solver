
#ifndef CPP_UNIT_SOLVER_TESTS_H
#define CPP_UNIT_SOLVER_TESTS_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class SolverTests : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( SolverTests );
  CPPUNIT_TEST( test_solver_ctor );
  CPPUNIT_TEST( test_solve_simple_board_1 );
  CPPUNIT_TEST( test_solve_simple_board_2 );
  CPPUNIT_TEST( test_solve_simple_board_3 );
  CPPUNIT_TEST( test_solve_simple_board_4 );
  CPPUNIT_TEST( test_solve_simple_board_5 );
  CPPUNIT_TEST( test_solve_medium_board_1 );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();

private:

  void test_solver_ctor();
  void test_solve_simple_board_1();
  void test_solve_simple_board_2();
  void test_solve_simple_board_3();
  void test_solve_simple_board_4();
  void test_solve_simple_board_5();
  void test_solve_medium_board_1();
};


#endif
