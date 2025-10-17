/**
 *
 * Source:    TUF
 * Problem:   Linear Search in C
 * Link:
 * https://takeuforward.org/data-structure/linear-search-in-c/
 *
 *
 * Approach 1:
 * loop through array and compare with num if found return i or at end return -1
 *
 */

#include <bits/stdc++.h>

using namespace std;

int linear_search(vector<int>& nums, int num) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == num) return i;
  }
  return -1;
}

int main() {
  int num = 5;
  vector<int> nums = {0, 1, 2, 3, 4, 6, 7, 10, 5};
  cout << "Solution: " << linear_search(nums, num);
  return 0;
}