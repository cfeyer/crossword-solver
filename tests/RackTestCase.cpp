#include "RackTestCase.h"

#include "Rack.h"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION( RackTestCase );

void RackTestCase::setUp()
{
}

/*void RackTestCase::example()
{
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
  CPPUNIT_ASSERT( 1 == 0 );
  CPPUNIT_ASSERT( 1 == 1 );
}*/


void RackTestCase::test_empty()
{
   Rack rack;

   CPPUNIT_ASSERT_EQUAL( 0, rack.size() );

   for( int size = 1; size <= 7; size++ )
   {
      CPPUNIT_ASSERT( rack.get_permutations( size ) == 0 );
   }
}


void RackTestCase::test_one_tile()
{
   Rack rack;

   std::istringstream strm( "a" );

   strm >> rack;

   CPPUNIT_ASSERT_EQUAL( 1, rack.size() );

   const std::list<std::string> * p_len_1_perms = rack.get_permutations( 1 );
   CPPUNIT_ASSERT( p_len_1_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), p_len_1_perms->size() );

   for( int size = 2; size <= 7; size++ )
   {
      CPPUNIT_ASSERT( rack.get_permutations( size ) == 0 );
   }
}


void RackTestCase::test_two_unique_tiles()
{
   Rack rack;

   std::istringstream strm( "ab" );

   strm >> rack;

   CPPUNIT_ASSERT_EQUAL( 2, rack.size() );

   const std::list<std::string> * p_len_1_perms = rack.get_permutations( 1 );
   CPPUNIT_ASSERT( p_len_1_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), p_len_1_perms->size() );

   const std::list<std::string> * p_len_2_perms = rack.get_permutations( 2 );
   CPPUNIT_ASSERT( p_len_2_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), p_len_2_perms->size() );

   for( int size = 3; size <= 7; size++ )
   {
      CPPUNIT_ASSERT( rack.get_permutations( size ) == 0 );
   }
}


void RackTestCase::test_three_unique_tiles()
{
   Rack rack;

   std::istringstream strm( "abc" );

   strm >> rack;

   CPPUNIT_ASSERT_EQUAL( 3, rack.size() );

   const std::list<std::string> * p_len_1_perms = rack.get_permutations( 1 );
   CPPUNIT_ASSERT( p_len_1_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(3), p_len_1_perms->size() );

   const std::list<std::string> * p_len_2_perms = rack.get_permutations( 2 );
   CPPUNIT_ASSERT( p_len_2_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(6), p_len_2_perms->size() );

   const std::list<std::string> * p_len_3_perms = rack.get_permutations( 3 );
   CPPUNIT_ASSERT( p_len_3_perms != 0 );
   CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(6), p_len_3_perms->size() );

   for( int size = 4; size <= 7; size++ )
   {
      CPPUNIT_ASSERT( rack.get_permutations( size ) == 0 );
   }
}


void RackTestCase::test_seven_unique_tiles()
{
   Rack rack;

   std::istringstream strm( "abcdefg" );

   strm >> rack;

   CPPUNIT_ASSERT_EQUAL( 7, rack.size() );

   for( int size = 1; size <= 7; size++ )
   {
      CPPUNIT_ASSERT( rack.get_permutations( size ) != 0 );
   }
}
