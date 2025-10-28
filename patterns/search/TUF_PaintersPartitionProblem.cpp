/**
 *
 * Source:    TUF
 * Problem:   Painter's Partition Problem
 * Link:
 * https://takeuforward.org/arrays/painters-partition-problem/
 *
 *
 * Approach 1:
 * binary search on answer, where range of ans is [max(), sum()]
 *
 */

#include <bits/stdc++.h>

using namespace std;

int count_painters(vector<int>& boards, int area) {
  int total_painters = 1;
  int crt_sum = 0;
  for (auto n : boards) {
    if (crt_sum + n > area) {
      total_painters++;
      crt_sum = n;
    } else {
      crt_sum += n;
    }
  }
  return total_painters;
}

int findLargestMinDistance(vector<int>& boards, int painters) {
  int left = *max_element(boards.begin(), boards.end());
  int right = accumulate(boards.begin(), boards.end(), 0);
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int cost = count_painters(boards, mid);
    if (cost > painters) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

int main() {
  int k = 2;
  vector<int> nums = {5, 5, 5, 5};
  int ans = findLargestMinDistance(nums, k);
  cout << ans;
  return 0;
}