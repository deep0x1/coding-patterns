/**
 *
 * Source:    TUF
 * Problem:   Finding Sqrt of a number using Binary Search
 * Link:
 * https://takeuforward.org/binary-search/finding-sqrt-of-a-number-using-binary-search/
 *
 *
 * Approach 1:
 * using binary search approach to find square root by making a range of left =
 * 0 to right = n / 2 and then searching for mid * mid <= n
 *
 */

#include <bits/stdc++.h>

using namespace std;

int sqrt(int n) {
  // edge case
  if (n < 2) return n;

  int left = 0;
  int right = n / 2;
  int ans = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (mid * mid <= n) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

int main() {
  int n = 3;
  int ans = sqrt(n);
  cout << ans;
  return 0;
}