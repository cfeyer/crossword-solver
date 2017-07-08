#include "ScorerTests.h"

#include "Scorer.h"
#include "Board.h"
#include "Solution.h"


CPPUNIT_TEST_SUITE_REGISTRATION( ScorerTests );

void ScorerTests::setUp()
{
}


void ScorerTests::test_scorer_ctor()
{
   Scorer scorer;
}


void ScorerTests::test_invoke_scorer()
{
   Scorer scorer;
   Board board;
   Solution solution;

   int score = 0;

   score = scorer.evaluate( board, solution );
}


void ScorerTests::test_oversimplified()
{
   CPPUNIT_FAIL( "Test not implemented" );
}
