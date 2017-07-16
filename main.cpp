#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

class Grid{
private:
  int boardSize;
  int* board;

  class Row{
  public:
    // Iterator traits, previously from std::iterator.
    using value_type = int;
    using difference_type = ptrdiff_t;
    using pointer = int*;
    using reference = int&;
    using iterator_category = random_access_iterator_tag;

    // Default constructible.
    Row() = default;
    explicit Row(BstNode* node);

    // Dereferencable.
    reference operator*() const;

    // Pre- and post-incrementable.
    Row& operator++();
    Row operator++(int);

    // Pre- and post-decrementable.
    Row& operator--();
    Row operator--(int);

    // Equality / inequality.
    bool operator==(const Row& rhs);
    bool operator!=(const Row& rhs);
  private:

  }
public:
  Grid(){
    boardSize = 9;
    int numberOfPositions = pow(boardSize,2);
    board = new int[numberOfPositions];
  }

  Grid(int size){
    boardSize = size;
    int numberOfPositions = pow(boardSize,2);
    board = new int[numberOfPositions];
  }

  Grid(int startNums[], int size){
    boardSize = size;
    board = startNums;
  }

  ~Grid(){
  }

  int** getRow(int pos){
    int* row[boardSize];
    for(int i = 0; i < boardSize; i++){
      int offset = (pos - 1) * boardSize;
      int location = offset + i;
      cout << location << ": " << board[location] << endl;
      row[i] = &board[location];
    }
    return row;
  }

  int** getColumn(int pos){
    int* column[boardSize];
    for(int i = 0; i < boardSize; i++){
      int offset = (pos - 1);
      column[i] = &board[(i * boardSize) + offset];
    }
    return column;
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
    for(int r = 0; r < boardSize; r++){
      for(int c = 0; c < boardSize; c++){
        int offset = (r) * boardSize;
        //cout << r << c << ": ";
        cout << board[c + offset] << " ";
      }
      cout << endl;
    }
  }

  void printColumn(int pos){
    int** column = getColumn(pos);
    for(int r = 0; r < boardSize; r++){
      cout << **(column + r) << endl;
    }
  }

  void printRow(int pos){
    int** row = getRow(pos);
    for(int c = 0; c < boardSize; c++){
      cout << **(row + c) << endl;
    }
  }

};

int main(){

  int sudoku [] = {0,5,6,9,0,7,4,0,0,0,8,1,0,4,0,0,0,0,0,0,0,0,1,5,0,9,0,0,0,0,0,0,3,8,5,7,8,4,0,0,6,0,0,2,3,7,3,9,2,0,0,0,0,0,0,6,0,5,8,0,0,0,0,0,0,0,0,7,0,3,6,0,0,0,8,3,0,6,5,7,0};
  int* startNums = new int[89];

  for(int i = 0; i < 89; i++){
    startNums[i] = sudoku[i];
  }

  Grid grid = Grid(startNums, 9);
  grid.print();
  //grid.printColumn(4);
  grid.printRow(1);
  cout << "Hello, world" << endl;
  return 0;
}
