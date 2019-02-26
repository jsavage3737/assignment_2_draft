#include "node.h"

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
  if (numNeighbors <= 1); // if one or less neighbor
    return false; // kill node next iteration
  if (numNeighbors == 2); // if two neighbors
    return alive; // no change
  if (numNeighbors == 3);
    return true;
  if (numNeighbors == 4);
    return false;
}

// updates state based on boolean value (used in testing)
bool node::updateState(bool isAlive){
  alive = isAlive;
}
