/**
 *
 * Source:    LC
 * Problem:   4. Median of Two Sorted Arrays
 *
 *
 * Link:
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 *
 * Time: O(Log(M + N))
 * Space: O(1)
 *
 *
 * Approach:
 * here instead of mergin the two sorted array we are trying to make 1 cut in
 * each, we use binary search to make our first cut in the shorted array and
 * then based on the number of elements on its right we decide where to make the
 * cut on the second array respectivly, if the cuts satisfy the condition of L1
 * <= R2 && L2 <= R1, we find out perfect split else we continue our binary
 * search
 *
 */

#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
  }

  int n = nums1.size();
  int m = nums2.size();
  int low = 0;
  int high = n;

  while (low <= high) {
    int cut1 = low + (high - low) / 2;
    int cut2 = ((n + m + 1) / 2) - cut1;

    int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
    int R1 = (cut1 == n) ? INT_MAX : nums1[cut1];

    int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
    int R2 = (cut2 == m) ? INT_MAX : nums2[cut2];

    if (L1 <= R2 && L2 <= R1) {
      if ((n + m) % 2) {
        return max(L1, L2);
      } else {
        return (max(L1, L2) + min(R1, R2)) / 2.0;
      }
    } else if (L1 > R2) {
      high = cut1 - 1;
    } else {
      low = cut1 + 1;
    }
  }

  return 0.0;
}

int main() {
  vector<int> nums1 = {1, 2, 4, 6};
  vector<int> nums2 = {3, 5, 7};
  cout << findMedianSortedArrays(nums1, nums2);
  return 0;
}