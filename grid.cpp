#include <iostream>
#include <vector>

using namespace std;

class Grid{
private:
  vector< vector<int> > grid;

public:
  Grid(int startNums[]){
    grid.resize(9, vector<int>(9, 0));
    int pos;
    for (int c = 0; c < 9; c++){
      for (int r = 0; r < 9; r++){
        pos = r + (c * 9);
        grid[c][r] = startNums[pos];
      }
    }
  }

  ~Grid(){
  }

  /*int** getBlock(int pos){
    int* block[boardSize];
    for(int i = 0; i < boardSize; i++){
      int blockSize =
      int offset = (pos - 1)
      block[i] = &board[(i * boardSize) + offset];
    }
    return block;
  }*/

  void print(){
    for(int c = 0; c < 9; c++){
      for(int r = 0; r < 9; r++){
        cout << grid[c][r] << " ";
      }
      cout << endl;
    }
  }

  void printColumn(int c){
    c--;
    for(int r = 0; r < 9; r++){
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }

  void printRow(int r){
    r--;
    for(int c = 0; c < 9; c++){
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }

};

int main(){

  int sudoku [] = {0,5,6,9,0,7,4,0,0,0,8,1,0,4,0,0,0,0,0,0,0,0,1,5,0,9,0,0,0,0,0,0,3,8,5,7,8,4,0,0,6,0,0,2,3,7,3,9,2,0,0,0,0,0,0,6,0,5,8,0,0,0,0,0,0,0,0,7,0,3,6,0,0,0,8,3,0,6,5,7,0};

  Grid grid = Grid(sudoku);
  cout << "Hello, world" << endl;
  grid.print();
  grid.printRow(4);
  grid.printColumn(4);

  return 0;
}
