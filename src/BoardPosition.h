#ifndef BOARD_POSITION_H_
#define BOARD_POSITION_H_

class Board;

class BoardPosition
{
   public:

      BoardPosition left() const;
      BoardPosition right() const;
      BoardPosition up() const;
      BoardPosition down() const;
};

#endif /*BOARD_POSITION_H_*/
