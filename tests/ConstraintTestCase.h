
#ifndef CPP_UNIT_CONSTRAINT_TEST_CASE_H
#define CPP_UNIT_CONSTRAINT_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class ConstraintTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ConstraintTestCase );
//  CPPUNIT_TEST( example );
  CPPUNIT_TEST( test_empty );
  CPPUNIT_TEST( test_primary_succeeds_no_secondaries );
  CPPUNIT_TEST( test_primary_fails_no_secondaries );
  CPPUNIT_TEST( test_primary_succeeds_secondary_fails );
  CPPUNIT_TEST( test_primary_succeeds_secondary_succeeds );
  CPPUNIT_TEST( test_primary_fails_secondary_fails );
  CPPUNIT_TEST( test_constraint_degree_0 );
  CPPUNIT_TEST( test_constraint_degree_1 );
  CPPUNIT_TEST( test_constraint_degree_2 );
  CPPUNIT_TEST( test_constraint_degree_3 );
  CPPUNIT_TEST( test_equality_primary_constraint_only );
  CPPUNIT_TEST( test_equality_w_secondary_constraints );
  CPPUNIT_TEST( test_less_than_primary_constraint_only );
  CPPUNIT_TEST( test_less_than_w_secondary_constraints );
  CPPUNIT_TEST_SUITE_END();

protected:
//  double m_value1;
//  double m_value2;

public:
  void setUp();

protected:
//  void example();
  void test_empty();
  void test_primary_succeeds_no_secondaries();
  void test_primary_fails_no_secondaries();
  void test_primary_succeeds_secondary_fails();
  void test_primary_succeeds_secondary_succeeds();
  void test_primary_fails_secondary_fails();
  void test_constraint_degree_0();
  void test_constraint_degree_1();
  void test_constraint_degree_2();
  void test_constraint_degree_3();
  void test_equality_primary_constraint_only();
  void test_equality_w_secondary_constraints();
  void test_less_than_primary_constraint_only();
  void test_less_than_w_secondary_constraints();

//  void anotherExample();
//  void testAdd();
//  void testEquals();
};


#endif
