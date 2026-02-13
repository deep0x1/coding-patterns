/**
 *
 * Source:    LeetCode
 * Problem:   493. Reverse Pairs
 *
 * Link:
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 *
 * Time: O(NLogN)
 * Space: O(N)
 *
 *
 * Approach:
 * we are using merge sort to effectivly compare values and count the reverse
 * pairs
 *
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp(high - low + 1);
  int k = 0;

  while (left <= mid && right <= high) {
    if (nums[left] > nums[right]) {
      temp[k++] = nums[right++];
    } else {
      temp[k++] = nums[left++];
    }
  }

  while (left <= mid) temp[k++] = nums[left++];
  while (right <= high) temp[k++] = nums[right++];

  for (int i = 0; i < k; i++) {
    nums[low + i] = temp[i];
  }
}

int countPair(vector<int>& nums, int low, int mid, int high) {
  int count = 0;
  int right = mid + 1;

  for (int left = low; left <= mid; left++) {
    while (right <= high && nums[left] > 2LL * nums[right]) {
      right++;
    }
    count += (right - (mid + 1));
  }

  return count;
}

int sort(vector<int>& nums, int low, int high) {
  if (low >= high) return 0;

  int mid = low + (high - low) / 2;
  int count = 0;
  count += sort(nums, low, mid);
  count += sort(nums, mid + 1, high);
  count += countPair(nums, low, mid, high);
  merge(nums, low, mid, high);
  return count;
}

int reversePairs(vector<int>& nums) { return sort(nums, 0, nums.size() - 1); }

int main() {
  vector<int> nums = {2, 4, 3, 5, 1};
  cout << reversePairs(nums);
  return 0;
}