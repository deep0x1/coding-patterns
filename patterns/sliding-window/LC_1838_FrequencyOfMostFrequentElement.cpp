/**
 *
 * Source:    LeetCode
 * Problem:   1838. Frequency of the Most Frequent Element
 * Link:
 * https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
 *
 *
 * Approach 1:
 * Loop through the array, treating each element as a 'key'.
 * Shift all larger elements on the left one position to the right
 * to make space, then place the key in its correct sorted position.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
  // Defining sliding window
  int w_left = 0;
  int w_right = 0;
  int w_sum = 0;
  int max_freq = 0;

  // Sorting nums
  sort(nums.begin(), nums.end());

  for (w_right = 0; w_right < nums.size(); w_right++) {
    // Calculate window sum
    w_sum += nums[w_right];

    // Check validity
    int w_size = w_right - w_left + 1;
    int cost = (nums[w_right] * w_size) - w_sum;
    while (cost > k) {
      w_sum -= nums[w_left];
      w_left++;

      w_size = w_right - w_left + 1;
      cost = (nums[w_right] * w_size) - w_sum;
    }

    // Update max frequency
    max_freq = max(max_freq, w_size);
  }

  return max_freq;
}

int main() {
  vector<int> nums = {3, 9, 6};
  int k = 2;
  // maxFrequency(nums, k);
  cout << "Solution:\t" << maxFrequency(nums, k);
  return 0;
}