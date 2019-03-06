using namespace std;

#include "node.h"
#include<string>
namespace hw2{
  class board{
    public:
      void update_board();
      void generate_from_input(); // from user input
      void generate_from_file(); // used with fileparser class
      void generate_new_temp();
      node * access_value(int row, int column); // return memory address of node
      node * access_temp(int row, int column);
      void set_value(bool isAlive, int row, int column);
      void set_temp(bool isAlive, int row, int column);
      void setRunning(bool isRunning);
      void setRows(int numRows);
      void setColumns(int numCols);
      void setGeneration(int numGen);
      void setDensity(double newDensity);
      void setOutputFilename(string newOutputFilename);
      void setRunning();
      void incrementGeneration();
      bool getRunning();
      int getRows();
      int getColumns();
      int getGeneration();
      float getDensity();
      string getOutputFilename();
      void printBoard();
      void printBoardToFile();
      void printTemp();
      void saveBoard();
      void applyChanges();
      node **board_values; // contains current board nodes
    private:
      bool running;
      int rows;
      int columns;
      int generation;
      float density;
      string outputFilename;
      // boards stored as pointers to pointer array pointing to node arrays

      node **temp_board; // nodes are stored here between state updates
  };
}
