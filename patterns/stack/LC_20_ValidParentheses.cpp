/**
 *
 * Source:    LeetCode
 * Problem:   20. Valid Parentheses
 * Link:
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 *
 * Approach 1:
 * using hashmap and stack
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
  unordered_map<char, char> p_map;
  stack<char> p_stack;

  p_map[')'] = '(';
  p_map['}'] = '{';
  p_map[']'] = '[';

  for (auto c : s) {
    if (p_map.count(c)) {
      char top_elem = p_stack.empty() ? '#' : p_stack.top();
      if (top_elem != p_map[c]) return false;
      p_stack.pop();
    } else {
      p_stack.push(c);
    }
  }
  
  return p_stack.empty();
}

int main() {
  string s = "[[[]]]";
  bool ans = isValid(s);
  cout << ans;
  return 0;
}