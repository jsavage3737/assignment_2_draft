#include "board.h"
#include <iostream>
using namespace hw2;
using namespace std;

 // used with fileparser class
void board::generate_from_file(int rows, int columns){
  return;
}

//generating a board from user input
void board::generate_from_input(int rows, int columns){

  node** temp = new node*[rows]; // creating pointer to array of pointers
  for (int r=0;r<rows;r++){ // interating through array of pointers to initialize concrete arrays
    temp[r] = new node[columns]; // array of anonymous objects
  }
  board_values = temp;
}

// generates blank temp board
// same process as above
void board::generate_new_temp(int rows, int columns){
  node** new_temp = new node*[rows];
  for (int r=0;r<rows;r++){
    new_temp[r] = new node[columns];
  }
  temp_board = new_temp;
}

node board::access_value(int row, int column){
  return board_values[row][column];
}

void board::access_temp(int row, int column, bool isAlive){
  temp_board[row][column] = node(isAlive);
}
