#include "grid.hpp"

// Default constructor for initialise a blank sudoku grid
Grid::Grid() { grid.resize(9, vector<int>(9, 0)); };

// Constructs a sudoku grid based on int array
Grid::Grid(int numbers[]) : Grid() { setGrid(numbers); };

// Constructs a sudoku grid based of string of numbers
Grid::Grid(string numbers) : Grid() { setGrid(numbers); };

Grid::~Grid(){};

// Prints a 9 x 9 sudoku grid
void Grid::print() {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Prints numbers in a specified column
void Grid::printColumn(int c) {
  c--;
  for (int r = 0; r < 9; r++) {
    cout << grid[r][c] << " ";
  }
  cout << endl;
}

// Prints numbers in a specified row
void Grid::printRow(int r) {
  r--;
  for (int c = 0; c < 9; c++) {
    cout << grid[r][c] << " ";
  }
  cout << endl;
}

// Prints a 3 x 3 grid of numbers within the specified sudoku block. Blocks are
// numbered from 1 to 9 starting from the top right moving across each row.
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

// Returns the grid a single int array
int *Grid::getArray() {
  int *array;
  array = new int[81];
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      array[c + (r * 9)] = grid[r][c];
    }
  }
  return array;
}

// Returns the grid as single string of number characters
string Grid::toString() {
  string string(81, '0');
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      // TODO: Fix conversion from int to char
      string[c + (r * 9)] = grid[r][c] + '0';
    }
  }
  return string;
}

// Sets the numbers in the grid from a int array, filling each row first.
void Grid::setGrid(int numbers[]) {
  int pos;
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      pos = c + (r * 9);
      grid[r][c] = numbers[pos];
    }
  }
}

// Sets the numbers in the grid from a string of number characters, filling
// each row first.
void Grid::setGrid(string numbers) {
  int pos;
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      pos = c + (r * 9);
      grid[r][c] = numbers[pos] - '0';
    }
  }
}

// Checks if number is not already within row specified
bool Grid::unusedInRow(int r, int number) {
  for (int c = 0; c < 9; c++) {
    if (grid[r][c] == number) {
      return false;
    }
  }
  return true;
}

// Checks if number is not already within column specified
bool Grid::unusedInColumn(int c, int number) {
  for (int r = 0; r < 9; r++) {
    if (grid[r][c] == number) {
      return false;
    }
  }
  return true;
}

// Checks if number is not already within box specified
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

// Checks if a number can be legally placed in position on grid
bool Grid::validAssignment(int r, int c, int number) {
  return unusedInRow(r, number) && unusedInColumn(c, number) &&
         unusedInBox(r, c, number);
}

// Checks if grid is filled with numbers from 1 to 9
bool Grid::nextEmptyPosition(int &r, int &c) {
  for (r = 0; r < 9; r++) {
    for (c = 0; c < 9; c++) {
      if (grid[r][c] == 0) {
        return true;
      }
    }
  }
  return false;
}

// Checks if the grid is solved.
bool Grid::isSolved() {
  // Create arrays to represent whether number is used
  bool numberUsedInRow[9][9];
  bool numberUsedInColumn[9][9];
  bool numberUsedInBox[9][9];

  for (int i = 0; i < 9; i++) {
    for (int n = 0; n < 9; n++) {
      numberUsedInRow[i][n] = false;
      numberUsedInColumn[i][n] = false;
      numberUsedInBox[i][n] = false;
    }
  }

  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      int number = grid[r][c];
      int b = c / 3 + (r / 3) * 3;
      if (numberUsedInRow[r][number] && numberUsedInColumn[c][number] &&
          numberUsedInBox[b][number]) {
        return false;
      }
      numberUsedInRow[r][number] = true;
      numberUsedInColumn[c][number] = true;
      numberUsedInBox[b][number] = true;
    }
  }
  return true;
}

// Solves the grid using a brute force backtracking method.
bool Grid::solve() {
  int r, c;
  if (!nextEmptyPosition(r, c)) {
    return true;
  }
  for (int i = 1; i <= 9; i++) {
    if (validAssignment(r, c, i)) {
      grid[r][c] = i;
      if (solve()) {
        return true;
      }
      grid[r][c] = 0;
    }
  }
  return false;
}
