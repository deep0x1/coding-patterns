/**
 *
 * Source:    TUF
 * Problem:   Quick Sort Algorithm
 * Link:      https://takeuforward.org/data-structure/quick-sort-algorithm/
 *
 *
 * Approach 1:
 * Select an element from the array, known as the `pivot`.
 * Partition the array by rearranging its elements using a `partition` function
 * so that the pivot is placed in its final sorted position. All elements
 * smaller than the pivot are moved to its left, and all larger elements are
 * moved to its right.
 * This division creates two subarrays. Recursively apply quick sort to the
 * subarray of smaller elements (left of the pivot) and the subarray of larger
 * elements (right of the pivot) until the base case is reached (a subarray
 * with 0 or 1 elements), which is considered sorted.
 *
 */

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[low];
  int left = low;
  int right = high;

  // swap small on right with large on left
  while (left <= right) {
    while (arr[left] <= pivot && left <= high) left++;
    while (arr[right] > pivot && right >= low) right--;
    if (left < right) {
      swap(arr[left], arr[right]);
    }
  }

  // correct position found
  swap(arr[low], arr[right]);
  return right;
}

void quick_sort(vector<int>& arr, int low, int high) {
  // base case
  if (low >= high) return;

  int p_index = partition(arr, low, high);
  quick_sort(arr, low, p_index - 1);
  quick_sort(arr, p_index + 1, high);
}

int main() {
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  int n = arr.size();
  quick_sort(arr, 0, n - 1);
  for (auto it : arr) cout << it << ", ";
  return 0;
}