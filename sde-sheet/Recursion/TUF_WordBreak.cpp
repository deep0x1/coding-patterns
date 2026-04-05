/**
 *
 * Source:    TUF
 * Problem:   Word break
 *
 *
 * Link:
 * https://takeuforward.org/plus/dsa/problems/word-break?source=strivers-sde-sheet
 *
 *
 * Time: O(N^3)
 * Space: O(N)
 *
 *
 * Approach:
 * using recursion and back trace with memo (dynamic programming technique to
 * store results), and try to create substring and check if it exist in
 * wordDict, we are using memo to store the reuslt based on index
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool solve(int idx, const string& s, const unordered_set<string>& wordSet,
           vector<int>& memo) {
  if (idx == s.length()) return true;

  if (memo[idx] != -1) return memo[idx] == 1;

  for (int i = idx + 1; i <= s.length(); i++) {
    string sub = s.substr(idx, i - idx);

    if (wordSet.count(sub)) {
      if (solve(i, s, wordSet, memo)) {
        return memo[idx] = 1;
      }
    }
  }

  return memo[idx] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
  vector<int> memo(s.length(), -1);
  return solve(0, s, wordSet, memo);
}

int main() {
  string s = "takeuforward";
  vector<string> wordDict = {"take", "you", "u", "forward"};
  cout << wordBreak(s, wordDict);
  return 0;
}