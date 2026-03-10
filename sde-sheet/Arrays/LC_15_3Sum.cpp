/**
 *
 * Source:    LC
 * Problem:   15. 3Sum
 *
 *
 * Link:
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 *
 * Time: O(NLogN)
 * Space: O(N)
 *
 *
 * Approach:
 * fixing first element and then using two pointer approach as in to solve 2Sum
 * problem
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> sol;
  int n = nums.size();
  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    // skip duplicates for first elem
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    // two pointer approach
    int low = i + 1;
    int high = n - 1;

    while (low < high) {
      long long sum = (long long)nums[i] + nums[low] + nums[high];

      if (sum < 0)
        low++;
      else if (sum > 0)
        high--;
      else {
        sol.push_back({nums[i], nums[low], nums[high]});
        low++;
        high--;

        // skip duplicates for second and last elem
        while (low < high && nums[low] == nums[low - 1]) low++;
        while (low < high && nums[high] == nums[high + 1]) high--;
      }
    }
  }

  return sol;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> sol = threeSum(nums);
  for (auto row : sol) {
    for (auto col : row) cout << col << ", ";
    cout << "\n";
  }
  return 0;
}