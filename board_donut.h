#include "board.h"
using namespace std;

namespace hw2{
  class board_donut:public board {
    public:
      int count_neighbors(int row, int column);
      void update_board();
  };
}
