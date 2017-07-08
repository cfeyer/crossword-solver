
#ifndef CPP_UNIT_BOARD_TEST_CASE_H
#define CPP_UNIT_BOARD_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class BoardTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( BoardTestCase );
//  CPPUNIT_TEST( example );
  CPPUNIT_TEST( test_undefined_board );
  CPPUNIT_TEST( test_small_board );
  CPPUNIT_TEST( test_bigger_board );
  CPPUNIT_TEST_SUITE_END();

protected:
//  double m_value1;
//  double m_value2;

public:
  void setUp();

protected:
//  void example();
  void test_undefined_board();
  void test_small_board();
  void test_bigger_board();

//  void anotherExample();
//  void testAdd();
//  void testEquals();
};


#endif
