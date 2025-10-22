/**
 *
 * Source:    TUF
 * Problem:   Find the repeating and missing numbers
 * Link:
 * https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
 *
 *
 * Approach 1:
 * using maths S (sum of all num) and S2 (sum of all num squared);
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
  int n = a.size();
  long long Sn = n * (n + 1) / 2;
  long long S2n = n * (n + 1) * (2 * n + 1) / 6;

  long long S = 0;
  long long S2 = 0;
  for (auto num : a) {
    S += num;
    S2 += num * num;
  }

  // x - y
  long long val1 = S - Sn;
  // x^2 - y^2
  long long val2 = S2 - S2n;
  // x + y
  val2 = val2 / val1;

  long long x = (val1 + val2) / 2;
  long long y = x - val1;

  return {(int)x, (int)y};
}

int main() {
  vector<int> a = {3, 1, 2, 5, 3};
  vector<int> ans = findMissingRepeatingNumbers(a);
  cout << ans[0] << ", " << ans[1];
  return 0;
}