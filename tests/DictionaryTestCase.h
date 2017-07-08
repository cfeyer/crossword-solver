
#ifndef CPP_UNIT_DICTIONARY_TEST_CASE_H
#define CPP_UNIT_DICTIONARY_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class DictionaryTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( DictionaryTestCase );
//  CPPUNIT_TEST( example );
  CPPUNIT_TEST( test_with_some_stuff );
  CPPUNIT_TEST( test_hit_count );
  CPPUNIT_TEST_SUITE_END();

protected:
//  double m_value1;
//  double m_value2;

public:
  void setUp();

protected:
//  void example();
  void test_with_some_stuff();
  void test_hit_count();

//  void anotherExample();
//  void testAdd();
//  void testEquals();
};


#endif
