/**
 *
 * Source:    TUF
 * Problem:   Count the number of subarrays with given xor K
 * Link:
 * https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
 *
 *
 * Approach 1:
 * prefix sum approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int zeroXOR(vector<int> arr, int target) {
  unordered_map<int, int> p_map;
  int count = 0;
  int current_xor = 0;
  p_map[current_xor]++;
  for (int i = 0; i < arr.size(); i++) {
    current_xor ^= arr[i];
    if (p_map.count(current_xor ^ target)) {
      count += p_map[current_xor ^ target];
    }
    p_map[current_xor]++;
  }
  return count;
}

int main() {
  int k = 5;
  vector<int> arr = {5, 6, 7, 8, 9};
  int ans = zeroXOR(arr, k);
  cout << ans;
  return 0;
}
