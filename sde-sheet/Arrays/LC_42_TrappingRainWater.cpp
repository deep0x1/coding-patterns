/**
 *
 * Source:    LC
 * Problem:   42. Trapping Rain Water
 *
 *
 * Link:
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * calcuating water trapped above each block using min(leftMax, rightMax) -
 * blockHeight;
 *
 */

#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
  int n = height.size();
  vector<int> leftMax(n);
  vector<int> rightMax(n);

  int temp = 0;
  for (int i = 0; i < n; i++) {
    temp = max(height[i], temp);
    leftMax[i] = temp;
  }

  temp = 0;
  for (int i = n - 1; i >= 0; i--) {
    temp = max(height[i], temp);
    rightMax[i] = temp;
  }

  int water = 0;
  for (int i = 1; i < n - 1; i++) {
    int waterAbove = min(leftMax[i], rightMax[i]) - height[i];
    if (waterAbove > 0) water += waterAbove;
  }

  return water;
}

int main() {
  vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int k = trap(nums);
  cout << k << endl;
  return 0;
}