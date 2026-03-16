/**
 *
 * Source:    LC
 * Problem:   322. Coin Change
 *
 *
 * Link:
 * https://leetcode.com/problems/coin-change/description/
 *
 *
 * Time: O(N^2)
 * Space: O(N)
 *
 *
 * Approach:
 * using dynamic programming to calculate least possible coins needed to make an
 * amount by comparing current_target - coin_amount
 *
 */

#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
  int INF = amount + 1;
  vector<int> dp(amount + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
    for (auto coin : coins) {
      int target = i - coin;
      if (target >= 0) {
        dp[i] = min(dp[i], dp[target] + 1);
      }
    }
  }

  if (dp[amount] == INF) return -1;
  return dp[amount];
}

int main() {
  vector<int> coins = {5, 5};
  int amount = 8;
  cout << coinChange(coins, amount);
  return 0;
}