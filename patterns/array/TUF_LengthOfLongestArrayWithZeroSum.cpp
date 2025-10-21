/**
 *
 * Source:    TUF
 * Problem:   Length of the longest subarray with zero Sum
 * Link:      https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
 *
 *
 * Approach 1:
 * prefix sum approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longestZero(vector<int> arr) {
  unordered_map<int, int> p_map;
  int longest = 0;
  int current_sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    current_sum += arr[i];
    if (p_map.count(current_sum)) {
      int length = i - p_map[current_sum];
      longest = max(longest, length);
    }
    if (!p_map.count(current_sum)) {
      p_map[current_sum] = i;
    }
  }
  return longest;
}

int main() {
  vector<int> arr = {9, -3, 3, -1, 6, -5};
  int ans = longestZero(arr);
  cout << ans;
  return 0;
}
