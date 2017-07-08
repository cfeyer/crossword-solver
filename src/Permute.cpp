#include "Permute.h"

#include <iostream>

void Permute::permute_all_lengths( const std::string & free_objects,
                                   std::set<std::string> & permutations )
{
   permutations.clear();
   permute_all_lengths( free_objects, permutations, "" );
}


void Permute::permute_all_lengths( const std::string & free_objects,
                                   std::set<std::string> & permutations,
                                   const std::string & prefix_sequence )
{
   if( free_objects.empty() == false )
   {
      for( int free_obj_index = 0; free_obj_index < free_objects.size(); free_obj_index++ )
      {
         char current_object = free_objects.at( free_obj_index );

         if( current_object != '?' )
         {
            char suffix = current_object;

            std::string this_new_permutation = prefix_sequence + suffix;

            permutations.insert( this_new_permutation );

            std::string objects_still_free = free_objects.substr( 0, free_obj_index ) + free_objects.substr( free_obj_index+1 );

            permute_all_lengths( objects_still_free, permutations, this_new_permutation );
         }
         else
         {
            for( char suffix = 'a'; suffix <= 'z'; suffix++ )
            {
               std::string this_new_permutation = prefix_sequence + suffix;

               permutations.insert( this_new_permutation );

               std::string objects_still_free = free_objects.substr( 0, free_obj_index ) + free_objects.substr( free_obj_index+1 );

               permute_all_lengths( objects_still_free, permutations, this_new_permutation );
            }
         }

      }
   }
}

