/**
 *
 * Source:    LeetCode
 * Problem:   509. Fibonacci Number
 * Link:
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 *
 * Approach 1:
 * using recursive calls to fib to calculate current fib with
 * fib(n-1) + fib(n-2)
 *
 *
 * Approach 2: OPTIMAL
 * instead of using recursive function calls, direction calculsting the fib
 *
 */

#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n - 1) + fib(n - 2);
}

int fibOptimal(int n) {
  int a = 0;
  int b = 1;
  int temp;
  if (n < 2) return n;
  for (int i = 2; i <= n; i++) {
    temp = a;
    a = b;
    b = b + temp;
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  cout << "Solution1: " << fib(n) << "\n";
  cout << "Solution2: " << fibOptimal(n) << "\n";
  return 0;
}