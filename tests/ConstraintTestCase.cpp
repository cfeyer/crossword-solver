#include "ConstraintTestCase.h"

#include "Constraint.h"
#include "Dictionary.h"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION( ConstraintTestCase );

void ConstraintTestCase::setUp()
{
}

/*void ConstraintTestCase::example()
{
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
  CPPUNIT_ASSERT( 1 == 0 );
  CPPUNIT_ASSERT( 1 == 1 );
}*/


void ConstraintTestCase::test_empty()
{
   Dictionary dict;

   Constraint constraint;

   Constraint::Disposition dispo = constraint.test( "", dict );

   CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_PRIMARY );
}


void ConstraintTestCase::test_primary_succeeds_no_secondaries()
{
   Dictionary dict;
   std::istringstream strm( "llama" );
   strm >> dict;

   Constraint constraint( "lla0a" );

   Constraint::Disposition dispo = constraint.test( "m", dict );

   CPPUNIT_ASSERT( dispo == Constraint::CONSTR_PASS );
}


void ConstraintTestCase::test_primary_fails_no_secondaries()
{
   Dictionary dict;
   std::istringstream strm( "llama" );
   strm >> dict;

   Constraint constraint( "lla0a" );

   Constraint::Disposition dispo = constraint.test( "z", dict );

   CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_PRIMARY );
}


void ConstraintTestCase::test_primary_succeeds_secondary_fails()
{
   Dictionary dict;
   std::istringstream strm( "llama" );
   strm >> dict;

   const std::string subst( "m" );

   Constraint secondary_constraint( "goos0" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = secondary_constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_PRIMARY );
   }

   Constraint constraint( "lla0a" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_PASS );
   }

   constraint.further_constrain( secondary_constraint );

   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_SECONDARY );
   }
}


void ConstraintTestCase::test_primary_succeeds_secondary_succeeds()
{
   Dictionary dict;
   std::istringstream strm( "goose\ngus" );
   strm >> dict;

   const std::string subst( "g" );

   Constraint secondary_constraint( "0oose" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = secondary_constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_PASS );
   }

   Constraint constraint( "0us" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_PASS );
   }

   constraint.further_constrain( secondary_constraint );

   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_PASS );
   }
}


void ConstraintTestCase::test_primary_fails_secondary_fails()
{
   Dictionary dict;
   std::istringstream strm( "goose" );
   strm >> dict;

   const std::string subst( "l" );

   Constraint secondary_constraint( "0oose" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = secondary_constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_PRIMARY );
   }

   Constraint constraint( "0oose" );
   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_PRIMARY );
   }

   constraint.further_constrain( secondary_constraint );

   {
      Constraint::Disposition dispo = Constraint::CONSTR_ERROR;
      dispo = constraint.test( subst, dict );
      CPPUNIT_ASSERT( dispo == Constraint::CONSTR_FAIL_SECONDARY );
   }
}


void ConstraintTestCase::test_constraint_degree_0()
{
   Constraint constraint;

   CPPUNIT_ASSERT_EQUAL( 0, constraint.degree() );
}


void ConstraintTestCase::test_constraint_degree_1()
{
   Constraint constraint( "asdf" );

   CPPUNIT_ASSERT_EQUAL( 1, constraint.degree() );
}


void ConstraintTestCase::test_constraint_degree_2()
{
   Constraint constraint( "asdf" );
   constraint.further_constrain( Constraint("qwerty") );

   CPPUNIT_ASSERT_EQUAL( 2, constraint.degree() );
}


void ConstraintTestCase::test_constraint_degree_3()
{
   Constraint constraint( "asdf" );
   constraint.further_constrain( Constraint("qwerty") );
   constraint.further_constrain( Constraint("jkl") );

   CPPUNIT_ASSERT_EQUAL( 3, constraint.degree() );
}


