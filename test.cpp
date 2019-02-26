#include <iostream>
#include <fstream>
#include "board.h"

using namespace hw2;
using namespace std;

int main(int argc, char *argv[]){

  node testNode(true);
  int rows = 2;
  int cols = 2;

  node board_test[rows][cols];

  for (int x=0; x<cols; x++){
    for (int y=0; y<rows; y++){
      cout << board_test[y][x].getState();
    }
  }

  board GameBoard;
  GameBoard.generate_from_input(2,2);
  cout << GameBoard.access_value(1,1).getState();
}
