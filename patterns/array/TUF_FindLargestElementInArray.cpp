/**
 *
 * Source:    TUF
 * Problem:   Find the Largest element in an array
 * Link:
 * https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
 *
 *
 * Approach 1:
 * Initialize `max` variable with INT_MIN and then loop through the array while
 * comparing each element with max, if any element is greater than max, repalce
 * max with that element;
 *
 */

#include <bits/stdc++.h>

using namespace std;

int largest_elem(int arr[], int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int n = 5;
  int arr[] = {2, 5, 1, 3, 0};
  cout << "Solution: " << largest_elem(arr, n);
  return 0;
}