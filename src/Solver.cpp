#include "Solver.h"

#include <iostream>

#include "Board.h"
#include "Rack.h"
#include "Dictionary.h"
#include "SolutionSet.h"
#include "Constraint.h"


void Solver::solve( const Board & board,
                    const Rack & rack,
                    const Dictionary & dict,
                    SolutionSet & soln_set )
{
   soln_set.clear();
   solve_board( board, rack, dict, soln_set );
}


void Solver::solve_board( const Board & board,
                          const Rack & rack,
                          const Dictionary & dict,
                          SolutionSet & soln_set )
{
   for( int row = 0; row < board.height(); row++ )
   {
      for( int col = 0; col < board.width(); col++ )
      {
         solve_square( board, rack, dict, soln_set, row, col );
      }
   }
}


void Solver::solve_square( const Board & board,
                           const Rack & rack,
                           const Dictionary & dict,
                           SolutionSet & soln_set,
                           int row,
                           int col )
{
   if( board.get_tile( row, col ) == Board::TILE_EMPTY )
   {
      solve_square_right( board, rack, dict, soln_set, row, col );
      solve_square_down( board, rack, dict, soln_set, row, col );
   }
}


void Solver::solve_square_right( const Board & board,
                                 const Rack & rack,
                                 const Dictionary & dict,
                                 SolutionSet & soln_set,
                                 int row,
                                 int col )
{
   const int rack_size = rack.size();

   bool in_contact = false;

   int cursor_offset = -1;

   Constraint constraint;
   constraint.tag_location( row, col, ORIENT_RIGHT );

   //
   // Figure out if a tile played here would have any
   // existing tiles right before it.
   //
   while( (col + cursor_offset) >= 0 && board.get_tile( row, col + cursor_offset ) != Board::TILE_EMPTY )
   {
      in_contact = true;
      constraint.prepend( board.get_tile( row, col + cursor_offset ) );
      constraint.tag_location( row, col + cursor_offset, ORIENT_RIGHT );
      cursor_offset--;
   }

   cursor_offset = 0;

   //
   // As long as they fit on the board, add tile wildcard to the
   // primary constraint for every tile in our rack.
   //
   for( int num_tiles_played = 1;
        num_tiles_played <= rack_size;
        num_tiles_played++ )
   {
      char wildcard_symbol = '0' + (num_tiles_played - 1);

      if( (col + cursor_offset) < board.width() )
      {
         constraint.append( wildcard_symbol );


         //
         // Check whether adding this new tile causes us to intersect
         // with any existing perpendicular words.  If it does, then
         // add a secondary constraint for this perpendicular word.
         //
         bool new_secondary_constraint = false;

         {
            Constraint secondary_constraint( wildcard_symbol );
            secondary_constraint.tag_location( row, col + cursor_offset, ORIENT_DOWN );

            int secondary_cursor_offset = -1;

            while( (row + secondary_cursor_offset) >= 0 &&
                   board.get_tile( row + secondary_cursor_offset, col + cursor_offset ) != Board::TILE_EMPTY )
            {
               new_secondary_constraint = true;
               char prefix = board.get_tile( row + secondary_cursor_offset, col + cursor_offset );
               secondary_constraint.prepend( board.get_tile( row + secondary_cursor_offset, col + cursor_offset ) );
               secondary_constraint.tag_location( row + secondary_cursor_offset, col + cursor_offset, ORIENT_DOWN );

               secondary_cursor_offset--;
            }

            secondary_cursor_offset = 1;

            while( (row + secondary_cursor_offset) < board.height() &&
                   board.get_tile( row + secondary_cursor_offset, col + cursor_offset ) != Board::TILE_EMPTY )
            {
               new_secondary_constraint = true;
               char suffix = board.get_tile( row + secondary_cursor_offset, col + cursor_offset );
               secondary_constraint.append( board.get_tile( row + secondary_cursor_offset, col + cursor_offset ) );
               secondary_cursor_offset++;
            }

            if( new_secondary_constraint == true )
            {
               in_contact = true;
               constraint.further_constrain( secondary_constraint );
            }
         }

         cursor_offset++;

         //
         // Figure out if this new tile would have any existing
         // tiles immediately following it.
         //
         while( (col + cursor_offset) < board.width() &&
                board.get_tile( row, col + cursor_offset ) != Board::TILE_EMPTY )
         {
            in_contact = true;

            char suffix = board.get_tile( row, col + cursor_offset );

            constraint.append( suffix );

            cursor_offset++;
         }

         //
         // If the word we'd form by playing a tile doesn't touch
         // any of the tiles already on the board, the word wouldn't be
         // playable, so move on.  If the word would touch existing tiles,
         // see if we can make a real word there with the tiles we have
         // in our rack.
         //
         if( in_contact == true )
         {
            const std::list<std::string> * p_play_possibilities = rack.get_permutations( num_tiles_played );

            if( p_play_possibilities != 0 )
            {
               std::list<std::string>::const_iterator iter = p_play_possibilities->begin();
               const std::list<std::string>::const_iterator end_iter = p_play_possibilities->end();

               while( iter != end_iter )
               {
                  const std::string & possibility = *iter;

                  Constraint::Disposition disposition = constraint.test( possibility, dict );

                  if( disposition == Constraint::CONSTR_PASS )
                  {
                     soln_set.add( Solution( constraint, possibility ) );
                     std::cout << "Solution: " << possibility << " " << constraint << std::endl;
                  }

                  iter++;
               }
            }
         }
      }
      //
      // If we can't fit N tiles on the board at this position, we can't
      // fit N+1 tiles on the board at this position, so move to next position.
      //
      else
      {
         break;
      }
   }
}


