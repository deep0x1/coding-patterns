/**
 *
 * Source:    LC
 * Problem:   455. Assign Cookies
 *
 *
 * Link:
 * https://leetcode.com/problems/assign-cookies/description/
 *
 *
 * Time: O(NLogN + MLogM)
 * Space: O(1)
 *
 *
 * Approach:
 * using greedy approach to find the smallest cookie to satify children with
 * smallest greed first
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  int i = 0;
  int j = 0;

  while (i < g.size() && j < s.size()) {
    if (g[i] <= s[j]) {
      i++;
    }
    j++;
  }

  return i;
}

int main() {
  vector<int> g = {1, 2};
  vector<int> s = {};
  cout << findContentChildren(g, s);
  return 0;
}