void ConstraintTestCase::test_equality_primary_constraint_only()
{
   Constraint c1;

   CPPUNIT_ASSERT( c1 == c1 );

   Constraint c2;

   CPPUNIT_ASSERT( c1 == c2 );

   Constraint c3( "cat" );

   CPPUNIT_ASSERT( c3 == c3 );

   Constraint c4( "cat" );

   CPPUNIT_ASSERT( c3 == c4 );
   CPPUNIT_ASSERT( c4 == c3 );

   Constraint c5( "dog" );
   Constraint c6( "dog" );

   CPPUNIT_ASSERT( c5 == c6 );
   CPPUNIT_ASSERT( c6 == c5 );

   CPPUNIT_ASSERT( ( c1 == c3 ) == false );
   CPPUNIT_ASSERT( ( c3 == c1 ) == false );

   CPPUNIT_ASSERT( ( c3 == c5 ) == false );
   CPPUNIT_ASSERT( ( c5 == c3 ) == false );

   c5.tag_location( 1, 2, ORIENT_DOWN );
   CPPUNIT_ASSERT( ( c5 == c6 ) == false );
   CPPUNIT_ASSERT( ( c6 == c5 ) == false );

   c6.tag_location( 1, 2, ORIENT_RIGHT );
   CPPUNIT_ASSERT( ( c5 == c6 ) == false );
   CPPUNIT_ASSERT( ( c6 == c5 ) == false );

   c6.tag_location( 1, 9, ORIENT_DOWN );
   CPPUNIT_ASSERT( ( c5 == c6 ) == false );
   CPPUNIT_ASSERT( ( c6 == c5 ) == false );

   c6.tag_location( 9, 2, ORIENT_DOWN );
   CPPUNIT_ASSERT( ( c5 == c6 ) == false );
   CPPUNIT_ASSERT( ( c6 == c5 ) == false );

   c6.tag_location( 1, 2, ORIENT_DOWN );
   CPPUNIT_ASSERT( ( c5 == c6 ) );
   CPPUNIT_ASSERT( ( c6 == c5 ) );
}


void ConstraintTestCase::test_equality_w_secondary_constraints()
{
   Constraint c1( "cat" );
   c1.tag_location( 1, 2, ORIENT_DOWN );

   CPPUNIT_ASSERT( c1 == c1 );

   Constraint c2( "cat" );
   c2.tag_location( 1, 2, ORIENT_DOWN );

   CPPUNIT_ASSERT( c1 == c2 );

   c1.further_constrain( c2 );

   CPPUNIT_ASSERT( ( c1 == c2 ) == false );

   c2.further_constrain( c2 );

   CPPUNIT_ASSERT( c1 == c2 );

   Constraint c3( "dog" );
   c3.tag_location( 5, 6, ORIENT_DOWN );

   Constraint c4( "dog" );
   c4.tag_location( 5, 6, ORIENT_RIGHT );

   c1.further_constrain( c3 );
   CPPUNIT_ASSERT( ( c1 == c2 ) == false );

   c2.further_constrain( c4 );
   CPPUNIT_ASSERT( ( c1 == c2 ) == false );

   Constraint c5( "bird" );
   Constraint c6( "bird" );

   CPPUNIT_ASSERT( c5 == c6 );

   c5.further_constrain( Constraint( "dog" ) );
   c6.further_constrain( Constraint( "cat" ) );

   CPPUNIT_ASSERT( ( c5 == c6 ) == false );

   c5.further_constrain( Constraint( "cat" ) );
   c6.further_constrain( Constraint( "dog" ) );

   CPPUNIT_ASSERT( c5 == c6 );
}


void ConstraintTestCase::test_less_than_primary_constraint_only()
{
   Constraint c1;

   CPPUNIT_ASSERT( ( c1 < c1 ) == false );

   Constraint c2;

   CPPUNIT_ASSERT( ( c1 < c2 ) == false );

   Constraint cat( "cat" );
   CPPUNIT_ASSERT( ( cat < cat ) == false );
   CPPUNIT_ASSERT( c1 < cat );
   CPPUNIT_ASSERT( ( cat < c1 ) == false );

   Constraint dog( "dog" );
   CPPUNIT_ASSERT( ( dog < dog ) == false );
   CPPUNIT_ASSERT( c1 < dog );
   CPPUNIT_ASSERT( ( dog < c1 ) == false );

   CPPUNIT_ASSERT( cat < dog );
   CPPUNIT_ASSERT( ( dog < cat ) == false );

   c1.tag_location( 0, 0, ORIENT_RIGHT );
   CPPUNIT_ASSERT( ( c1 < c2 ) == false );
   CPPUNIT_ASSERT( c2 < c1 );

   c2.tag_location( 0, 0, ORIENT_DOWN );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c2.tag_location( 0, 1, ORIENT_RIGHT );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c2.tag_location( 0, 1, ORIENT_DOWN );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c2.tag_location( 1, 0, ORIENT_RIGHT );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c2.tag_location( 1, 0, ORIENT_DOWN );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c1.tag_location( 0, 1, ORIENT_RIGHT );
   c2.tag_location( 1, 0, ORIENT_RIGHT );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c1.tag_location( 0, 1, ORIENT_DOWN );
   c2.tag_location( 1, 0, ORIENT_RIGHT );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );

   c1.tag_location( 0, 1, ORIENT_RIGHT );
   c2.tag_location( 1, 0, ORIENT_DOWN );
   CPPUNIT_ASSERT( c1 < c2 );
   CPPUNIT_ASSERT( ( c2 < c1 ) == false );
}


void ConstraintTestCase::test_less_than_w_secondary_constraints()
{
   CPPUNIT_FAIL( "Test not implemented" );
}

