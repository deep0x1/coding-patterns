/**
 *
 * Source:    TUF
 * Problem:   Find Second Smallest and Second Largest Element in an array
 * Link:
 * https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/
 *
 *
 * Approach 1:
 * Initialize 4 values, two for max and two for min, while looping through the
 * array compare and shift values from 1 -> 2
 *
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> solution(int arr[], int n) {
  // edge case
  if (n < 2) return {-1, -1};

  int max1 = INT_MIN;
  int max2 = max1;
  int min1 = INT_MAX;
  int min2 = min1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max1) {
      max2 = max1;
      max1 = arr[i];
    } else if (arr[i] > max2 && arr[i] != max1) {
      max2 = arr[i];
    }

    if (arr[i] < min1) {
      min2 = min1;
      min1 = arr[i];
    } else if (arr[i] < min2 && arr[i] != min1) {
      min2 = arr[i];
    }
  }
  return {max2, min2};
}

int main() {
  int n = 5;
  int arr[] = {2, 5, 1, 3, 0};
  pair<int, int> sol = solution(arr, n);
  cout << sol.first << ", " << sol.second;
  return 0;
}