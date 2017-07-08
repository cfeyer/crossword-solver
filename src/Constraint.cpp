#include "Constraint.h"

#include <iostream>
#include "Dictionary.h"

Constraint::Constraint() :
   m_row( -1 ),
   m_col( -1 ),
   m_orientation( ORIENT_NULL )
{
}

Constraint::Constraint( char pattern ) :
   m_row( -1 ),
   m_col( -1 ),
   m_orientation( ORIENT_NULL )
{
   char buffer[2] = { pattern, '\0' };
   m_pattern = buffer;
}

Constraint::Constraint( const std::string & pattern ) :
   m_pattern( pattern ),
   m_row( -1 ),
   m_col( -1 ),
   m_orientation( ORIENT_NULL )
{
}

void Constraint::prepend( char new_prefix )
{
   m_pattern = new_prefix + m_pattern;
}


void Constraint::append( char new_suffix )
{
   m_pattern += new_suffix;
}


void Constraint::further_constrain( const Constraint & secondary_constraint )
{
   m_secondary.insert( secondary_constraint );
}


int Constraint::degree() const
{
   int deg = 0;

   if( m_pattern.empty() == false )
   {
      deg++;
   }

   deg += m_secondary.size();

   return deg;
}


void Constraint::tag_location( int row, int col, WordOrientation orientation )
{
   m_row = row;
   m_col = col;
   m_orientation = orientation;
}


Constraint::Disposition Constraint::test( const std::string & substitutions,
                                          const Dictionary & dict ) const
{
   Disposition dispo = CONSTR_ERROR;

   dispo = test_secondary_constraints( substitutions, dict );

   if( dispo == CONSTR_PASS )
   {
      dispo = test_primary_constraint( substitutions, dict );
   }

   return dispo;
}


std::string Constraint::substitute( const std::string & wildcard_values, bool & success ) const
{
   success = true;

   std::string result = m_pattern;

   const int pattern_size = m_pattern.size();
   const int wildcard_count = wildcard_values.size();

   for( int i = 0; i < pattern_size; i++ )
   {
      char & letter = result.at( i );

      bool letter_is_wildcard = (letter >= '0') && (letter <= '9');

      if( letter_is_wildcard == true )
      {
         int wildcard_index = letter - '0';

         if( wildcard_index < wildcard_count )
         {
            letter = wildcard_values.at( wildcard_index );
         }
         else
         {
            success = false;
         }
      }
   }

   return result;
}


std::string Constraint::substitute( const std::string & wildcard_values ) const
{
   bool success = false;
   std::string expr;
   expr = substitute( wildcard_values, success );
   return expr;
}


Constraint::ConstSecondaryIter Constraint::secondary_begin() const
{
   return m_secondary.begin();
}


Constraint::ConstSecondaryIter Constraint::secondary_end() const
{
   return m_secondary.end();
}


bool Constraint::operator == ( const Constraint & rhs ) const
{
   const Constraint & lhs = *this;

   bool eq = ( lhs.m_pattern == rhs.m_pattern ) &&
             ( lhs.m_row == rhs.m_row ) &&
             ( lhs.m_col == rhs.m_col ) &&
             ( lhs.m_orientation == rhs.m_orientation ) &&
             ( lhs.m_secondary == rhs.m_secondary );

   return eq;
}


bool Constraint::operator < ( const Constraint & rhs ) const
{
   const Constraint & lhs = *this;

   bool lt = false;

   if( lhs.m_row < rhs.m_row )
   {
      lt = true;
   }
   else if( lhs.m_row == rhs.m_row )
   {
      if( lhs.m_col < rhs.m_col )
      {
         lt = true;
      }
      else if( lhs.m_col == rhs.m_col )
      {
         if( lhs.m_orientation < rhs.m_orientation )
         {
            lt = true;
         }
         else if( lhs.m_orientation == rhs.m_orientation )
         {
            if( lhs.m_pattern < rhs.m_pattern )
            {
               lt = true;
            }
            else if( lhs.m_pattern == rhs.m_pattern )
            {
               if( lhs.m_secondary < rhs.m_secondary )
               {
                  lt = true;
               }
            }
         }
      }
   }

   // std::cout << "Constraint::operator < : '" << lhs << " < " << rhs << " --> " << lt << std::endl;

   return lt;
}


Constraint::Disposition Constraint::test_primary_constraint( const std::string & substitutions, const Dictionary & dict ) const
{
   Disposition dispo = CONSTR_FAIL_PRIMARY; 

   std::string word;

   bool subst_ok = false;

   word = substitute( substitutions, subst_ok );

   if( subst_ok == true )
   {
      if( dict.contains( word ) == true )
      {
         dispo = CONSTR_PASS;
      }
   }
   else
   {
      dispo = CONSTR_ERROR;
   }

   return dispo;
}


Constraint::Disposition Constraint::test_secondary_constraints( const std::string & substitutions, const Dictionary & dict ) const
{
   Disposition dispo = CONSTR_PASS;

   Constraint::ConstSecondaryIter constr_iter = m_secondary.begin();
   Constraint::ConstSecondaryIter constr_end_iter = m_secondary.end();

   while( constr_iter != constr_end_iter && dispo == CONSTR_PASS )
   {
      const Constraint & secondary_constraint = *constr_iter;

      dispo = secondary_constraint.test( substitutions, dict );

      constr_iter++;
   }

   if( dispo == CONSTR_FAIL_PRIMARY )
   {
      dispo = CONSTR_FAIL_SECONDARY;
   }

   return dispo;
}


std::ostream & operator << ( std::ostream & strm, const Constraint & constraint )
{
   strm << "(constraint r"
        << constraint.m_row << ",c" << constraint.m_col << "," << constraint.m_orientation << ","
        << "degree " << constraint.degree() << ","
        << "'" << constraint.m_pattern << "'";

   std::set<Constraint>::const_iterator constr_iter = constraint.m_secondary.begin();
   std::set<Constraint>::const_iterator constr_end_iter = constraint.m_secondary.end();

   while( constr_iter != constr_end_iter )
   {
      const Constraint & secondary_constraint = *constr_iter;
      strm << " " << secondary_constraint;
      constr_iter++;
   }

   strm << ")";
   return strm;
}

