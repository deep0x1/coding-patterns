/**
 *
 * Source:    LeetCode
 * Problem:   7. Reverse Integer
 * Link:      https://leetcode.com/problems/reverse-integer/description/
 *
 *
 * Approach 1:
 * converting the number to string and reversing it
 *
 *
 * Approach 2: OPTIMAL
 * reversing with help of % 10 and / 10
 *
 */

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
  bool isNegative = x < 0;
  string s = to_string(x);
  int startIndex = isNegative ? 1 : 0;
  reverse(s.begin() + startIndex, s.end());
  long long result = stoll(s);
  if (result > INT_MAX || result < INT_MIN) return 0;
  return (int)result;
}

int reverseOptimal(int x) {
  long long reversed = 0;
  int temp = x;
  while (temp) {
    reversed = (reversed * 10) + (temp % 10);
    temp /= 10;
  }
  if (reversed > INT_MAX || reversed < INT_MIN) return 0;
  return (int)reversed;
}

int main() {
  int N;
  cin >> N;
  cout << "Solution 1:\t" << reverse(N) << "\n";
  cout << "Solution 2:\t" << reverseOptimal(N) << "\n";
  return 0;
}