/**
 *
 * Source:    LC
 * Problem:   234. Palindrome Linked List
 *
 *
 * Link:
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using slow and fast pointer to find mid of linked list and then reversing the
 * second half of the list, once reversed we compare both halfs to check
 * palindrome
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

bool isPalindrome(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  int count = 0;

  // finding mid
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    count++;
  }

  // reverse second half
  ListNode* prev = nullptr;
  ListNode* curr = slow;
  while (curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // compare both halfs
  ListNode* left = head;
  ListNode* right = prev;

  while (right) {
    if (left->val != right->val) return false;
    left = left->next;
    right = right->next;
  }

  return true;
}

int main() {
  vector<int> num1 = {1, 2, 3, 2, 1};
  ListNode* N1 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  cout << isPalindrome(N1);

  return 0;
}