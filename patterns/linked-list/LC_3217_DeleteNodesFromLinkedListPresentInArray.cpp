/**
 *
 * Source:    LeetCode
 * Problem:   3217. Delete Nodes From Linked List Present in Array
 * Array Link:
 * https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
 *
 *
 * Approach 1:
 * using unoredred set and linkedlist
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
  unordered_set<int> to_del(nums.begin(), nums.end());

  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* prev = dummy;
  ListNode* curr = head;

  while (curr != nullptr) {
    if (to_del.count(curr->val)) {
      prev->next = curr->next;
    } else {
      prev = curr;
    }
    curr = curr->next;
  }

  ListNode* new_head = dummy->next;
  delete dummy;
  return new_head;
}

int main() {
  vector<int> nums = {1};

  ListNode* n6 = new ListNode(2);
  ListNode* n5 = new ListNode(1, n6);
  ListNode* n4 = new ListNode(2, n5);
  ListNode* n3 = new ListNode(1, n4);
  ListNode* n2 = new ListNode(2, n3);
  ListNode* n1 = new ListNode(1, n2);

  ListNode* ans = modifiedList(nums, n1);
  while (ans != nullptr) {
    cout << ans->val << " -> ";
    ans = ans->next;
  }
  return 0;
}