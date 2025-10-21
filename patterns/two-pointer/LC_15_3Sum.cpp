/**
 *
 * Source:    LeetCode
 * Problem:   15. 3Sum
 * Link:      https://leetcode.com/problems/3sum/description/
 *
 *
 * Approach 1:
 * sort and two pointer
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    int j = i + 1;
    int k = n - 1;
    while (j < k && j < n && k > i) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum < 0) {
        j++;
      } else if (sum > 0) {
        k--;
      } else {
        ans.push_back({nums[i], nums[j], nums[k]});
        j++;
        k--;
        while (j < k && nums[j] == nums[j - 1]) j++;
        while (k > j && nums[k] == nums[k + 1]) k--;
      }
    }
  }

  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = threeSum(nums);
  for (auto row : result) {
    for (auto n : row) {
      cout << n << ", ";
    }
    cout << "\n";
  }
  return 0;
}
