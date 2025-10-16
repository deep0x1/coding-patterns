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
#define ARR_MAX 1000

using namespace std;

void merge(int arr[], int low, int mid, int high) {
  int temp[ARR_MAX];
  int idx = 0;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high) {
    if (arr[left] < arr[right]) {
      temp[idx++] = arr[left];
      left++;
    } else {
      temp[idx++] = arr[right];
      right++;
    }
  }
  while (left <= mid) {
    temp[idx++] = arr[left];
    left++;
  }
  while (right <= high) {
    temp[idx++] = arr[right];
    right++;
  }

  cout << idx << " || ";
  for (int i = low, j = 0; i <= high; i++, j++) {
    cout << temp[j] << ",";
    arr[i] = temp[j];
  }
  cout << "\n";
}

void merge_sort(int arr[], int low, int high) {
  // base case
  if (low == high) return;

  // divide
  int target = (low + high) / 2;
  merge_sort(arr, low, target);
  merge_sort(arr, target + 1, high);
  merge(arr, low, target, high);
}

int main() {
  int N;
  int arr[ARR_MAX];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  merge_sort(arr, 0, N - 1);
  for (int i = 0; i < N; i++) cout << arr[i] << ", ";
  return 0;
}