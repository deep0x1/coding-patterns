/**
 *
 * Source:    TUF
 * Problem:   Implement Lower Bound
 * Link:      https://takeuforward.org/arrays/implement-lower-bound-bs-2/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int ans = nums.size();

  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] >= target) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return ans;
}

int main() {
  int target = 9;
  vector<int> arr = {3,5,8,15,19};
  int ans = search(arr, target);
  cout << ans;
  return 0;
}