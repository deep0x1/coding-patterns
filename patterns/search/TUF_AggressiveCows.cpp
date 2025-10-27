/**
 *
 * Source:    TUF
 * Problem:   Aggressive Cows : Detailed Solution
 * Link:
 * https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
 *
 *
 * Approach 1:
 * using binary search approach on possible answer range [1, max() - min()]
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool canWePlace(vector<int>& stalls, int dist, int cows) {
  int n = stalls.size();
  int cntCows = 1;
  int last = stalls[0];
  for (int i = 1; i < n; i++) {
    if (stalls[i] - last >= dist) {
      cntCows++;
      last = stalls[i];
    }
    if (cntCows >= cows) return true;
  }
  return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());

  int left = 1;
  int right = stalls[n - 1] - stalls[0];
  int ans = left;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (canWePlace(stalls, mid, k)) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

int main() {
  int k = 4;
  vector<int> arr = {0, 3, 4, 7, 10, 9};
  int ans = aggressiveCows(arr, k);
  cout << ans;
  return 0;
}