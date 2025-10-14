/**
 *
 * Source:    LeetCode
 * Problem:   9. Palindrome Number
 * Link:      https://leetcode.com/problems/palindrome-number/description/
 *
 *
 * Approach 1:
 * converting to string -> reversing -> comparing with original
 *
 *
 * Approach 2: OPTIMAL
 * copying -> reversing mathematically (% 10 , / 10) -> comparing with original
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
  // negative numbers can not be palindrome
  // none zero numbers with 0 at the end can not be palindrome
  if (x < 0 || (x % 10 == 0 && x != 0)) return false;

  // reverse and compare
  string s = to_string(x);
  reverse(s.begin(), s.end());
  return stoll(s) == x;
}

bool isPalindromeOptimal(int x) {
  // negative numbers can not be palindrome
  // none zero numbers with 0 at the end can not be palindrome
  if (x < 0 || (x % 10 == 0 && x != 0)) return false;

  // reverse
  long long reversed = 0;
  int temp = x;
  while (temp) {
    reversed = (reversed * 10) + (temp % 10);
    temp /= 10;
  }

  // compare
  return reversed == x;
}

int main() {
  int N;
  cin >> N;
  cout << "Solution 1:\t" << isPalindrome(N) << "\n";
  cout << "Solution 2:\t" << isPalindromeOptimal(N) << "\n";
  return 0;
}