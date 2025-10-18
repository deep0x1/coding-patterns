/**
 *
 * Source:    LeetCode
 * Problem:   2149. Rearrange Array Elements by Sign
 * Link:
 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
 *
 *
 * Approach 1:
 * two pointer
 *
 *
 * Appraoch 2: Optimal
 * question (leetcode) editorial's approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
  int pos = 0;
  int neg = 0;
  vector<int> sol;
  for (int i = 0; i < nums.size(); i += 2) {
    // find next positive and negative number
    while (nums[pos] < 0) pos++;
    while (nums[neg] >= 0) neg++;

    // push next positive and negative number
    sol.push_back(nums[pos++]);
    sol.push_back(nums[neg++]);
  }
  return sol;
}

vector<int> rearrangeArrayOptimal(vector<int>& nums) {
  int p_index = 0;
  int n_index = 1;
  vector<int> sol(nums.size());
  for (auto num : nums) {
    if (num < 0) {
      sol[n_index] = num;
      n_index += 2;
    } else {
      sol[p_index] = num;
      p_index += 2;
    }
  }
  return sol;
}

int main() {
  vector<int> arr = {3, 1, -2, -5, 2, -4};
  vector<int> sol = rearrangeArrayOptimal(arr);
  for (auto n : sol) cout << n << ", ";
  return 0;
}