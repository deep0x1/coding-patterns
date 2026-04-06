/**
 *
 * Source:    TUF
 * Problem:   Nth Root of a Number using Binary Search
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search
 *
 *
 * Time: O(NLog(M))
 * Space: O(1)
 *
 *
 * Approach:
 * using binary search to find right number which matches the given condition
 *
 */

#include <bits/stdc++.h>

using namespace std;

int nth_root(int n, int m) {
  if (m == 1) return 1;

  int low = 0;
  int high = m;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    long long target = 1;
    for (int i = 0; i < n; i++) {
      target *= mid;
      if (target > m) break;
    }

    if (target == m)
      return mid;
    else if (target > m)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

int main() {
  int n = 3;
  int m = 27;
  cout << nth_root(n, m);
  return 0;
}