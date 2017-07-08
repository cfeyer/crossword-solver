#ifndef WORD_ORIENTATION_H_
#define WORD_ORIENTATION_H_

#include <iosfwd>

enum WordOrientation
{
   ORIENT_NULL,
   ORIENT_RIGHT,
   ORIENT_DOWN
};

std::ostream & operator << ( std::ostream & strm, WordOrientation orientation );

#endif /*WORD_ORIENTATION_H_*/
