/**
 *
 * Source:    TUF
 * Problem:   Floor and Ceil in Sorted Array
 * Link:      https://takeuforward.org/arrays/floor-and-ceil-in-sorted-array/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> floor_and_ceiling(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int flo = left;
  int ceil = right;
  while (left <= right) {
    cout << left << ", " << right << "\n";
    int mid = (left + right) / 2;
    if (nums[mid] > target) {
      right = mid - 1;
      ceil = mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
      flo = mid;
    } else {
      ceil = mid;
      flo = mid;
      break;
    }
  }

  return {flo, ceil};
}

int main() {
  int target = 8;
  vector<int> arr = {3, 4, 4, 7, 8, 10};
  vector<int> ans = floor_and_ceiling(arr, target);
  cout << ans[0] << ", " << ans[1];
  return 0;
}