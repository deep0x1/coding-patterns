/**
 *
 * Source:    LeetCode
 * Problem:   Longest Consecutive Sequence in an Array
 * Link:
 * https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
 *
 *
 * Approach 1: optimal
 * using set datatype
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& arr) {
  unordered_set<int> arr_set;
  int max_count = 0;
  for (auto n : arr) arr_set.insert(n);
  for (auto n : arr) {
    int target = n;
    if (arr_set.count(n - 1)) continue;

    int count = 0;
    while (true) {
      if (arr_set.count(n + count))
        count++;
      else
        break;
    }
    max_count = max(max_count, count);
  }
  return max_count;
}

int main() {
  int k = 0;
  vector<int> nums = {3, 4, 5, 6, 7, 9, 10};
  int sol = longestConsecutive(nums);
  cout << sol;
  return 0;
}
