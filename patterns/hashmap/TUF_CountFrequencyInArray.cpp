/**
 *
 * Source:    TUF
 * Problem:   Count frequency of each element in the array
 * Link:
 * https://takeuforward.org/data-structure/count-frequency-of-each-element-in-the-array/
 *
 *
 * Approach 1:
 * using array hash, heavy on size
 *
 *
 * Approach 2: OPTIMAL
 * using unordered map, note here, mpp[arr[i]]++ is directly used, because
 * default value of map are 0
 *
 */

#include <bits/stdc++.h>
using namespace std;

void count_frequency(int arr[], int size) {
  const int frequency_size = 100;
  int frequency[frequency_size] = {0};
  for (int i = 0; i < size; i++) {
    frequency[arr[i]]++;
  }
  for (int i = 0; i < frequency_size; i++) {
    if (frequency[i] > 0) {
      cout << i << " -> " << frequency[i] << "\n";
    }
  }
}

void count_frequency_optimal(int arr[], int size) {
  unordered_map<int, int> mpp;
  for (int i = 0; i < size; i++) {
    mpp[arr[i]]++;
  }
  for (auto it : mpp) {
    cout << it.first << " -> " << it.second << "\n";
  }
}

int main() {
  int N;
  int arr[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  // count_frequency(arr, N);
  count_frequency_optimal(arr, N);
  return 0;
}