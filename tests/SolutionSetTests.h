
#ifndef CPP_UNIT_SOLUTION_SET_TESTS_H
#define CPP_UNIT_SOLUTION_SET_TESTS_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class SolutionSetTests : public CPPUNIT_NS::TestFixture
{
   CPPUNIT_TEST_SUITE( SolutionSetTests );
   CPPUNIT_TEST( test_solution_set_ctor );
   CPPUNIT_TEST( test_equality );
   CPPUNIT_TEST_SUITE_END();

   public:

      void setUp();

   protected:

     void test_solution_set_ctor();
     void test_equality();
};


#endif
