/**
 *
 * Source:    LeetCode
 * Problem:   121. Best Time to Buy and Sell Stock
 * Link:      https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 *
 * Approach 1:
 * two pointer
 *
 *
 * Appraoch 2: Optimal
 * finding minimum price while comparing possible profits with old minimum
 *
 */

#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
  int left = 0;
  int right = 0;
  int m_profit = 0;

  for (right = 0; right < prices.size(); right++) {
    int profit = prices[right] - prices[left];
    m_profit = max(profit, m_profit);
    while (prices[left] >= prices[right] && left < right) left++;
  }

  return m_profit;
}

int maxProfitOptimal(vector<int>& prices) {
  int m_profit = 0;
  int min_price = INT_MAX;
  for (auto price : prices) {
    if (price < min_price) {
      min_price = price;
    } else {
      int profit = price - min_price;
      m_profit = max(profit, m_profit);
    }
  }
  return m_profit;
}

int main() {
  vector<int> arr = {1, 2, 3, 1, 5, 3, 2, 8};
  int sol = maxProfitOptimal(arr);
  cout << sol;
  return 0;
}