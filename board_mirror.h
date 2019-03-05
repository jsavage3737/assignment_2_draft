#ifndef BOARD_H
#define BOARD_H
#include "board.h"
#endif

using namespace std;

namespace hw2{
  class board_mirror:public board {
    public:
      int count_neighbors(int row, int column);
      void update_board();
  };
}
