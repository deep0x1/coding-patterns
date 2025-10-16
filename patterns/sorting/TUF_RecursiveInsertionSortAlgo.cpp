/**
 *
 * Source:    TUF
 * Problem:   Recursive Insertion Sort Algorithm
 * Link:      https://takeuforward.org/arrays/recursive-insertion-sort-algorithm/
 *
 *
 * Approach 1:
 * comparing the key element with elemens before it untill correct position is
 * found while shifting all compared element to the right, recursivly calling it
 * with pvoit+1 untill end is reached;
 *
 */

#include <bits/stdc++.h>
#define ARR_MAX 1000

using namespace std;

void insertion_sort(int arr[], int pivot, int size) {
  // base case
  if (pivot > size) return;

  int key = arr[pivot];
  int temp = pivot - 1;
  while (temp >= 0 && arr[temp] > key) {
    arr[temp + 1] = arr[temp];
    temp--;
  }
  arr[temp + 1] = key;
  insertion_sort(arr, pivot + 1, size);
}

int main() {
  int N, arr[ARR_MAX];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  insertion_sort(arr, 1, N - 1);
  for (int i = 0; i < N; i++) cout << arr[i] << ", ";
  return 0;
}