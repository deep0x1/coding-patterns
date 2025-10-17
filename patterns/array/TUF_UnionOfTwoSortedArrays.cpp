/**
 *
 * Source:    TUF
 * Problem:   Union of Two Sorted Arrays
 * Link:
 * https://takeuforward.org/data-structure/union-of-two-sorted-arrays/
 *
 *
 * Approach 1:
 * loop through both arrays and inset elements to a `set` then convert it to
 * vector
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> union_array(vector<int>& nums1, vector<int>& nums2) {
  set<int> temp_set;
  int i, j;
  for (i = 0, j = 0; i < nums1.size() && j < nums2.size(); i++, j++) {
    temp_set.insert(nums1[i]);
    temp_set.insert(nums2[j]);
  }
  for (; i < nums1.size(); i++) {
    temp_set.insert(nums1[i]);
  }
  for (; j < nums2.size(); j++) {
    temp_set.insert(nums2[j]);
  }
  vector<int> sol(temp_set.begin(), temp_set.end());
  return sol;
}

int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> nums2 = {2, 3, 4, 4, 5, 11, 12};
  vector<int> sol = union_array(nums1, nums2);
  for (auto num : sol) cout << num << ", ";
  return 0;
}