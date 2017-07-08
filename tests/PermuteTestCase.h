
#ifndef CPP_UNIT_PERMUTE_TEST_CASE_H
#define CPP_UNIT_PERMUTE_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class PermuteTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( PermuteTestCase );
//  CPPUNIT_TEST( example );
  CPPUNIT_TEST( test_null );
  CPPUNIT_TEST( test_single_object );
  CPPUNIT_TEST( test_two_unique_objects );
  CPPUNIT_TEST( test_two_identical_objects );
  CPPUNIT_TEST( test_three_unique_objects );
  CPPUNIT_TEST( test_single_wildcard );
  CPPUNIT_TEST( test_two_wildcards );
//  CPPUNIT_TEST( anotherExample );
//  CPPUNIT_TEST( testAdd );
//  CPPUNIT_TEST( testEquals );
  CPPUNIT_TEST_SUITE_END();

protected:
//  double m_value1;
//  double m_value2;

public:
  void setUp();

protected:
  void example();
  void test_null();
  void test_single_object();
  void test_two_unique_objects();
  void test_two_identical_objects();
  void test_three_unique_objects();
  void test_single_wildcard();
  void test_two_wildcards();

//  void anotherExample();
//  void testAdd();
//  void testEquals();
};


#endif
