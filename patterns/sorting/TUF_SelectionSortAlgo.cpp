/**
 *
 * Source:    TUF
 * Problem:   Selection Sort Algorithm
 * Link:      https://takeuforward.org/sorting/selection-sort-algorithm/
 *
 *
 * Approach 1:
 * loop through whole array, find the minimum, swap it with current, move
 * current point and repeat untill whole array is sorted
 *
 */

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int min_idx = i;
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(arr[i], arr[min_idx]);
  }
}

int main() {
  int N;
  int arr[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  selection_sort(arr, N);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}