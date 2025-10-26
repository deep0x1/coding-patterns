/**
 *
 * Source:    LeetCode
 * Problem:   1539. Kth Missing Positive Number
 * Link:
 * https://leetcode.com/problems/kth-missing-positive-number/description/
 *
 *
 * Approach 1:
 * using binary search approach to adjacent index between which solution may exist
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int miss_so_far = arr[mid] - mid - 1;

    if (miss_so_far < k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left + k;
}

int main() {
  int k = 5;
  vector<int> arr = {1, 2, 3, 4};
  int ans = findKthPositive(arr, k);
  // int ans = ship(arr, 15);
  cout << ans;
  return 0;
}