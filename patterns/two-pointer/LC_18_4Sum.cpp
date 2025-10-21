/**
 *
 * Source:    LeetCode
 * Problem:   18. 4Sum
 * Link:      https://leetcode.com/problems/4sum/description/
 *
 *
 * Approach 1:
 * sort and two pointer (3sum solution approach)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    for (int j = i + 1; j < n; j++) {
      // ignore dublicate j
      if (j > (i + 1) && nums[j] == nums[j - 1]) continue;

      int k = j + 1;
      int l = n - 1;
      while (k < l) {
        // (long long) to avoid int overflow
        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
        if (sum > target) {
          l--;
        } else if (sum < target) {
          k++;
        } else {
          ans.push_back({nums[i], nums[j], nums[k], nums[l]});
          k++;
          l--;
          while (k <= l && nums[k] == nums[k - 1]) k++;
          while (l >= k && nums[l] == nums[l + 1]) l--;
        }
      }
    }
  }

  return ans;
}

int main() {
  int k = 0;
  vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
  vector<vector<int>> result = fourSum(nums, k);
  for (auto row : result) {
    for (auto n : row) {
      cout << n << ", ";
    }
    cout << "\n";
  }
  return 0;
}
