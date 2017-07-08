#include "Dictionary.h"

#include <iostream>

Dictionary::Dictionary() :
   m_hit_count( 0 )
{
}


Dictionary::~Dictionary()
{
   std::cout << "Dictionary hit count: " << m_hit_count << std::endl;
}


bool Dictionary::contains( const std::string & word ) const
{
   m_hit_count++;

   bool found_word = false;

   std::set<std::string>::const_iterator iter = m_words.find( word );

   if( iter != m_words.end() )
   {
      found_word = true;
   }

   //std::cout << "Dictionary " << ( found_word ? "contains" : "does not contain" ) << " '" << word << "'." << std::endl;

   return found_word;
}


int Dictionary::hit_count() const
{
   return m_hit_count;
}


std::ostream & operator << ( std::ostream & strm, const Dictionary & dict )
{
   bool list_words = false;

   if( list_words == true )
   {
      std::set<std::string>::const_iterator iter = dict.m_words.begin();
      const std::set<std::string>::const_iterator end_iter = dict.m_words.end();

      while( iter != end_iter )
      {
         const std::string & word = *iter;
         strm << word << "\n";
         iter++;
      }
   }

   strm << dict.m_words.size() << " words in dictionary" << "\n";

   return strm;
}


bool operator >> ( std::istream & strm, Dictionary & dict )
{
   dict.m_words.clear();

   while( strm.good() )
   {
      std::string word;
      strm >> word;

      if( word.empty() == false )
      {
         dict.m_words.insert( word );
      }
   }

   return true;
}
