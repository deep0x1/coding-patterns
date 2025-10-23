/**
 *
 * Source:    LeetCode
 * Problem:   704. Binary Search
 * Link:      https://leetcode.com/problems/binary-search/description/
 *
 *
 * Approach 1:
 * binary search
 *
 */

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int ans = -1;

  while (left <= right) {
    int mid = (right + left) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else {
      ans = mid;
      break;
    }
  }

  return ans;
}

int searchRecursive(vector<int>& nums, int low, int high, int target) {
  // base case
  if (low >= high) return -1;

  int mid = (low + high) / 2;
  if (nums[mid] < target) {
    return searchRecursive(nums, mid + 1, high, target);
  } else if (nums[mid] > target) {
    return searchRecursive(nums, low, mid - 1, target);
  } else {
    return mid;
  }
}

int main() {
  int target = 9;
  vector<int> arr = {-1, 0, 3, 5, 9, 12};
  // int ans = search(arr, target);
  int ans = searchRecursive(arr, 0, arr.size() - 1, target);
  cout << ans;
  return 0;
}