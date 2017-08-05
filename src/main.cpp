#include "../test/csv.cpp"
#include "grid.hpp"

void printGridStatus(Grid grid) {
  if (grid.isSolved()) {
    cout << "Solved!\n" << endl;
  } else {
    cout << "Not solved!\n" << endl;
  };
}

int main() {
  Grid grid = Grid("00430020900500900107006004300600208719000740005008300060000"
                   "0105003508690042910300");
  grid.print();
  printGridStatus(grid);

  grid.solve();
  grid.print();
  printGridStatus(grid);
}
