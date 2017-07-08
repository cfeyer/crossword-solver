#include "BoardTestCase.h"

#include "Board.h"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION( BoardTestCase );

void BoardTestCase::setUp()
{
}

/*void BoardTestCase::example()
{
  CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
  CPPUNIT_ASSERT( 1 == 0 );
  CPPUNIT_ASSERT( 1 == 1 );
}*/


void BoardTestCase::test_undefined_board()
{
   Board board;

   CPPUNIT_ASSERT_EQUAL( 0, board.height() );
   CPPUNIT_ASSERT_EQUAL( 0, board.width() );

   CPPUNIT_ASSERT_EQUAL( '!', board.get_tile( 0, 0 ) );
}


void BoardTestCase::test_small_board()
{
   Board board;

   std::istringstream strm( "2 3\na b c\nd e f" );

   strm >> board;

   CPPUNIT_ASSERT_EQUAL( 2, board.height() );
   CPPUNIT_ASSERT_EQUAL( 3, board.width() );

   CPPUNIT_ASSERT_EQUAL( 'a', board.get_tile( 0, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'b', board.get_tile( 0, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'c', board.get_tile( 0, 2 ) );

   CPPUNIT_ASSERT_EQUAL( 'd', board.get_tile( 1, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'e', board.get_tile( 1, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'f', board.get_tile( 1, 2 ) );

   for( int row = -1; row < board.height()+1; row++ )
   {
//      CPPUNIT_ASSERT_EQUAL( Board::TILE_ILLEGAL, board.get_tile( row, -1 ) );
   }
}


void BoardTestCase::test_bigger_board()
{
   Board board;

   std::istringstream strm( "5 4\nq w e r\nt y u i\no p a s\nd f g h\nj k l z" );

   strm >> board;

   CPPUNIT_ASSERT_EQUAL( 5, board.height() );
   CPPUNIT_ASSERT_EQUAL( 4, board.width() );

   CPPUNIT_ASSERT_EQUAL( 'q', board.get_tile( 0, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'w', board.get_tile( 0, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'e', board.get_tile( 0, 2 ) );
   CPPUNIT_ASSERT_EQUAL( 'r', board.get_tile( 0, 3 ) );

   CPPUNIT_ASSERT_EQUAL( 't', board.get_tile( 1, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'y', board.get_tile( 1, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'u', board.get_tile( 1, 2 ) );
   CPPUNIT_ASSERT_EQUAL( 'i', board.get_tile( 1, 3 ) );

   CPPUNIT_ASSERT_EQUAL( 'o', board.get_tile( 2, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'p', board.get_tile( 2, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'a', board.get_tile( 2, 2 ) );
   CPPUNIT_ASSERT_EQUAL( 's', board.get_tile( 2, 3 ) );

   CPPUNIT_ASSERT_EQUAL( 'd', board.get_tile( 3, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'f', board.get_tile( 3, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'g', board.get_tile( 3, 2 ) );
   CPPUNIT_ASSERT_EQUAL( 'h', board.get_tile( 3, 3 ) );

   CPPUNIT_ASSERT_EQUAL( 'j', board.get_tile( 4, 0 ) );
   CPPUNIT_ASSERT_EQUAL( 'k', board.get_tile( 4, 1 ) );
   CPPUNIT_ASSERT_EQUAL( 'l', board.get_tile( 4, 2 ) );
   CPPUNIT_ASSERT_EQUAL( 'z', board.get_tile( 4, 3 ) );

}

