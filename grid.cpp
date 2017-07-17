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
    for (int r = 0; r < 9; r++){
      for (int c = 0; c < 9; c++){
        pos = c + (r * 9);
        grid[r][c] = startNums[pos];
      }
    }
  }

  ~Grid(){
  }

  void print(){
    for(int r = 0; r < 9; r++){
      for(int c = 0; c < 9; c++){
        cout << grid[r][c] << " ";
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

  void printBlock(int b){
    b--;
    int rowStart = (b / 3) * 3;
    int columnStart = (b % 3) * 3;

    int rowEnd = rowStart + 3;
    int columnEnd = columnStart + 3;
    for(int r = rowStart; r < rowEnd; r++){
      for(int c = columnStart; c < columnEnd; c++){
        cout << grid[r][c] << " ";
      }
      cout << endl;
    }
  }

  bool unusedInRow(int r, int number){
    for (int c = 0; c < 9; c++){
      if(grid[r][c] == number){
        return false;
      }
    }
    return true;
  }

  bool unusedInColumn(int c, int number){
    for (int r = 0; r < 9; r++){
      if(grid[r][c] == number){
        return false;
      }
    }
    return true;
  }

  bool unusedInBox(int row, int col, int number){
    int rowStart = row - row % 3;
    int columnStart = col - col % 3;
    int rowEnd = rowStart + 3;
    int columnEnd = columnStart + 3;

    for(int r = rowStart; r < rowEnd; r++){
      for(int c = columnStart; c < columnEnd; c++){
        if(grid[r][c] == number){
          return false;
        }
      }
    }
    return true;
  }

  bool validAssignment(int r, int c, int number){
    return unusedInRow(r, number) && unusedInColumn(c, number) && unusedInBox(r, c, number);
  }

  bool isSolved(int &r, int &c){
    for(r = 0; r < 9; r++){
      for(c = 0; c < 9; c++){
        if(grid[r][c] == 0){
          return false;
        }
      }
    }
    return true;
  }

  bool solve(){
    int row, col;
    if (isSolved(row, col)){
      return true;
    }
    for (int i = 1; i <=9; i++){
      if(validAssignment(row, col, i)){
        grid[row][col] = i;
        if (solve()){
          return true;
        }
        grid[row][col] = 0;
      }
    }
    return false;
  }

};

int main(){

  int sudoku [] = {0,5,6,9,0,7,4,0,0,0,8,1,0,4,0,0,0,0,0,0,0,0,1,5,0,9,0,0,0,0,0,0,3,8,5,7,8,4,0,0,6,0,0,2,3,7,3,9,2,0,0,0,0,0,0,6,0,5,8,0,0,0,0,0,0,0,0,7,0,3,6,0,0,0,8,3,0,6,5,7,0};

  Grid grid = Grid(sudoku);

  if (grid.solve()){
    grid.print();
  } else {
    cout << "No solution found." << endl;
  }

  return 0;
}
