/**
 *
 * Source:    LeetCode
 * Problem:   229. Majority Element II
 * Link:      https://leetcode.com/problems/majority-element-ii/description/
 *
 *
 * Approach 1:
 * using ordered map
 * 
 * Approach 2: Optimal
 * using boyer moore's voting algorithm with two targets 
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElementOptimal(vector<int>& nums) {
  int t1 = 0, t2 = 0;
  int count1 = 0, count2 = 0;
  for (auto num : nums) {
    if (num == t1) {
      count1++;
    } else if (num == t2) {
      count2++;
    } else if (count1 == 0) {
      t1 = num;
      count1 = 1;
    } else if (count2 == 0) {
      t2 = num;
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }

  // checking if target is > n/3;
  count1 = count2 = 0;
  for (auto num : nums) {
    if (num == t1) count1++;
    if (num == t2) count2++;
  }

  vector<int> result;
  int n = nums.size() / 3;
  if (count1 > n) result.push_back(t1);
  if (count2 > n && t2 != t1) result.push_back(t2);

  return result;
}

vector<int> majorityElement(vector<int>& nums) {
  map<int, int> mpp;
  vector<int> result;
  int n = nums.size() / 3;
  for (auto num : nums) mpp[num]++;
  for (auto num : mpp) {
    if (num.second > n) result.push_back(num.first);
  }
  return result;
}

int main() {
  vector<int> nums = {3, 1, 3};
  vector<int> result = majorityElementOptimal(nums);
  for (auto n : result) cout << n << ", ";
  return 0;
}
