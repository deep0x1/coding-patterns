/**
 *
 * Source:    TUF
 * Problem:   Find out how many times the array has been rotated
 * Link:
 * https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/
 *
 *
 * Approach 1:
 * using modified binary search to find index of minimum digit in array that is
 * exacly how many times array is rotated
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findRotated(vector<int>& nums) {
  int min_idx = 0;
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    // if array have unique elements
    // and its already sorted
    // then min element is the left most
    if (nums[left] <= nums[right]) {
      if (nums[left] < nums[min_idx]) {
        min_idx = left;
        break;
      }
    }

    // left sorted
    if (nums[left] <= nums[mid]) {
      if (nums[left] < nums[min_idx]) {
        min_idx = left;
      }
      left = mid + 1;

    // right sorted
    } else {
      if (nums[mid] < nums[min_idx]) {
        min_idx = mid;
      }
      right = mid - 1;
    }
  }

  return min_idx;
}

int main() {
  vector<int> arr = {3, 4, 5, 1, 2};
  int ans = findRotated(arr);
  cout << ans;
  return 0;
}