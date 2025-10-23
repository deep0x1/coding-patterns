/**
 *
 * Source:    TUF
 * Problem:   Count Occurrences in Sorted Array
 * Link:
 * https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/
 *
 *
 * Approach 1:
 * using binary search upper and lower bound approach
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

int countOccurance(vector<int>& arr, int target) {
  int l_b = lower_bound(arr, target);
  if (l_b == -1 || arr[l_b] != target) return 0;
  int u_b = upper_bound(arr, target);
  return u_b - l_b;
}

int main() {
  int target = 2;
  vector<int> arr = {1, 1, 2, 2, 2, 2, 2, 3};
  int ans = countOccurance(arr, target);
  cout << ans;
  return 0;
}