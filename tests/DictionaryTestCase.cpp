#include "DictionaryTestCase.h"

#include "Dictionary.h"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION( DictionaryTestCase );

void DictionaryTestCase::setUp()
{
}

/*void DictionaryTestCase::example()
{
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
  CPPUNIT_ASSERT( 1 == 0 );
  CPPUNIT_ASSERT( 1 == 1 );
}*/

void DictionaryTestCase::test_with_some_stuff()
{
   Dictionary dict;

   CPPUNIT_ASSERT( dict.contains( "apple" ) == false );
   CPPUNIT_ASSERT( dict.contains( "orange" ) == false );
   CPPUNIT_ASSERT( dict.contains( "pear" ) == false );
   CPPUNIT_ASSERT( dict.contains( "banana" ) == false );

   {
      std::istringstream strm( "apple\norange\npear" );
      strm >> dict;
   }

   CPPUNIT_ASSERT( dict.contains( "apple" ) == true );
   CPPUNIT_ASSERT( dict.contains( "orange" ) == true );
   CPPUNIT_ASSERT( dict.contains( "pear" ) == true );
   CPPUNIT_ASSERT( dict.contains( "banana" ) == false );
}


void DictionaryTestCase::test_hit_count()
{
   Dictionary dict;

   CPPUNIT_ASSERT_EQUAL( 0, dict.hit_count() );

   dict.contains( "dog" );

   CPPUNIT_ASSERT_EQUAL( 1, dict.hit_count() );

   dict.contains( "dog" );

   CPPUNIT_ASSERT_EQUAL( 2, dict.hit_count() );

   dict.contains( "dog" );
   dict.contains( "dog" );

   CPPUNIT_ASSERT_EQUAL( 4, dict.hit_count() );
}

