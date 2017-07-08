#include "SolutionTests.h"

#include "Solution.h"

CPPUNIT_TEST_SUITE_REGISTRATION( SolutionTests );

void SolutionTests::setUp()
{
}


void SolutionTests::test_solution_ctor()
{
   Solution solution;
}


void SolutionTests::test_equality()
{
   Solution soln_1;
   CPPUNIT_ASSERT( soln_1 == soln_1 );

   CPPUNIT_FAIL( "Test not implemented" );
}


void SolutionTests::test_less_than()
{
   Solution soln_1;
   CPPUNIT_ASSERT( ( soln_1 < soln_1 ) == false );

   CPPUNIT_FAIL( "Test not implemented" );
}
