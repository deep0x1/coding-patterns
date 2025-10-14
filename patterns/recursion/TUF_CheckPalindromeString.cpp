/**
 *
 * Source:    TUF
 * Problem:   Check if the given String is Palindrome or not
 * Link:
 * https://takeuforward.org/data-structure/check-if-the-given-string-is-palindrome-or-not/
 *
 *
 * Approach 1:
 * using recustive approach to loop through half string while comparing to the
 * end half
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
  if (start < end) {
    bool condition = s[start] == s[end];
    return condition && isPalindrome(s, start + 1, end - 1);
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  cout << "Solution: " << isPalindrome(s, 0, s.length() - 1) << "\n";
  return 0;
}