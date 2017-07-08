#include "Board.h"

#include <iostream>


Board::Board() :
   m_width( 0 ),
   m_height( 0 ),
   m_square( 0 )
{
}


Board::~Board()
{
   deallocate();
}


int Board::width() const
{
   return m_width;
}


int Board::height() const
{
   return m_height;
}


char Board::get_tile( int row, int col ) const
{
   char tile = TILE_ILLEGAL;

   if( row >= 0 && row < m_height )
   {
      if( col >= 0 && col < m_width )
      {
         tile = m_square[row][col];
      }
   }

   return tile;
}


void Board::allocate( int height, int width )
{
   if( height > 0 && width > 0 )
   {
      m_height = height;
      m_width = width;

      m_square = new char * [m_height];

      for( int row = 0; row < m_height; row++ )
      {
         m_square[row] = new char[m_width];

         for( int col = 0; col < m_width; col++ )
         {
            m_square[row][col] = Board::TILE_EMPTY;
         }
      }
   }
}


void Board::deallocate()
{
   if( m_height > 0 && m_width > 0 )
   {
      for( int row = 0; row < m_height; row++ )
      {
         delete [] m_square[row];
         m_square[row] = 0;
      }

      delete [] m_square;
      m_square = 0;

      m_height = 0;
      m_width = 0;
   }
}


std::ostream & operator << ( std::ostream & strm, const Board & board )
{
   const bool show_headers = true;

   if( show_headers == true )
   {
      strm << "   ";

      for( int col = 0; col < board.width(); col++ )
      {
         strm << (col/10) << " ";
      }

      strm << "\n";

      strm << "   ";

      for( int col = 0; col < board.width(); col++ )
      {
         strm << (col%10) << " ";
      }

      strm << "\n";
   }
   strm << "\n";

   for( int row = 0; row < board.height(); row++ )
   {
      if( show_headers == true )
      {
         strm << (row/10) << (row%10) << " ";
      }

      for( int col = 0; col < board.width(); col++ )
      {
         strm << board.m_square[row][col] << " ";
      }

      strm << "\n";
   }

   return strm;
}

bool operator >> ( std::istream & strm, Board & board )
{
   int width = 0;
   int height = 0;

   strm >> height;
   strm >> width;

   board.deallocate();
   board.allocate( height, width );

   for( int row = 0; row < board.height(); row++ )
   {
      for( int col = 0; col < board.width(); col++ )
      {
         char tile = Board::TILE_EMPTY;
         strm >> tile;
         board.m_square[row][col] = tile;
      }
   }

   return strm.good();
}

