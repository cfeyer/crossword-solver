#ifndef SOLUTION_SET_H_
#define SOLUTION_SET_H_

#include <iosfwd>
#include <set>

#include "Solution.h"

class SolutionSet
{
   public:

      void clear();

      void add( const Solution & soln );

      bool operator == ( const SolutionSet & rhs ) const;

      friend std::ostream & operator << ( std::ostream & strm, const SolutionSet & soln_set );

   private:

      std::set<Solution> m_solutions;
};

std::ostream & operator << ( std::ostream & strm, const SolutionSet & soln_set );

#endif /*SOLUTION_SET_H_*/
