#include "board_normal.h"
#include <iostream> // included for testing
using namespace hw2;
using namespace std;

// updates board with new node board_values
void board_normal::update_board(){
  bool oldState, newState;
  bool isSame=true;
  int neighbors;
  // for each cell
  for (int i=0; i<getRows(); i++){
    for (int j=0; j<getColumns(); j++){
      // evaluate whether cell is alive next iteration and store in temp
      neighbors = count_neighbors(i,j);
      oldState = access_value(i,j)->getState();
      newState = access_value(i,j)->updateState(neighbors);

      if (oldState!=newState){isSame=false;}
      set_temp(newState,i,j);
    }
  }
  //keeps same board if it wouldn't change
  if (!isSame){applyChanges();incrementGeneration();}
  else{setRunning(false);}
}

// determines number of neighbors for cell at row and column index
int board_normal::count_neighbors(int row, int column){
  int numNeighbors = 0;

  for (int i=row-1; i<=row+1; i++){ // for 3 rows centered on input index
    for (int j=column-1; j<=column+1; j++){ // for the 3 cols centered on input index

      // ignore the center cell
      if (i==row && j==column){continue;}

      // if indices would be out of array range, ignore cell
      else if (i < 0 || j < 0 || i >= getRows() || j >= getColumns()){continue;}

      // else evaluate cell and tally accordingly
      else if(access_value(i,j)->getState()){numNeighbors++;}
      }
    }
  return numNeighbors;}
