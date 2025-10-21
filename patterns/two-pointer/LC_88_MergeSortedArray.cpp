/**
 *
 * Source:    LeetCode
 * Problem:   88. Merge Sorted Array
 * Link:      https://leetcode.com/problems/merge-sorted-array/description/
 *
 *
 * Approach 1:
 * two pointer from back
 *
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int l = m - 1;
  int k = n - 1;
  int i = nums1.size() - 1;
  cout << l << " | " << k << " | " << i << "\n";
  while (l >= 0 && k >= 0) {
    if (nums1[l] >= nums2[k]) {
      nums1[i] = nums1[l];
      l--;
    } else {
      nums1[i] = nums2[k];
      k--;
    }
    i--;
    cout << "test";
  }
  while (l >= 0) nums1[i--] = nums1[l--];
  while (k >= 0) nums1[i--] = nums2[k--];
}

int main() {
  vector<int> nums1 = {0};
  int m = 0;
  vector<int> nums2 = {1};
  int n = nums2.size();
  merge(nums1, m, nums2, n);
  for (auto i : nums1) {
    cout << i << ", ";
  }
  return 0;
}
