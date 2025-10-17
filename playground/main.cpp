/**
 *
 * Source:    TUF
 * Problem:   Merge Sort Algorithm
 * Link:
 * https://takeuforward.org/data-structure/merge-sort-algorithm/
 *
 *
 * Approach 1:
 * divide the array into two sub parts and apply merge sort on each, untill
 * singular array are not reached, once returning from singular arrays use
 * `merge` to compare and merge them into a new array using a temp arry and then
 * replacing original array's subsection with temp array.
 *
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int low, int pivot, int high) {
  vector<int> temp;
  int left = low;
  int right = pivot + 1;

  // compare and push
  while (left <= pivot && right <= high) {
    if (arr[left] < arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  // push the rest
  while (left <= pivot) temp.push_back(arr[left++]);
  while (right <= high) temp.push_back(arr[right++]);

  // replace the original
  for (int i = low; i <= high; i++) arr[i] = temp[i - low];
}

void merge_sort(vector<int>& arr, int low, int high) {
  // base case
  if (low >= high) return;

  // divide
  int pivot = low + (high - low) / 2;
  merge_sort(arr, low, pivot);
  merge_sort(arr, pivot + 1, high);
  merge(arr, low, pivot, high);
}

int main() {
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  int n = arr.size();
  merge_sort(arr, 0, n - 1);
  for (auto it : arr) cout << it << ", ";
  return 0;
}