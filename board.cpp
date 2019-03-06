#include "board.h"
#include <iostream>
#include <fstream>
using namespace hw2;
using namespace std;

 // used with fileparser class
void board::generate_from_file(){

  // establish board is running
  setRunning(true);

  // safely getting user input
  string filename, line;
  int r, c;
  int i=-1;

  setGeneration(0);

  while(true) { // continue until valid filename
    cout << "Enter file you wish to read: ";
    cin>>filename;
    ifstream FileStream;
    FileStream.open(filename);

    // first check if file can be loaded
    if (FileStream.is_open()){

      // read and set board dimensions
      FileStream >> r;
      FileStream >> c;
      setRows(r);
      setColumns(c);

      // building empty board
      node** temp = new node*[rows]; // creating pointer to array of pointers
      for (int x=0;x<rows;x++){ // interating through array of pointers to initialize concrete arrays
        temp[x] = new node[columns]; // array of anonymous objects
      }
      board_values = temp; // assigning new board to object

      // read in cell values and pass to new board
        while(getline(FileStream,line)){
        if (line[0] == 'X' || line[0] == '-') { // make sure line is valid
          for(int j=0; j<getColumns(); j++){ // treating each char as dif column
            if (line[j]=='X'){set_value(true, i, j);} // if cell from file is alive, set board cell to alive
          }
        }
        i++; // incrementing row
      }

      FileStream.close();
      break;
    }
    else{ // tell user if file isn't found
      cout << "File not found" << endl;
      cout << "Please try again" << endl;
    }
  }
  generate_new_temp(); // initializing temp board
}

//generating a board from user input
void board::generate_from_input(){
  setGeneration(0);
  float ran;

  node** temp = new node*[rows]; // creating pointer to array of pointers
  for (int r=0;r<rows;r++){ // interating through array of pointers to initialize concrete arrays
    temp[r] = new node[columns]; // array of anonymous objects
  }

  // initialize values randomly according to density
  for (int i=0;i<rows;i++){
    for (int j=0;j<columns;j++){
      ran = ((float)rand()/(RAND_MAX)); // generate random number (0,1)
      // if r is less than density, initialize cell as alive
      if (ran<density){
        temp[i][j].setState(true);
      }
    }
  }
  board_values = temp; // assign class pointer to newly created array
  generate_new_temp(); // create a temp
  setRunning(true); // start the game
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

void board::update_board(){return;}

// getters and setters
void board::setRunning(bool isRunning){running=isRunning;}
void board::setRows(int numRows){rows = numRows;}
void board::setColumns(int numCols){columns = numCols;}
void board::setGeneration(int numGen){generation = numGen;}
void board::setDensity(double newDensity){density=newDensity;}
void board::setOutputFilename(string newOutputFilename){outputFilename=newOutputFilename;}
void board::incrementGeneration(){generation++;}
bool board::getRunning(){return running;}
int board::getRows(){return rows;}
int board::getColumns(){return columns;}
int board::getGeneration(){return generation;}
float board::getDensity(){return density;}
string board::getOutputFilename(){return outputFilename;}

// display board to terminal
void board::printBoard(){
  cout << generation << endl;
  for (int r=0; r<rows; r++){ // draw each row
    for (int c=0; c<columns; c++){ // draw each column
      if (access_value(r,c)->getState()){cout << "X";} // draw x if node is alive
      else{cout << "-";}} // draw o if node is dead
  cout << endl;
  }
  cout << endl;
}

// saves board layout to file
void board::printBoardToFile(){
  // file object creation and opening file
  ofstream boardFile;
  boardFile.open (getOutputFilename());
  if (boardFile.is_open()){
    boardFile << generation << endl;
    for (int r=0; r<rows; r++){ // draw each row
      for (int c=0; c<columns; c++){ // draw each column
        if (access_value(r,c)->getState()){boardFile << "X";} // draw x if node is alive
        else{boardFile << "-";}} // draw o if node is dead
    boardFile << endl;
    }
    boardFile << endl;
  }

}
// prints the current temporary board (used mostly in testing)
void board::printTemp(){
  for (int r=0; r<rows; r++){ // draw each row
    for (int c=0; c<columns; c++){ // draw each column
      if (access_temp(r,c)->getState()){cout << "X";} // draw x if node is alive
      else{cout << "-";}  // draw - if node is dead
    }
    cout << endl;
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
