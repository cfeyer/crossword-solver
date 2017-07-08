
#ifndef CPP_UNIT_SCORER_TESTS_H
#define CPP_UNIT_SCORER_TESTS_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class ScorerTests : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ScorerTests );
  CPPUNIT_TEST( test_scorer_ctor );
  CPPUNIT_TEST( test_invoke_scorer );
  CPPUNIT_TEST( test_oversimplified );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();

protected:

  void test_scorer_ctor();
  void test_invoke_scorer();

  void test_oversimplified();
};


#endif
