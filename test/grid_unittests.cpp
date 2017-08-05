#include "../src/grid.hpp"
#include "csv.cpp"
#include <gtest/gtest.h>
#include <stdlib.h>

TEST(GridTest, SolveMany) {

  string filepath = "test/sudoku.csv";
  io::CSVReader<2> in(filepath);
  in.read_header(io::ignore_extra_column, "quizzes", "solutions");
  std::string puzzle, solution;
  Grid grid = Grid();

  while (in.read_row(puzzle, solution)) {
    grid.setGrid(puzzle);
    ASSERT_STREQ(grid.toString().c_str(), puzzle.c_str());
    ASSERT_TRUE(grid.solve());
    ASSERT_STREQ(grid.toString().c_str(), solution.c_str());
  }
}

TEST(IsSolvedTest, WithSolvedPuzzle) {
  Grid grid = Grid("65792184318354697294237856126571943831865429779483215683146"
                   "5729479283615526197384");
  ASSERT_TRUE(grid.isSolved());
}

TEST(IsSolvedTest, WithUnsolvedPuzzle) {
  Grid grid = Grid("00090080310350000200207056000571903030000400009400200680006"
                   "0709079080610520100004");
  ASSERT_FALSE(grid.isSolved());
}
