/**
 *
 * Source:    TUF
 * Problem:   Bubble Sort Algorithm
 * Link:      https://takeuforward.org/data-structure/bubble-sort-algorithm/
 *
 *
 * Approach 1:
 * loop through whole array (size times), while comparing current element with
 * next element, if they are not sorted; just swap them
 *
 */

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    bool did_swap = false;
    for (int j = 0; j < (size - i - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        did_swap = true;
      }
    }
    if (!did_swap) break;
  }
}

int main() {
  int N;
  int arr[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  bubble_sort(arr, N);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}