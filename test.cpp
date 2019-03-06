#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "board_normal.h"
#include "board_torus.h"
#include "board_mirror.h"
#include "game.h"
using namespace hw2;
using namespace std;

int main(int argc, char *argv[]){
  // game board functionality testing
  /*srand(time(NULL));
  // initializing
  int numRows = 5;
  int numCols = 10;
  float density = 0.5;
  board_normal GameBoard;
  GameBoard.setRows(numRows);
  GameBoard.setColumns(numCols);
  GameBoard.setDensity(density);

  // configuring objects
  GameBoard.generate_new_temp();
  GameBoard.generate_from_input();
  GameBoard.printBoard();

  for (int step=0; step<10; step++){
    cout << step+1 << endl;
    GameBoard.update_board();
    GameBoard.printBoard();
  }*/

/*
  // file io testing
  board_mirror board;
  board.generate_from_file();
  board.update_board();
  board.printBoard();
  board.printTemp();*/
  game game;
  game.initializeGame();
  game.runGame();

  // main implementation teseting

}
