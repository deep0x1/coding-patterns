/**
 *
 * Source:    LeetCode
 * Problem:   1482. Minimum Number of Days to Make m Bouquets
 * Link:
 * https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
 *
 *
 * Approach 1:
 * using binary search approach on the range of possible solutions min() to max() days
 *
 */

#include <bits/stdc++.h>

using namespace std;

int simulate(vector<int>& bloomDay, int k, int n) {
  int counter = 0;
  int result = 0;

  for (auto b : bloomDay) {
    if (b <= n)
      counter++;
    else
      counter = 0;

    if (counter >= k) {
      result++;
      counter = 0;
    }
  }

  return result;
}

int minDays(vector<int>& bloomDay, int m, int k) {
  if (bloomDay.size() < ((long long)m * k)) return -1;

  int min_val = *min_element(bloomDay.begin(), bloomDay.end());
  int max_val = *max_element(bloomDay.begin(), bloomDay.end());

  int left = min_val;
  int right = max_val;
  int ans = left;

  while (left <= right) {
    int mid = (left + right) / 2;
    int result = simulate(bloomDay, k, mid);

    if (result >= m) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return ans;
}

int main() {
  int m = 2;
  int k = 3;
  vector<int> arr = {7, 7, 7, 7, 12, 7, 7};
  int ans = minDays(arr, m, k);
  // int ans = simulate(arr, k, 97);
  cout << ans;
  return 0;
}