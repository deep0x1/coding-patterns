/**
 *
 * Source:    LeetCode
 * Problem:   493. Reverse Pairs
 * Link:      https://leetcode.com/problems/reverse-pairs/description/
 *
 *
 * Approach 1:
 * using maths S (sum of all num) and S2 (sum of all num squared);
 *
 */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
  vector<int> temp;
  int l = low;
  int r = mid + 1;

  while (l <= mid && r <= high) {
    if (nums[l] <= nums[r]) {
      temp.push_back(nums[l++]);
    } else {
      temp.push_back(nums[r++]);
    }
  }

  while (l <= mid) temp.push_back(nums[l++]);
  while (r <= high) temp.push_back(nums[r++]);

  for (int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }
}

int count_pairs(vector<int>& nums, int low, int mid, int high) {
  int r = mid + 1;
  int count = 0;
  for (int i = low; i <= mid; i++) {
    while (r <= high && nums[i] > 2 * (long long)nums[r]) {
      r++;
    }
    count += (r - (mid + 1));
  }
  return count;
}

int merge_sort(vector<int>& nums, int low, int high) {
  if (low >= high) return 0;
  int mid = (high + low) / 2;
  int pairs = 0;
  pairs += merge_sort(nums, low, mid);
  pairs += merge_sort(nums, mid + 1, high);
  pairs += count_pairs(nums, low, mid, high);
  merge(nums, low, mid, high);
  return pairs;
}

int reversePairs(vector<int>& nums) {
  int n = nums.size() - 1;
  int pairs = merge_sort(nums, 0, n);
  return pairs;
}

int main() {
  vector<int> arr = {1, 3, 2, 3, 1};
  int ans = reversePairs(arr);
  cout << ans;
  return 0;
}