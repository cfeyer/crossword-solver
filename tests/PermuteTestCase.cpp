#include "PermuteTestCase.h"

#include "Permute.h"

#include <string>
#include <set>

CPPUNIT_TEST_SUITE_REGISTRATION( PermuteTestCase );

/*void PermuteTestCase::example()
{
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
  CPPUNIT_ASSERT( 1 == 0 );
  CPPUNIT_ASSERT( 1 == 1 );
}*/

void PermuteTestCase::test_null()
{
   const std::string input( "" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(0), output.size() );
}

void PermuteTestCase::test_single_object()
{
   const std::string input( "a" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT( output.find( "a" ) != output.end() );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), output.size() );
}

void PermuteTestCase::test_two_unique_objects()
{
   const std::string input( "ab" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT( output.find( "a" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "b" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ab" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ba" ) != output.end() );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(4), output.size() );
}

void PermuteTestCase::test_two_identical_objects()
{
   const std::string input( "aa" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT( output.find( "a" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "aa" ) != output.end() );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), output.size() );
}

void PermuteTestCase::test_three_unique_objects()
{
   const std::string input( "abc" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT( output.find( "a" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ab" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ac" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "abc" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "acb" ) != output.end() );

   CPPUNIT_ASSERT( output.find( "b" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ba" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "bc" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "bac" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "bca" ) != output.end() );

   CPPUNIT_ASSERT( output.find( "c" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "ca" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "cb" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "cab" ) != output.end() );
   CPPUNIT_ASSERT( output.find( "cba" ) != output.end() );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(15), output.size() );
}


void PermuteTestCase::test_single_wildcard()
{
   const std::string input( "?" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(26), output.size() );

   for( char letter = 'a'; letter <= 'z'; letter++ )
   {
      std::string str;
      str = str + letter;
      CPPUNIT_ASSERT( output.find( str ) != output.end() );
   }
}


void PermuteTestCase::test_two_wildcards()
{
   const std::string input( "??" );
   std::set<std::string> output;

   Permute::permute_all_lengths( input, output );

   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(702), output.size() );
}



/*void PermuteTestCase::anotherExample()
{
  CPPUNIT_ASSERT (1 == 2);
}*/

void PermuteTestCase::setUp()
{
//  m_value1 = 2.0;
//  m_value2 = 3.0;
}

/*void PermuteTestCase::testAdd()
{
  double result = m_value1 + m_value2;
  CPPUNIT_ASSERT( result == 6.0 );
}


void PermuteTestCase::testEquals()
{
  long* l1 = new long(12);
  long* l2 = new long(12);

  CPPUNIT_ASSERT_EQUAL( 12, 12 );
  CPPUNIT_ASSERT_EQUAL( 12L, 12L );
  CPPUNIT_ASSERT_EQUAL( *l1, *l2 );

  delete l1;
  delete l2;

  CPPUNIT_ASSERT( 12L == 12L );
  CPPUNIT_ASSERT_EQUAL( 12, 13 );
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 12.0, 11.99, 0.5 );
}*/
