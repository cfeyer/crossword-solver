#ifndef SOLVER_H_
#define SOLVER_H_

class Board;
class Rack;
class Dictionary;
class SolutionSet;

class Solver
{
   public:

      static void solve( const Board & board,
                         const Rack & rack,
                         const Dictionary & dict,
                         SolutionSet & soln_set );

   private:

      static void solve_board( const Board & board,
                               const Rack & rack,
                               const Dictionary & dict,
                               SolutionSet & soln_set );

      static void solve_square( const Board & board,
                                const Rack & rack,
                                const Dictionary & dict,
                                SolutionSet & soln_set,
                                int row,
                                int col );

      static void solve_square_right( const Board & board,
                                      const Rack & rack,
                                      const Dictionary & dict,
                                      SolutionSet & soln_set,
                                      int row,
                                      int col );

      static void solve_square_down( const Board & board,
                                     const Rack & rack,
                                     const Dictionary & dict,
                                     SolutionSet & soln_set,
                                     int row,
                                     int col );
};

#endif /*SOLVER_H_*/
