/**
 *
 * Source:    LC
 * Problem:   K-th Element of two sorted arrays
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays
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

int get_kth_element(vector<int>& nums1, vector<int>& nums2, int k) {
  if (nums1.size() > nums2.size()) {
    return get_kth_element(nums2, nums1, k);
  }

  int n = nums1.size();
  int m = nums2.size();
  int low = max(0, k - m);
  int high = min(n, k);

  while (low <= high) {
    int cut1 = low + (high - low) / 2;
    int cut2 = k - cut1;

    int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
    int R1 = (cut1 == n) ? INT_MAX : nums1[cut1];

    int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
    int R2 = (cut2 == m) ? INT_MAX : nums2[cut2];

    if (L1 <= R2 && L2 <= R1)
      return max(L1, L2);
    else if (L1 > R2)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }

  return 0;
}

int main() {
  vector<int> nums1 = {100, 112, 256, 349, 770};
  vector<int> nums2 = {72, 86, 113, 119, 265, 445, 892};
  int k = 7;
  cout << get_kth_element(nums1, nums2, k);
  return 0;
}