/**
 *
 * Source:    LeetCode
 * Problem:   2125. Number of Laser Beams in a Bank
 * Link:
 * https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description
 *
 *
 * Approach 1:
 * store last non zero row sum
 *
 */

#include <bits/stdc++.h>

using namespace std;

int row_sum(string& s) {
  int sum = 0;
  for (auto c : s) sum += (c == '1');
  return sum;
}

int numberOfBeams(vector<string>& bank) {
  int total_beams = 0;
  int prev_row_devices = 0;

  for (auto row : bank) {
    int current_row_devices = row_sum(row);
    if (current_row_devices > 0) {
      total_beams += current_row_devices * prev_row_devices;
      prev_row_devices = current_row_devices;
    }
  }

  return total_beams;
}

int main() {
  vector<string> bank = {"011001", "000000", "010100", "001000"};
  int ans = numberOfBeams(bank);
  cout << ans;
  return 0;
}