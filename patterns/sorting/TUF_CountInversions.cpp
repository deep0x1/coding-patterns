/**
 *
 * Source:    TUF
 * Problem:   Count inversions in an array
 * Link:
 * https://takeuforward.org/data-structure/count-inversions-in-an-array/
 *
 *
 * Approach 1:
 * merge sort approach
 * here we are using `count += (mid - l + 1)` because both side of side of array
 * are sorted after `mid` so if elemnt from right is smaller than an element on
 * left then it must be smaller than all other elements after l upto mid
 *
 */

#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
  vector<int> temp;
  int count = 0;

  int l = low;
  int r = mid + 1;

  while (l <= mid && r <= high) {
    if (arr[l] <= arr[r]) {
      temp.push_back(arr[l++]);
    } else {
      temp.push_back(arr[r++]);
      count += (mid - l + 1);
    }
  }

  while (l <= mid) temp.push_back(arr[l++]);
  while (r <= high) temp.push_back(arr[r++]);
  for (int i = low; i <= high; i++) arr[i] = temp[i - low];
  return count;
}

int merge_sort(vector<int>& arr, int low, int high) {
  if (low >= high) return 0;

  int pairs = 0;
  int mid = (low + high) / 2;
  pairs += merge_sort(arr, low, mid);
  pairs += merge_sort(arr, mid + 1, high);
  pairs += merge(arr, low, mid, high);
  return pairs;
}

int numberOfInversions(vector<int>& arr) {
  int n = arr.size() - 1;
  int ans = merge_sort(arr, 0, n);
  return ans;
}

int main() {
  vector<int> arr = {5, 4, 3, 2, 1};
  int ans = numberOfInversions(arr);
  cout << ans;
  return 0;
}