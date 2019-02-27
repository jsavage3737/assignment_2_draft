#include "board.h"
#include <iostream>
using namespace hw2;
using namespace std;

 // used with fileparser class
void board::generate_from_file(){
  return;
}

//generating a board from user input
void board::generate_from_input(){

  node** temp = new node*[rows]; // creating pointer to array of pointers
  for (int r=0;r<rows;r++){ // interating through array of pointers to initialize concrete arrays
    temp[r] = new node[columns]; // array of anonymous objects
  }
  board_values = temp;
}

// generates blank temp board
// same process as above
void board::generate_new_temp(){
  node** new_temp = new node*[rows];
  for (int r=0;r<rows;r++){
    new_temp[r] = new node[columns];
  }
  temp_board = new_temp;
}

// retrieves node from board
node * board::access_value(int row, int column){
  node *temp = &board_values[row][column];
  return temp;
}

// returns pointer to node in temp
node * board::access_temp(int row, int column){
  node *temp = &temp_board[row][column];
  return temp;
}

// set active board node state
void board::set_value(bool isAlive, int row, int column){
  board_values[row][column].setState(isAlive);
}

// set temp node state
void board::set_temp(bool isAlive, int row, int column){
  temp_board[row][column].setState(isAlive);
}

// getters and setters
void board::setRows(int numRows){rows = numRows;}
void board::setColumns(int numCols){columns = numCols;}
int board::getRows(){return rows;}
int board::getColumns(){return columns;}

// display board to terminal
void board::printBoard(){
  cout << "|"; // add two dashes to account for walls
  for (int c=0; c<columns-1; c++){cout<< "--";} cout << "-|"<< endl; // write top boundary of board

  for (int r=0; r<rows; r++){ // draw each row
    cout << "|";
    for (int c=0; c<columns; c++){ // draw each column

      if (access_value(r,c)->getState()){cout << "X|";} // draw x if node is alive
      else{cout << "O|";}} // draw o if node is dead

    cout << endl << "|"; // start new line with wall
    for (int c=0; c<columns-1; c++){cout << "--";} // draw divider for "c" values
    cout << "-|" << endl; // draw final wall and progress to new line
  }
}

void board::printTemp(){
  cout << "|"; // add two dashes to account for walls
  for (int c=0; c<columns-1; c++){cout<< "--";} cout << "-|"<< endl; // write top boundary of board

  for (int r=0; r<rows; r++){ // draw each row
    cout << "|";
    for (int c=0; c<columns; c++){ // draw each column

      if (access_temp(r,c)->getState()){cout << "X|";} // draw x if node is alive
      else{cout << "O|";}} // draw o if node is dead

    cout << endl << "|"; // start new line with wall
    for (int c=0; c<columns-1; c++){cout << "--";} // draw divider for "c" values
    cout << "-|" << endl; // draw final wall and progress to new line
  }
}

// replace current board with temp and create new temp
void board::applyChanges(){
  for(int r=0; r<rows; r++){
      delete [] board_values[r];
  }
  delete[] board_values;
  board_values = temp_board;
  generate_new_temp();
}
