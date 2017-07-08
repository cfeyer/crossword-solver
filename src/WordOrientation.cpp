#include "WordOrientation.h"

#include <iostream>

std::ostream & operator << ( std::ostream & strm, WordOrientation orientation )
{
   switch( orientation )
   {
      case ORIENT_NULL:
         strm << "ORIENT_NULL";
         break;

      case ORIENT_RIGHT:
         strm << "RIGHT";
         break;

      case ORIENT_DOWN:
         strm << "DOWN";
         break;

      default:
         strm << "(unrecognized enum WordOrientation=" << static_cast<int>(orientation);
   }

   return strm;
}

