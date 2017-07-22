#include "grid.hpp"

Grid::Grid(int startNums[]) {
  grid.resize(9, vector<int>(9, 0));
  int pos;
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      pos = c + (r * 9);
      grid[r][c] = startNums[pos];
    }
  }
};

Grid::~Grid() {};

void Grid::print() {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;

}

void Grid::printColumn(int c) {
  c--;
  for (int r = 0; r < 9; r++) {
    cout << grid[r][c] << " ";
  }
  cout << endl;
}

void Grid::printRow(int r) {
  r--;
  for (int c = 0; c < 9; c++) {
    cout << grid[r][c] << " ";
  }
  cout << endl;
}

void Grid::printBlock(int b) {
  b--;
  int rowStart = (b / 3) * 3;
  int columnStart = (b % 3) * 3;

  int rowEnd = rowStart + 3;
  int columnEnd = columnStart + 3;
  for (int r = rowStart; r < rowEnd; r++) {
    for (int c = columnStart; c < columnEnd; c++) {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
}

int* Grid::getArray() {
  int* array;
  array = new int[81];
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      array[c + (r * 9)] = grid[r][c];
    }
  }
  return array;
}

bool Grid::unusedInRow(int r, int number) {
  for (int c = 0; c < 9; c++) {
    if (grid[r][c] == number) {
      return false;
    }
  }
  return true;
}

bool Grid::unusedInColumn(int c, int number) {
  for (int r = 0; r < 9; r++) {
    if (grid[r][c] == number) {
      return false;
    }
  }
  return true;
}

bool Grid::unusedInBox(int row, int col, int number) {
  int rowStart = row - row % 3;
  int columnStart = col - col % 3;
  int rowEnd = rowStart + 3;
  int columnEnd = columnStart + 3;

  for (int r = rowStart; r < rowEnd; r++) {
    for (int c = columnStart; c < columnEnd; c++) {
      if (grid[r][c] == number) {
        return false;
      }
    }
  }
  return true;
}

bool Grid::validAssignment(int r, int c, int number) {
  return unusedInRow(r, number) && unusedInColumn(c, number) &&
         unusedInBox(r, c, number);
}

bool Grid::isSolved(int &r, int &c) {
  for (r = 0; r < 9; r++) {
    for (c = 0; c < 9; c++) {
      if (grid[r][c] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool Grid::solve() {
  int row, col;
  if (isSolved(row, col)) {
    return true;
  }
  for (int i = 1; i <= 9; i++) {
    if (validAssignment(row, col, i)) {
      grid[row][col] = i;
      if (solve()) {
        return true;
      }
      grid[row][col] = 0;
    }
  }
  return false;
}
