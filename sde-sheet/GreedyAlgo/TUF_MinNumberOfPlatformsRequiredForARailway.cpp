/**
 *
 * Source:    TUF
 * Problem:   Minimum number of platforms required for a railway
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * sort both arrival and depature and loop though both one by one, if a train
 * arrives before the last one deperatues we increase current_platforms else we
 * decrease current_platforms
 *
 */

#include <bits/stdc++.h>

using namespace std;

int minPlatform(vector<int>& arr, vector<int>& dep) {
  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());

  int n = arr.size();
  int i = 0;
  int j = 0;
  int current_platforms = 0;
  int max_platforms = 0;

  while (i < n && j < n) {
    if (arr[i] <= dep[j]) {
      current_platforms++;
      i++;
    } else {
      current_platforms--;
      j++;
    }
    max_platforms = max(max_platforms, current_platforms);
  }

  return max_platforms;
}

int main() {
  vector<int> arr = {0, 45, 55, 120, 360, 720};
  vector<int> dep = {20, 180, 150, 170, 600, 660};
  int k = minPlatform(arr, dep);
  cout << k;
  return 0;
}