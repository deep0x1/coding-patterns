/**
 *
 * Source:    LeetCode
 * Problem:   18. 4Sum
 *
 * Link:
 * https://leetcode.com/problems/4sum/description/
 *
 *
 * Time: O(N^3)
 * Space: O(1)
 *
 *
 * Approach:
 * nest looping the array twice and using two pointer approach to solve for 4sum
 * (1 + 1 + 2sum)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> sol;
  int n = nums.size();
  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    // skip dublicate first elem
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    for (int j = i + 1; j < n; j++) {
      // skip dublicate second elem
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;

      int low = j + 1;
      int high = n - 1;

      while (low < high) {
        long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];

        if (sum == target) {
          sol.push_back({nums[i], nums[j], nums[low], nums[high]});
          low++;
          high--;

          // skip dublicate third and forth elem
          while (low < high && nums[low] == nums[low - 1]) low++;
          while (low < high && nums[high] == nums[high + 1]) high--;

        } else if (sum < target) {
          low++;

        } else {
          high--;
        }
      }
    }
  }

  return sol;
}

int main() {
  vector<int> nums = {2, 2, 2, 2, 2};
  int target = 8;
  for (auto n : fourSum(nums, target)) {
    for (auto m : n) cout << m << ", ";
    cout << "\n";
  }
  return 0;
}