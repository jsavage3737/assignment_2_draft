using namespace std;
#include "node.h"

namespace hw2{
  class board{
    public:
      void generate_from_input(); // from user input
      void generate_from_file(); // used with fileparser class
      void generate_new_temp();
      node * access_value(int row, int column); // return memory address of node
      node * access_temp(int row, int column);
      void set_value(bool isAlive, int row, int column);
      void set_temp(bool isAlive, int row, int column);
      void setRows(int numRows);
      void setColumns(int numCols);
      int getRows();
      int getColumns();
      void printBoard();
      void printTemp();
      void applyChanges();
    private:
      int rows;
      int columns;
      // boards stored as pointers to pointer array pointing to node arrays
      node **board_values; // contains current board nodes
      node **temp_board; // nodes are stored here between state updates
  };
}
