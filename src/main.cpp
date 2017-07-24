#include "grid.hpp"
#include "csv.cpp"

#include <stdlib.h>

void printArray(int* arr, int len){
  for (int i =0; i < len; i++){
    cout<<arr[i];
  }
  cout << endl;
  cout << endl;
  cout << endl;
}

int main() {
  string filepath;
  cout << "Select a file to test: ";
  getline (cin, filepath);
  io::CSVReader<2>in(filepath);
  in.read_header(io::ignore_extra_column, "quizzes", "solutions");
  std::string q, s;
  //int count = 0;
  while(in.read_row(q,s)){
    //cout << "\r" << count;
    int puzzle[81];
    int solution[81];
    for(std::string::size_type i = 0; i < q.size(); ++i) {
        puzzle[i] = q[i] - '0';
        solution[i] = s[i] - '0';
    }
    Grid grid = Grid(puzzle);

    if (grid.solve()) {
      int* solvedGrid = grid.getArray();
      grid.print();
      for (int i = 0; i < 81; i++){
        if (solution[i] != solvedGrid[i]){
          cout << "WRONG: " << endl;
          printArray(solution, 81);
          printArray(solvedGrid, 81);
          cout << endl;

          break;
        };
      }
    } else {
      cout << "No solution found." << endl;
    }
    //count ++;
  }

  return 0;
}
