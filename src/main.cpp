#include "grid.hpp"
#include "../test/csv.cpp"

int main() {
  Grid grid = Grid("004300209005009001070060043006002087190007400050083000600000105003508690042910300");
  grid.print();
  grid.solve();
  grid.print();
  if (grid.isSolved()){
    cout << "SOLVED!" << endl;
  } else {
    cout << "No solution found" << endl;
  };

}
