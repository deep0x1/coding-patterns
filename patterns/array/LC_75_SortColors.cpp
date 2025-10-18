/**
 *
 * Source:    LeetCode
 * Problem:   75. Sort Colors
 * Link:      https://leetcode.com/problems/sort-colors/
 *
 *
 * Approach 1:
 * using hasharray to store total numbers of variable in sorted order and then
 * replacing the original elements with our stored information
 *
 *
 * Approach 2: Optimal
 * using dutch national flag algorithm or three partition algorithm, where we
 * create three points for low, mid (pivot) and high, and put mid and low in the
 * starting while high at the end of array, then whlie looping through the array
 * if we find 0 we swap it with low and increment low and mid while if we find a
 * 2 we swap it with high and decrement the high only, while for rest we just
 * increment mid
 *
 */

#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
  int arr[3] = {0};
  for (auto n : nums) arr[n]++;
  int j = 0;
  for (int i = 0; i < arr[0]; i++, j++) nums[j] = 0;
  for (int i = 0; i < arr[1]; i++, j++) nums[j] = 1;
  for (int i = 0; i < arr[2]; i++, j++) nums[j] = 2;
}

void sortColorsOptimal(vector<int>& nums) {
  int low = 0;
  int mid = 0;
  int high = nums.size() - 1;

  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    } else if (nums[mid] == 2) {
      swap(nums[mid], nums[high]);
      high--;
    } else {
      mid++;
    }
  }
}

int main() {
  vector<int> arr = {2, 0, 2, 1, 1, 0};
  sortColorsOptimal(arr);
  for (auto it : arr) cout << it << ", ";
  return 0;
}