#include "Solution.h"

#include <ostream>

Solution::Solution()
{
}

Solution::Solution( const Constraint & constraint, const std::string & tiles ) :
   m_tiles( tiles ),
   m_constraint( constraint )
{
}


const Constraint & Solution::constraint() const
{
   return m_constraint;
}


bool Solution::operator == ( const Solution & rhs ) const
{
   const Solution & lhs = *this;

   bool eq = false;

   eq = ( lhs.m_constraint == rhs.m_constraint ) &&
        ( lhs.m_tiles == rhs.m_tiles );

   return eq;
}


bool Solution::operator < ( const Solution & rhs ) const
{
   const Solution & lhs = *this;

   bool lt = false;

   if( lhs.m_constraint < rhs.m_constraint )
   {
      lt = true;
   }
   else if( lhs.m_constraint == rhs.m_constraint )
   {
      if( lhs.m_tiles < rhs.m_tiles )
      {
         lt = true;
      }
   }

   return lt;
}


std::ostream & operator << ( std::ostream & strm, const Solution & soln )
{
   strm << "(soln "
        << "'" << soln.m_tiles << "' --> "
        << soln.m_constraint << " --> "
        << "{'" << soln.m_constraint.substitute( soln.m_tiles ) << "'";

   std::set<Constraint>::const_iterator secondary_iter = soln.m_constraint.secondary_begin();
   const std::set<Constraint>::const_iterator secondary_end_iter = soln.m_constraint.secondary_end();

   while( secondary_iter != secondary_end_iter )
   {
      const Constraint & secondary_constraint = *secondary_iter;
      strm << " '" << secondary_constraint.substitute( soln.m_tiles ) << "'";
      secondary_iter++;
   }

   strm << "} ";

   strm << ")";

   return strm;
}

