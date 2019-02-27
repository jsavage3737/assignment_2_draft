#include <iostream>
#include <fstream>
#include "board_normal.h"

using namespace hw2;
using namespace std;

int main(int argc, char *argv[]){

  // initializing
  int numRows = 5;
  int numCols = 10;
  board_normal GameBoard;
  GameBoard.setRows(numRows);
  GameBoard.setColumns(numCols);


  // tuning objects
  GameBoard.generate_new_temp();
  GameBoard.generate_from_input();

  // testing some functionality
  GameBoard.access_value(0,1)->setState(true);
  GameBoard.access_value(0,2)->setState(true);
  GameBoard.access_value(0,3)->setState(true);
  GameBoard.printBoard();

  GameBoard.update_board();
  GameBoard.printBoard();
  GameBoard.update_board();
  GameBoard.printBoard();
}
