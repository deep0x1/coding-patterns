/**
 *
 * Source:    LeetCode
 * Problem:   1526. Minimum Number of Increments on Subarrays to Form a Target Array
 * Link:
 * https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
 *
 *
 * Approach 1:
 * brute force approach
 *
 *
 * Approach 2: Optimal
 * in this approach we start from frist element and in order to increase heigth
 * of first element from 0, we need to make target[0] operations so is
 * target[0], now when we move to the next element we check if the next element
 * is greater than previous one, if the previous element was larger than current
 * element then we have to do nothing as the operations from previous elements
 * would have increment current one too via subarray property, and if the
 * previous element was smaller than we will assume that current element was
 * incremented till previous element so new operations needed will be curr_elem
 * - prev_elem
 *
 */

#include <bits/stdc++.h>

using namespace std;

int minNumberOperations(vector<int>& target) {
  int max_elem = *max_element(target.begin(), target.end());
  int arr_max = 0;
  int oprs = 0;

  while (arr_max <= max_elem) {
    int right = 0, left = 0;
    while (right < target.size()) {
      if (target[right] > arr_max) {
        right++;

      } else {
        if (left < right) oprs++;
        right++;
        left = right;
      }
    }
    if (left < right) oprs++;

    arr_max++;
  }

  return oprs;
}

int minNumberOperationsOptimal(vector<int>& target) {
  int result = target[0];
  for (int i = 1; i < target.size(); i++) {
    if (target[i] > target[i - 1]) {
      result += target[i] - target[i - 1];
    }
  }
  return result;
}

int main() {
  vector<int> nums = {1, 2, 3, 2, 1};
  int ans = minNumberOperationsOptimal(nums);
  cout << ans;
  return 0;
}