#include "board_torus.h"
#include <iostream>
using namespace std;
using namespace hw2;

// updates board with new node board_values
void board_torus::update_board(){
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
int board_torus::count_neighbors(int row, int column){
  int numNeighbors = 0;
  int temp_i, temp_j; // temp indices used if original is outside bounds
  for (int i=row-1; i<=row+1; i++){ // for 3 rows centered on input index
    for (int j=column-1; j<=column+1; j++){ // for the 3 cols centered on input index
      // ignore the center cell
      if (i==row && j==column){continue;}

      // check for problem indices
      else if (i < 0 || j < 0 || i >= getRows() || j >= getColumns()){
        // resolve problem indices
        temp_i = i, temp_j = j; // temp vars can now used to look for neighbors
        if (i<0){temp_i = getRows()-1;} // if out of bounds left, redirect to rightmost node
        else if (i>= getRows()){temp_i=0;} // else if out of bounds right, redirect to leftmost node
        if (j<0){temp_j = getColumns()-1;} // if out of bounds from top, redirect to bottom
        else if (j>=getColumns()){temp_j=0;} // if out of bounds from bottom, redirect to top

        // evaluate new point and count if alive
        if(access_value(temp_i,temp_j)->getState()){numNeighbors++;}
      }

      // else check cell
      else{if(access_value(i,j)->getState()){numNeighbors++;}}
    }
  }
  return numNeighbors;
}
