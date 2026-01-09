/**
 *
 * Source:    LeetCode
 * Problem:   88. Merge Sorted Array
 * Link:      https://leetcode.com/problems/merge-sorted-array/
 *
 *
 * Time: O(N+M)
 * Space: O(1)
 *
 *
 * Approach:
 * initilize three pointers (pivot1, pivot2 and pivotN)
 * pivot 1 loop backward in nums1
 * pivot 2 loop backward in nums2
 * pivot N is the filling pivot for final array (nums1)
 * loop and compare element and push the bigger ones on pivotN's position
 *
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  // phase 1: initlization
  int pivot1 = m - 1;
  int pivot2 = n - 1;
  int pivotN = nums1.size() - 1;

  // phase 2: lopo though arrays and compare
  while (pivot1 >= 0 && pivot2 >= 0) {
    if (nums1[pivot1] > nums2[pivot2]) {
      nums1[pivotN--] = nums1[pivot1--];
    } else {
      nums1[pivotN--] = nums2[pivot2--];
    }
  }

  // phase 3: fill rest of elements
  while (pivot1 >= 0) nums1[pivotN--] = nums1[pivot1--];
  while (pivot2 >= 0) nums1[pivotN--] = nums2[pivot2--];
}

int main() {
  int n = 3;
  int m = 3;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 4, 6};
  merge(nums1, m, nums2, n);
  for (auto num: nums1) {
    cout << num << ", ";
  }
  return 0;
}