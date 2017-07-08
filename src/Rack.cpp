#include "Rack.h"

#include <iostream>
#include <set>

#include "Permute.h"

Rack::Rack()
{
   clear();
}


int Rack::size() const
{
   return m_size;
}


const std::list<std::string> * Rack::get_permutations( int perm_len ) const
{
   const std::list<std::string> * p_perm_list = 0;

   if( (perm_len > 0) && (perm_len <= m_size) )
   {
      p_perm_list = &( m_permutations[perm_len-1] );
   }

   return p_perm_list;
}


std::ostream & operator << ( std::ostream & strm, const Rack & rack )
{
   const bool show_headers = true;

   if( show_headers == true )
   {
      for( int pos = 0; pos < Rack::MAX_SIZE; pos++ )
      {
         strm << pos << " ";
      }

      strm << "\n";
   }

   for( int pos = 0; pos < Rack::MAX_SIZE; pos++ )
   {
      strm << rack.m_tile[pos] << " ";
   }
   strm << "\n";

   return strm;
}


bool operator >> ( std::istream & strm, Rack & rack )
{
   rack.clear();

   for( int pos = 0; pos < Rack::MAX_SIZE; pos++ )
   {
      char tile = Rack::EMPTY;
      strm >> tile;

      if( tile != Rack::EMPTY )
      {
         rack.m_tile[rack.m_size] = tile;
         rack.m_size++;
      }
   }

   rack.generate_permutations();

   return strm.good();
}


void Rack::clear()
{
   for( int pos = 0; pos < MAX_SIZE; pos++ )
   {
      m_tile[pos] = EMPTY;
   }

   m_size = 0;

   for( int perm_len = 1; perm_len <= MAX_SIZE; perm_len++ )
   {
      m_permutations[perm_len-1].clear();
   }
}


void Rack::generate_permutations()
{
   std::string objects;

   for( int obj_index = 0; obj_index < m_size; obj_index++ )
   {
      objects += m_tile[obj_index];
   }

   std::set<std::string> all_permutations;

   Permute::permute_all_lengths( objects, all_permutations );

   std::cout << "Rack has " << all_permutations.size() << " unique permutations" << std::endl;

   std::set<std::string>::iterator iter = all_permutations.begin();
   std::set<std::string>::iterator end_iter = all_permutations.end();

   while( iter != end_iter )
   {
      const std::string & permutation = *iter;
      int size = permutation.size();

      m_permutations[size-1].push_back( permutation );

      iter++;
   }
}
