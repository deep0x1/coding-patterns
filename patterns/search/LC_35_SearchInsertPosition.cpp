/**
 *
 * Source:    LeetCode
 * Problem:   35. Search Insert Position
 * Link:      https://leetcode.com/problems/search-insert-position/description/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int ans = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] >= target) {
      right = mid - 1;
      ans = mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
      ans = left;
    }
  }

  return ans;
}

int main() {
  int target = 5;
  vector<int> arr = {1, 3, 5, 6};
  int ans = searchInsert(arr, target);
  cout << ans;
  return 0;
}