#include "SolutionSet.h"

#include <ostream>

void SolutionSet::clear()
{
   m_solutions.clear();
}


void SolutionSet::add( const Solution & soln )
{
   //m_solutions.push_back( soln );
   m_solutions.insert( soln );
}


bool SolutionSet::operator == ( const SolutionSet & rhs ) const
{
   const SolutionSet & lhs = *this;

   bool eq = ( lhs.m_solutions == rhs.m_solutions );

   return eq;
}


std::ostream & operator << ( std::ostream & strm, const SolutionSet & soln_set )
{
   strm << soln_set.m_solutions.size() << " solutions: \n"
        << "{ \n";

   std::set<Solution>::const_iterator iter = soln_set.m_solutions.begin();
   std::set<Solution>::const_iterator end_iter = soln_set.m_solutions.end();

   while( iter != end_iter )
   {
      const Solution & soln = *iter;
      strm << soln << " \n";
      iter++;
   }

   strm << "} \n";

   return strm;
}
