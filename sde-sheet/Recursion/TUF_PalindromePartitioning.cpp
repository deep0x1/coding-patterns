/**
 *
 * Source:    TUF
 * Problem:   Palindrome partitioning
 *
 *
 * Link:
 * https://takeuforward.org/plus/dsa/problems/palindrome-partitioning?tab=editorial&source=strivers-sde-sheet
 *
 *
 * Time: O(N2^N)
 * Space: O(N2^N)
 *
 *
 * Approach:
 * using recursive for loop backtrace approach, every time before making a
 * partition we check if current left side of partition is a plandrome or not
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string& s) {
  string rev = s;
  reverse(rev.begin(), rev.end());
  return rev == s;
}

void backtrace(int idx, string s, vector<string>& curr_partition,
               vector<vector<string>>& all_partition) {
  if (idx == s.length()) {
    all_partition.push_back(curr_partition);
    return;
  }

  for (int i = idx; i < s.length(); i++) {
    string left_part = s.substr(idx, i - idx + 1);
    if (checkPalindrome(left_part)) {
      curr_partition.push_back(left_part);
      backtrace(i + 1, s, curr_partition, all_partition);
      curr_partition.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> all_partition;
  vector<string> curr_partition;
  backtrace(0, s, curr_partition, all_partition);
  return all_partition;
}

int main() {
  string s = "aabaa";
  vector<vector<string>> sol = partition(s);
  for (auto r : sol) {
    for (auto c : r) cout << c << ", ";
    cout << "\n";
  }
  return 0;
}