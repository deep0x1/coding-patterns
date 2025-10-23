/**
 *
 * Source:    LeetCode
 * Problem:   34. Find First and Last Position of Element in Sorted Array
 * Link:
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int upper_bound(vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  int idx = right + 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] > target) {
      idx = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return idx;
}

int lower_bound(vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  int idx = left - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] >= target) {
      idx = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return idx;
}

vector<int> searchRange(vector<int>& arr, int target) {
  int l_b = lower_bound(arr, target);
  if (l_b == -1 || arr[l_b] != target) return {-1, -1};

  int u_b = upper_bound(arr, target);
  return {l_b, u_b - 1};
}

int main() {
  int target = 3;
  vector<int> arr = {2, 2, 3, 3, 3, 3, 3};
  vector<int> ans = searchRange(arr, target);
  cout << ans[0] << ", " << ans[1];
  return 0;
}