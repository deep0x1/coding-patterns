/**
 *
 * Source:    LeetCode
 * Problem:   1011. Capacity To Ship Packages Within D Days
 * Link:
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
 *
 *
 * Approach 1:
 * using binary search approach on the range of possible solutions 1 to
 * sum of all weights
 *
 */

#include <bits/stdc++.h>

using namespace std;

int ship(vector<int>& weights, int max_cap) {
  int days = 0;
  int current_sum = 0;

  for (auto weight : weights) {
    current_sum += weight;

    if (current_sum > max_cap) {
      days++;
      current_sum = weight;
    }
  }

  // checking left weights
  if (current_sum <= max_cap) days++;

  return days;
}

int shipWithinDays(vector<int>& weights, int days) {
  int max_weight = *max_element(weights.begin(), weights.end());
  int left = max_weight;
  int right = accumulate(weights.begin(), weights.end(), 0);
  int result = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int cost = ship(weights, mid);

    if (cost <= days) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return result;
}

int main() {
  int days = 8;
  vector<int> arr = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int ans = shipWithinDays(arr, days);
  // int ans = ship(arr, 15);
  cout << ans;
  return 0;
}