void Solver::solve_square_down( const Board & board,
                                const Rack & rack,
                                const Dictionary & dict,
                                SolutionSet & soln_set,
                                int row,
                                int col )
{
   const int rack_size = rack.size();

   bool in_contact = false;

   int cursor_offset = -1;

   Constraint constraint;
   constraint.tag_location( row, col, ORIENT_DOWN );

   //
   // Figure out if a tile played here would have any
   // existing tiles right before it.
   //
   while( (row + cursor_offset) >= 0 && board.get_tile( row + cursor_offset, col ) != Board::TILE_EMPTY )
   {
      in_contact = true;
      constraint.prepend( board.get_tile( row + cursor_offset, col ) );
      constraint.tag_location( row + cursor_offset, col, ORIENT_DOWN );
      cursor_offset--;
   }

   cursor_offset = 0;

   //
   // As long as they fit on the board, add tile wildcard to the
   // primary constraint for every tile in our rack.
   //
   for( int num_tiles_played = 1;
        num_tiles_played <= rack_size;
        num_tiles_played++ )
   {
      char wildcard_symbol = '0' + (num_tiles_played - 1);

      if( (row + cursor_offset) < board.height() )
      {
         constraint.append( wildcard_symbol );

         //
         // Check whether adding this new tile causes us to intersect
         // with any existing perpendicular words.  If it does, then
         // add a secondary constraint for this perpendicular word.
         //
         bool new_secondary_constraint = false;

         {
            Constraint secondary_constraint( wildcard_symbol );
            secondary_constraint.tag_location( row + cursor_offset, col, ORIENT_RIGHT );

            int secondary_cursor_offset = -1;

            while( (col + secondary_cursor_offset) >= 0 &&
                   board.get_tile( row + cursor_offset, col + secondary_cursor_offset ) != Board::TILE_EMPTY )
            {
               new_secondary_constraint = true;
               char prefix = board.get_tile( row + cursor_offset, col + secondary_cursor_offset );
               secondary_constraint.prepend( board.get_tile( row + cursor_offset, col + secondary_cursor_offset ) );
               secondary_constraint.tag_location( row + cursor_offset, col + secondary_cursor_offset, ORIENT_RIGHT );

               secondary_cursor_offset--;
            }

            secondary_cursor_offset = 1;

            while( (col + secondary_cursor_offset) < board.width() &&
                   board.get_tile( row + cursor_offset, col + secondary_cursor_offset ) != Board::TILE_EMPTY )
            {
               new_secondary_constraint = true;
               char suffix = board.get_tile( row + cursor_offset, col + secondary_cursor_offset );
               secondary_constraint.append( board.get_tile( row + cursor_offset, col + secondary_cursor_offset ) );
               secondary_cursor_offset++;
            }

            if( new_secondary_constraint == true )
            {
               in_contact = true;
               constraint.further_constrain( secondary_constraint );
            }
         }

         cursor_offset++;

         //
         // Figure out if this new tile would have any existing
         // tiles immediately following it.
         //
         while( (row + cursor_offset) < board.height() &&
                board.get_tile( row + cursor_offset, col ) != Board::TILE_EMPTY )
         {
            in_contact = true;

            char suffix = board.get_tile( row + cursor_offset, col );

            constraint.append( suffix );

            cursor_offset++;
         }

         //
         // If the word we'd form by playing a tile doesn't touch
         // any of the tiles already on the board, the word wouldn't be
         // playable, so move on.  If the word would touch existing tiles,
         // see if we can make a real word there with the tiles we have
         // in our rack.
         //
         if( in_contact == true )
         {
            const std::list<std::string> * p_play_possibilities = rack.get_permutations( num_tiles_played );

            if( p_play_possibilities != 0 )
            {
               std::list<std::string>::const_iterator iter = p_play_possibilities->begin();
               const std::list<std::string>::const_iterator end_iter = p_play_possibilities->end();

               while( iter != end_iter )
               {
                  const std::string & possibility = *iter;

                  Constraint::Disposition disposition = constraint.test( possibility, dict );

                  if( disposition == Constraint::CONSTR_PASS )
                  {
                     soln_set.add( Solution( constraint, possibility ) );
                     std::cout << "Solution: " << possibility << " " << constraint << std::endl;
                  }

                  iter++;
               }
            }
         }
      }
      //
      // If we can't fit N tiles on the board at this position, we can't
      // fit N+1 tiles on the board at this position, so move to next position.
      //
      else
      {
         break;
      }
   }
}

