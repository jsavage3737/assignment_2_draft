#include "node.h"
#include <iostream> // included for testing
using namespace hw2;
using namespace std;

// constructor with boolean arg
node::node(bool isAlive){
  alive = isAlive;
}

// default constructor builds a dead node
node::node(){
  alive = false;
}
// returns whether node is alive or dead
bool node::getState(){
  return alive;
}

// updates node state based on number of neighbors
bool node::updateState(int numNeighbors){
  if (numNeighbors < 2){ // if one or less neighbor
    return false;} // kill node next iteration
  else if (numNeighbors == 2){ // if two neighbors
    return alive;} // no change
  else if (numNeighbors == 3){
    return true;}
  else if (numNeighbors >= 4){
    return false;}
}

// updates state based on boolean value (used in testing)
bool node::setState(bool isAlive){
  alive = isAlive;
}
