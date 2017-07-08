#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_

#include <string>
#include <iosfwd>
#include <set>

#include "WordOrientation.h"

class Dictionary;

class Constraint
{
   public:

      Constraint();
      Constraint( char pattern );
      Constraint( const std::string & pattern );

      void prepend( char new_prefix );
      void append( char new_suffix );

      void further_constrain( const Constraint & secondary_constraint );

      int degree() const;

      void tag_location( int row, int col, WordOrientation orientation );

      enum Disposition
      {
         CONSTR_ERROR,
         CONSTR_FAIL_SECONDARY,
         CONSTR_FAIL_PRIMARY,
         CONSTR_PASS
      };

      Disposition test( const std::string & substitutions, const Dictionary & dict ) const;

      std::string substitute( const std::string & wildcard_values, bool & success ) const;
      std::string substitute( const std::string & wildcard_values ) const;

      typedef std::set<Constraint>::const_iterator ConstSecondaryIter;

      ConstSecondaryIter secondary_begin() const;
      ConstSecondaryIter secondary_end() const;

      bool operator == ( const Constraint & rhs ) const;
      bool operator < ( const Constraint & rhs ) const;

      friend std::ostream & operator << ( std::ostream & strm, const Constraint & constraint );

   private:

      std::string m_pattern;
      std::set<Constraint> m_secondary;

      Disposition test_primary_constraint( const std::string & substitutions, const Dictionary & dict ) const;
      Disposition test_secondary_constraints( const std::string & substitutions, const Dictionary & dict ) const;

      int m_row;
      int m_col;
      WordOrientation m_orientation;
};

std::ostream & operator << ( std::ostream & strm, const Constraint & constraint );

#endif /*CONSTRAINT_H_*/
