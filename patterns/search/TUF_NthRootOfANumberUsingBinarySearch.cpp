/**
 *
 * Source:    TUF
 * Problem:   Nth Root of a Number using Binary Search
 * Link:
 * https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int rootN(int n, int m) {
  int left = 0;
  int right = m / n;

  while (left <= right) {
    int mid = (left + right) / 2;
    int curr = pow(mid, n);

    if (curr == m) {
      return mid;
    } else if (curr < m) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int n = 4;
  int m = 69;
  int ans = rootN(n, m);
  cout << ans;
  return 0;
}