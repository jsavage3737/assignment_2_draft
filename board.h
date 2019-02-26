using namespace std;
#include "node.h"

namespace hw2{
  class board{
    public:
      void generate_from_input(int rows, int columns); // from user input
      void generate_from_file(int rows, int columns); // used with fileparser class
      void generate_new_temp(int rows, int columns);
      node access_value(int row, int column);
      void access_temp(int row, int column, bool isAlive);
      int count_neighbors(int row, int column);
    private:
      // boards stored as pointers to pointer array pointing to node arrays
      node **board_values; // contains current board nodes
      node **temp_board; // nodes are stored here between state updates
  };
}
