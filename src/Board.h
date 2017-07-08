#ifndef BOARD_H_
#define BOARD_H_

#include <iosfwd>

class BoardPosition;
class BoardSpace;

class Board
{
   public:

      Board();
      ~Board();

      int width() const;
      int height() const;

//      BoardSpace * get_space( const BoardPosition & coordinate );

      // Given the coordinates of a space on the board, returns the letter that
      // has been played at that space, or returns TILE_EMPTY if no tile has been
      // played at that space.  For blank tiles, the letter the tile was played
      // as is returned.
      char get_tile( int row, int col ) const;

      friend std::ostream & operator << ( std::ostream & strm, const Board & board );
      friend bool operator >> ( std::istream & strm, Board & board );

      static const char TILE_EMPTY = '-';
      static const char TILE_ILLEGAL = '!';

   private:

      void allocate( int height, int width );
      void deallocate();

      int m_width;
      int m_height;

      char ** m_square;

};

std::ostream & operator << ( std::ostream & strm, const Board & board );
bool operator >> ( std::istream & strm, Board & board );

#endif /*BOARD_H_*/
