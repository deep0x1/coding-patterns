/**
 *
 * Source:    TUF
 * Problem:   Insertion Sort Algorithm
 * Link:      https://takeuforward.org/data-structure/insertion-sort-algorithm/
 *
 *
 * Approach 1:
 * Loop through the array, treating each element as a 'key'.
 * Shift all larger elements on the left one position to the right
 * to make space, then place the key in its correct sorted position.
 *
 */

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j++;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int N;
  int arr[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  // bubble_sort(arr, N);
  insertion_sort(arr, N);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}