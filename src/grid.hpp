#include <vector>
#include <iostream>

using namespace std;

class Grid {
private:
  vector< vector<int> > grid;
  bool unusedInRow(int r, int number);
  bool unusedInColumn(int c, int number);
  bool unusedInBox(int row, int col, int number);
  bool validAssignment(int r, int c, int number);
  bool isSolved(int &r, int &c);

public:
  Grid(int startNums[]);
  ~Grid();

  void print();
  void printColumn(int c);
  void printRow(int r);
  void printBlock(int b);
  int* getArray();

  bool solve();
};
