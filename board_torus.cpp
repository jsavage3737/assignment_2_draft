#include "board_torus.h"
#include <iostream>
using namespace std;
using namespace hw2;

// updates board with new node board_values
void board_torus::update_board(){
  bool newState;
  int neighbors;
  // for each cell
  for (int i=0; i<getRows(); i++){
    for (int j=0; j<getColumns(); j++){
      // evaluate whether cell is alive next iteration and store in temp
      neighbors = count_neighbors(i,j);
      newState = access_value(i,j)->updateState(neighbors);
      set_temp(newState,i,j);
    }
  }
  applyChanges();
}

// determines number of neighbors for cell at row and column index
int board_torus::count_neighbors(int row, int column){
  int numNeighbors = 0;

  for (int i=row-1; i<=row+1; i++){ // for 3 rows centered on input index
    for (int j=column-1; j<=column+1; j++){ // for the 3 cols centered on input index

      // ignore the center cell
      if (i==row && j==column){continue;}

      // continue logic for non-center cells
      else{
        if (i<0){i = row-1;} // if out of bounds left, redirect to rightmost node
        else if (i>=column){i=0;} // else if out of bounds right, redirect to leftmost node

      }
      }
    }
  return numNeighbors;}
