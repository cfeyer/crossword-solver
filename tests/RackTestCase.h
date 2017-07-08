
#ifndef CPP_UNIT_RACK_TEST_CASE_H
#define CPP_UNIT_RACK_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class RackTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( RackTestCase );
//  CPPUNIT_TEST( example );
  CPPUNIT_TEST( test_empty );
  CPPUNIT_TEST( test_one_tile );
  CPPUNIT_TEST( test_two_unique_tiles );
  CPPUNIT_TEST( test_three_unique_tiles );
  CPPUNIT_TEST( test_seven_unique_tiles );
  CPPUNIT_TEST_SUITE_END();

protected:
//  double m_value1;
//  double m_value2;

public:
  void setUp();

protected:
//  void example();
  void test_empty();
  void test_one_tile();
  void test_two_unique_tiles();
  void test_three_unique_tiles();
  void test_seven_unique_tiles();

//  void anotherExample();
//  void testAdd();
//  void testEquals();
};


#endif
