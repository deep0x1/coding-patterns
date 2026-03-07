/**
 *
 * Source:    LC
 * Problem:   3. Longest Substring Without Repeating Characters
 *
 * Link:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * using sliding window apprach with vector map checking if a char exist within
 * the sliding window to slide the window
 *
 */

#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
  vector<int> charMap(256, -1);

  int maxLength = 0;
  int low = 0;
  int high = 0;

  while (high < s.length()) {
    char currentChar = s[high];

    // check if exist and inside current window
    if (charMap[currentChar] != -1 && charMap[currentChar] >= low) {
      low = charMap[currentChar] + 1;
    }

    charMap[currentChar] = high;
    high++;
    maxLength = max(maxLength, high - low);
  }

  return maxLength;
}

int main() {
  string s = "pwwkew";
  cout << lengthOfLongestSubstring(s);
  return 0;
}