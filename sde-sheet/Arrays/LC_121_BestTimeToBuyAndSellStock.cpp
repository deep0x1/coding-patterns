/**
 *
 * Source:    LeetCode
 * Problem:   121. Best Time to Buy and Sell Stock
 * Link:      leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * initilize minPrice (prices[0]) and maxProfit (0)
 * to get the best profit we must buy it on the lest price so while looping
 * though the array we keep track of lowest price we saw before today
 *
 */

#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
  // phase 1: initilization
  int minPrice = INT_MAX;
  int maxProfit = 0;

  // phase 2: loop through prices and compare profit
  for (auto price : prices) {
    if (price < minPrice) {
      minPrice = price;
    } else {
      int profit = price - minPrice;
      maxProfit = max(maxProfit, profit);
    }
  }

  return maxProfit;
}

int main() {
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  cout << maxProfit(nums);
  return 0;
}