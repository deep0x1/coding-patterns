/**
 *
 * Source:    TUF
 * Problem:   Rat in a Maze
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/rat-in-a-maze
 *
 *
 * Time: O(3^(N^2))
 * Space: O(N^2)
 *
 *
 * Approach:
 * using recursion and back trace to try all possible paths by moving rat in
 * DLRU direction
 *
 */

#include <bits/stdc++.h>

using namespace std;

void solve(int row, int col, vector<vector<int>>& grid, string& curr,
           vector<string>& allPaths) {
  int n = grid.size();
  if (row == n - 1 && col == n - 1) {
    allPaths.push_back(curr);
    return;
  }

  // mark the current cell visited
  grid[row][col] = 0;

  // check down
  if (row + 1 < n && grid[row + 1][col]) {
    curr.push_back('D');
    solve(row + 1, col, grid, curr, allPaths);
    curr.pop_back();
  }

  // check left
  if (col - 1 >= 0 && grid[row][col - 1]) {
    curr.push_back('L');
    solve(row, col - 1, grid, curr, allPaths);
    curr.pop_back();
  }

  // check right
  if (col + 1 < n && grid[row][col + 1]) {
    curr.push_back('R');
    solve(row, col + 1, grid, curr, allPaths);
    curr.pop_back();
  }

  // check up
  if (row - 1 >= 0 && grid[row - 1][col]) {
    curr.push_back('U');
    solve(row - 1, col, grid, curr, allPaths);
    curr.pop_back();
  }

  // undo backtrace
  grid[row][col] = 1;
}

vector<string> findPath(vector<vector<int>>& grid) {
  string curr;
  vector<string> allPaths;

  if (grid[0][0] == 1) {
    solve(0, 0, grid, curr, allPaths);
  }

  return allPaths;
}

int main() {
  vector<vector<int>> grid = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 1},
      {0, 1, 1, 1},
  };
  vector<string> out = findPath(grid);
  for (auto path : out) cout << path << ", ";
  return 0;
}