/**
 *
 * Source:    TUF
 * Problem:   Leaders in an Array
 * Link:
 * https://takeuforward.org/data-structure/leaders-in-an-array/
 *
 *
 * Approach 1:
 * looping from behind while comparing with max
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> find_leader(vector<int>& nums) {
  vector<int> sol;
  int last = INT_MIN;
  int n = nums.size() - 1;
  for (int i = n; i >= 0; i--) {
    if (nums[i] > last) {
      sol.push_back(nums[i]);
      last = nums[i];
    }
  }
  reverse(sol.begin(), sol.end());
  return sol;
}

int main() {
  vector<int> nums = {10, 22, 12, 3, 0, 6};
  vector<int> sol = find_leader(nums);
  for (auto n : sol) cout << n << ", ";
  return 0;
}
