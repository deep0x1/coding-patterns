/**
 *
 * Source:    TUF
 * Problem:   M - Coloring Problem
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/m-coloring-problem
 *
 *
 * Time: O(N*M)
 * Space: O(N)
 *
 *
 * Approach:
 * using recursion to check if it is safe to use color from 1 - m one by one for
 * all nodes
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int node, vector<int>& color, bool graph[101][101], int N,
            int col) {
  for (int i = 0; i < N; i++) {
    if (graph[node][i]) {
      if (color[i] == col) return false;
    }
  }
  return true;
}

bool solve(int node, vector<int>& color, int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }
  }

  return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
  vector<int> color(N, 0);
  return solve(0, color, m, N, graph);
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  graph[0][1] = 1;
  graph[1][0] = 1;

  graph[1][2] = 1;
  graph[2][1] = 1;

  graph[2][3] = 1;
  graph[3][2] = 1;

  graph[3][0] = 1;
  graph[0][3] = 1;

  graph[0][2] = 1;
  graph[2][0] = 1;

  cout << graphColoring(graph, m, N);

  return 0;
}