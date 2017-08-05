#include "../test/csv.cpp"
#include "grid.hpp"

int main() {
  Grid grid = Grid("00430020900500900107006004300600208719000740005008300060000"
                   "0105003508690042910300");
  grid.print();
  grid.solve();
  grid.print();

  if (grid.isSolved()) {
    cout << "Solved!" << endl;
  } else {
    cout << "Not solved!" << endl;
  };
}
