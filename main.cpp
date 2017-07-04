#include <iostream>

using namespace std;

class Grid{
private:
  int boardSize = 9;
  int board[boardSize**2];
public:
  int** getRow(int pos){
    int* row[boardSize];
    for(int i = 0; i < boardSize; i++){
      int offset = (pos - 1) * boardSize
      row[i] = &board[offset + i]
    }
    return row;
  }

  int** getColumn(int pos){
    int* column[boardSize];
    for(int i = 0; i < boardSize; i++){
      int offset = (pos - 1)
      column[i] = &board[(i * boardSize) + offset]
    }
    return column;
  }

  int** getBlock(int pos){
    int* block[boardSize];
    for(int i = 0; i < boardSize; i++){
      int blockSize =
      int offset = (pos - 1)
      block[i] = &board[(i * boardSize) + offset]
    }
    return block;
  }
}

int main(){
  cout << "Hello, world" << endl;
  return 0;
}
