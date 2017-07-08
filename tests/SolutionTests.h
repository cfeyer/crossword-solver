
#ifndef CPP_UNIT_SOLUTION_TESTS_H
#define CPP_UNIT_SOLUTION_TESTS_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class SolutionTests : public CPPUNIT_NS::TestFixture
{
   CPPUNIT_TEST_SUITE( SolutionTests );
   CPPUNIT_TEST( test_solution_ctor );
   CPPUNIT_TEST( test_equality );
   CPPUNIT_TEST( test_less_than );
   CPPUNIT_TEST_SUITE_END();

   public:

      void setUp();

   protected:

     void test_solution_ctor();
     void test_equality();
     void test_less_than();
};


#endif
