
#ifndef BOARD_H
#define BOARD_H
#include "board.h"
#include "board_normal.h"
#include "board_torus.h"
#include "board_mirror.h"
#endif

#include<iostream>
using namespace std;

namespace hw2{
  class game{
    public:
      void initializeGame();
      int rows, columns;
      float inputf;
      char inputc;
      board board;
      bool enter;
    private:

  };
}
