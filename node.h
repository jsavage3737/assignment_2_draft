using namespace std;
namespace hw2{
  class node{
  public:
    bool getState();
    bool updateState(int numNeighbors);
    bool updateState(bool isAlive);
    node(bool isAlive);
    node();
  private:
    bool alive;
  };
}
