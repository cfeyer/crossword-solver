#ifndef RACK_H_
#define RACK_H_

#include <iosfwd>

#include <list>
#include <string>

class Rack
{
   public:

      Rack();

      int size() const;

      const std::list<std::string> * get_permutations( int perm_len ) const;

      friend std::ostream & operator << ( std::ostream & strm, const Rack & board );
      friend bool operator >> ( std::istream & strm, Rack & board );

   private:

      static const int MAX_SIZE = 7;

      static const char EMPTY = '-';

      char m_tile[MAX_SIZE];
      int m_size;

      void clear();

      void generate_permutations();

      // Array of lists of permutations.  List [0] contains all permutations of
      // length 1, list [1] all permutations of length 2, and so on.
      std::list<std::string> m_permutations[MAX_SIZE];

};

std::ostream & operator << ( std::ostream & strm, const Rack & board );
bool operator >> ( std::istream & strm, Rack & board );

#endif /*RACK_H_*/
