#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iosfwd>
#include <string>

#include "Constraint.h"

class Solution
{
   public:

      Solution();

      Solution( const Constraint & constraint, const std::string & tiles );

      const Constraint & constraint() const;

      bool operator == ( const Solution & rhs ) const;
      bool operator < ( const Solution & rhs ) const;

      friend std::ostream & operator << ( std::ostream & strm, const Solution & soln );

   private:

      std::string m_tiles;
      Constraint m_constraint;
};

std::ostream & operator << ( std::ostream & strm, const Solution & soln );

#endif /*SOLUTION_H_*/
