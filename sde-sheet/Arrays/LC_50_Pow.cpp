/**
 *
 * Source:    LeetCode
 * Problem:   50. Pow(x, n)
 *
 * Link:
 * https://leetcode.com/problems/powx-n/description/
 *
 *
 * Time: O(LogN)
 * Space: O(1)
 *
 *
 * Approach:
 * we are using the idea of expressing exponent in terms of power of 2
 * for example we are presenting 3^20 = 3^16 * 3^4
 * and we are using bit wise & to check if the right most bit is 1 and multiple
 * the current base to result, while continously calculating the next base^2n
 *
 */

#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n) {
  double result = 1.0;
  long long exp = n;
  if (exp < 0) {
    x = 1 / x;
    exp = -exp;
  }

  while (exp) {
    if (exp & 1) result *= x;
    x *= x;
    exp >>= 1;
  }

  return result;
}

int main() {
  double x = 2.0;
  double n = -2;
  cout << myPow(x, n);
  return 0;
}