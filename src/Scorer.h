#ifndef SCORER_H_
#define SCORER_H_

class Board;
class Solution;

class Scorer
{
   public:

      int evaluate( const Board & board, const Solution & solution ) const;
};

#endif /* SCORER_H_ */
