#include "../src/grid.hpp"
#include "csv.cpp"
#include <gtest/gtest.h>


TEST(GridTest, SolveMany) {
  string filepath = "/Users/seanrankine/Developer/sudoku-solver/test/sudoku.csv";
  io::CSVReader<2>in(filepath);
  in.read_header(io::ignore_extra_column, "quizzes", "solutions");
  std::string puzzle, solution;
  Grid grid = Grid();

  while(in.read_row(puzzle,solution)){
    grid.setGrid(puzzle);
    ASSERT_STREQ(grid.toString().c_str(), puzzle.c_str());
    ASSERT_TRUE(grid.solve());
    ASSERT_STREQ(grid.toString().c_str(), solution.c_str());
  }
}

TEST(IsSolvedTest, WithSolvedPuzzle) {
  Grid grid = Grid("657921843183546972942378561265719438318654297794832156831465729479283615526197384");
  ASSERT_TRUE(grid.isSolved());
}

TEST(IsSolvedTest, WithUnsolvedPuzzle) {
  Grid grid = Grid("000900803103500002002070560005719030300004000094002006800060709079080610520100004");
  ASSERT_FALSE(grid.isSolved());
}
