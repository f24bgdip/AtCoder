// d-abc_puzzle.h
#ifndef D_ABC_PUZZLE_H
#define D_ABC_PUZZLE_H

#include <string>
#include <vector>

void test_input(int n, std::string r, std::string c);
bool check(const std::vector<std::string> &grid, int row);
bool solve(std::vector<std::string> &grid,
           std::vector<std::vector<int>> &abc_counts, int row);

#endif // D_ABC_PUZZLE_H
