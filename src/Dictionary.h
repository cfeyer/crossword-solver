#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <string>
#include <set>
#include <iosfwd>

class Dictionary
{
   public:

      Dictionary();
      ~Dictionary();

      bool contains( const std::string & word ) const;

      int hit_count() const;

      friend std::ostream & operator << ( std::ostream & strm, const Dictionary & dict );

      friend bool operator >> ( std::istream & strm, Dictionary & dict );

   private:

      std::set<std::string> m_words;

      mutable int m_hit_count;
};

std::ostream & operator << ( std::ostream & strm, const Dictionary & dict );

bool operator >> ( std::istream & strm, Dictionary & dict );

#endif /*DICTIONARY_H_*/
