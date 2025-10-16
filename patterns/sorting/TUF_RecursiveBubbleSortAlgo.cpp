/**
 *
 * Source:    TUF
 * Problem:   Recursive Bubble Sort Algorithm
 * Link:      https://takeuforward.org/arrays/recursive-bubble-sort-algorithm/
 *
 *
 * Approach 1:
 * loop through the array once while swaping bigger element by shorter ones on
 * there right adgecent element and then recursivly recall the function with
 * size - 1
 *
 */

#include <bits/stdc++.h>
#define ARR_MAX 1000

using namespace std;

void bubble_sort(int arr[], int size) {
  if (size < 1) return;
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
  }
  bubble_sort(arr, size - 1);
}

int main() {
  int N;
  int arr[ARR_MAX];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  bubble_sort(arr, N - 1);
  for (int i = 0; i < N; i++) cout << arr[i] << ", ";
  return 0;
}