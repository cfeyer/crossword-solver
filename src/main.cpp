#include <iostream>
#include <fstream>
#include <string>

#include "Board.h"
#include "Rack.h"
#include "Dictionary.h"
#include "Solver.h"
#include "SolutionSet.h"

int main( int argc, char * argv[] )
{
   int exit_code = 1;

   if( argc == 4 )
   {
      const std::string board_path( argv[1] );
      const std::string rack_path( argv[2] );
      const std::string dictionary_path( argv[3] );

      std::cout << "board_path=" << board_path << std::endl;
      std::cout << "rack_path=" << rack_path << std::endl;
      std::cout << "dictionary_path=" << dictionary_path << std::endl;

      std::ifstream board_strm( board_path.c_str() );
      Board board;
      board_strm >> board;
      std::cout << board << std::endl;
      board_strm.close();

      std::ifstream rack_strm( rack_path.c_str() );
      Rack rack;
      rack_strm >> rack;
      std::cout << rack << std::endl;
      rack_strm.close();

      std::ifstream dictionary_stream( dictionary_path.c_str() );
      Dictionary dictionary;
      dictionary_stream >> dictionary;
      std::cout << dictionary << std::endl;
      dictionary_stream.close();

      SolutionSet solution_set;
      Solver::solve( board, rack, dictionary, solution_set );
      std::cout << "Solution Set:" << std::endl;
      std::cout << solution_set << std::endl;

      exit_code = 0;
   }
   else
   {
      std::cerr << "Expected args: board filename, rack filename, dictionary filename" << std::endl;
   }

   return exit_code;
}

