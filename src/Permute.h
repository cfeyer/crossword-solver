#ifndef PERMUTE_H_
#define PERMUTE_H_

#include <string>
#include <set>

class Permute
{
   public:

      static void permute_all_lengths( const std::string & free_objects,
                                       std::set<std::string> & permutations );

   private:


      static void permute_all_lengths( const std::string & free_objects,
                                       std::set<std::string> & permutations,
                                       const std::string & prefix_sequence );
};

#endif /*PERMUTE_H_*/
