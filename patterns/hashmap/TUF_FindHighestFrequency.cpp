/**
 *
 * Source:    TUF
 * Problem:   Find the highest/lowest frequency element
 * Link:
 * https://takeuforward.org/arrays/find-the-highest-lowest-frequency-element/
 *
 *
 * Approach 1: OPTIMAL
 * using unordered and updating min_frequency and max_frequency pairs
 *
 */

#include <bits/stdc++.h>
using namespace std;

void print_frequency_range(int arr[], int size) {
  unordered_map<int, int> mpp;
  for (int i = 0; i < size; i++) {
    mpp[arr[i]]++;
  }

  pair<int, int> max_frequency = {0, -INT_MAX};
  pair<int, int> min_frequency = {0, INT_MAX};
  for (auto it : mpp) {
    if (it.second >= max_frequency.second) {
      max_frequency.first = it.first;
      max_frequency.second = it.second;
    }
    if (it.second <= min_frequency.second) {
      min_frequency.first = it.first;
      min_frequency.second = it.second;
    }
  }

  cout << max_frequency.first << " " << min_frequency.first << "\n";
}

int main() {
  int N;
  int arr[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  // count_frequency(arr, N);
  print_frequency_range(arr, N);
  return 0;
}