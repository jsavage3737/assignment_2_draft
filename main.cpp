#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "board_normal.h"
#include "board_torus.h"
#include "board_mirror.h"
#include "game.h"
using namespace hw2;
using namespace std;

// main declares game object and runs the game
int main(int argc, char *argv[]){
  game game;
  game.initializeGame();
  game.runGame();
  cout << "press enter to leave..."
  cin.get();
}
