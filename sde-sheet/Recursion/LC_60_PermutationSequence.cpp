/**
 *
 * Source:    LC
 * Problem:   60. Permutation Sequence
 *
 *
 * Link:
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 *
 * Time: O(N^2)
 * Space: O(N)
 *
 *
 * Approach:
 * using indexing math to find right number for each position in permutation
 * using slot block size
 *
 */

#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
  int res = 1;
  while (n) res *= n--;
  return res;
}

void backtrace(string& base, int k, string& perm) {
  int n = base.length();
  if (n == 0) return;

  int slot_size = fact(n - 1);
  int slot_index = k / slot_size;
  perm.push_back(base[slot_index]);
  base.erase(base.begin() + slot_index);

  k = k % slot_size;
  backtrace(base, k, perm);
}

string getPermutation(int n, int k) {
  string base = "";
  string perm = "";
  for (int i = 1; i <= n; i++) base.push_back('0' + i);
  backtrace(base, k - 1, perm);
  return perm;
}

int main() {
  int n = 3;
  int k = 3;
  cout << getPermutation(n, k);
  return 0;
}