/**
 *
 * Source:    LeetCode
 * Problem:   125. Valid Palindrome
 * Link:
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 *
 * Approach 1:
 * puting pvoit on both ends and moving them toward center untill alpha numeric
 * character are found then comparing to check palindrome
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  int start = 0;
  int end = s.length() - 1;

  while (start < end) {
    // checking if pvoits are alpha numeric
    bool left = isalnum(s[start]);
    bool right = isalnum(s[end]);

    // moving pvoits untill alpha numeric
    if (!left || !right) {
      start += left ? 0 : 1;
      end -= right ? 0 : 1;
      continue;
    }

    // checking palindrome
    if (tolower(s[start]) != tolower(s[end])) return false;

    // next itteration
    start++;
    end--;
  }

  return true;
}

int main() {
  string s;
  cin >> s;
  cout << "Solution: " << isPalindrome(s) << "\n";
  return 0;
}