
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
      void handleUpdateBoard();
      void handlePrintBoard();
      void runGame1();
      void runGame2();
      void runGame3();
      void runGame();
      bool fromInput;
      int output_mode, board_type;
      int rows, columns;
      int inputi;
      float inputf;
      float newDensity;
      char inputc;
      board default_board;
      board_normal board1;
      board_mirror board2;
      board_torus board3;
  };
}
