/**
 *
 * Source:    LeetCode
 * Problem:   875. Koko Eating Bananas
 * Link:
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 *
 * Approach 1:
 * using binary search approach on the range of possible solutions 1 - max_elem
 *
 */

#include <bits/stdc++.h>

using namespace std;

int checker(vector<int>& piles, int n) {
  int count = 0;
  for (auto banana : piles) {
    count += (banana / n);
    if (banana % n != 0) count++;
  }
  return count;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int max_val = *max_element(piles.begin(), piles.end());
  int left = 1;
  int right = max_val;
  int ans = -1;

  while (left <= right) {
    int mid = (left + right) / 2;
    int sol = checker(piles, mid);

    if (sol <= h) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return ans;
}

int main() {
  int h = 312884469;
  vector<int> piles = {312884470};
  int ans = minEatingSpeed(piles, h);
  // bool ans = checker(piles, h, 4);
  cout << ans;
  return 0;
}