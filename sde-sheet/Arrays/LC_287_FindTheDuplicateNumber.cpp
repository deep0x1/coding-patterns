/**
 *
 * Source:    LeetCode
 * Problem:   287. Find the Duplicate Number
 * Link:      https://leetcode.com/problems/find-the-duplicate-number/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using floyd's tortise and hare alogirhtm (linked-list cycle)
 * initilize two pointers slow (0) and fast (0)
 * move slow with 1 step and fast with 2 step untill they collide
 * reset the slow pointer to 0 and now move them both by 1 step this time untill
 * another collision, this collision is the entry of cycle hence duplicate
 * number
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
  // phase 1: initilization
  int slow = 0;
  int fast = 0;

  // phase 2: finding cycle
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  // phase 3: finding cycle entry point
  slow = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main() {
  vector<int> nums = {1, 3, 4, 2, 2};
  cout << findDuplicate(nums);
  return 0;
}