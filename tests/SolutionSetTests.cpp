#include "SolutionSetTests.h"

#include "SolutionSet.h"

CPPUNIT_TEST_SUITE_REGISTRATION( SolutionSetTests );

void SolutionSetTests::setUp()
{
}


void SolutionSetTests::test_solution_set_ctor()
{
   SolutionSet solution_set;
}


void SolutionSetTests::test_equality()
{
   SolutionSet soln_1;
   CPPUNIT_ASSERT( soln_1 == soln_1 );

   CPPUNIT_FAIL( "Test not implemented" );
}
