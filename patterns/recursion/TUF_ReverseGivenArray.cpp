/**
 *
 * Source:    TUF
 * Problem:   Reverse a given Array
 * Link:
 * https://takeuforward.org/data-structure/reverse-a-given-array/
 *
 *
 * Approach 1:
 * moving start and end pointer toward enter untill they cross each other while
 * swapping there elements
 *
 */

#include <bits/stdc++.h>
using namespace std;

void ReverseRecursive(int *arr, int start, int end) {
  if (start < end) {
    swap(arr[start], arr[end]);
    ReverseRecursive(arr, start + 1, end - 1);
  }
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  ReverseRecursive(arr, 0, 4);
  for (auto elem : arr) cout << elem << "\n";
  return 0;
}