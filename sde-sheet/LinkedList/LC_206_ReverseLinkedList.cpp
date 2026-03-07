/**
 *
 * Source:    LC
 * Problem:   206. Reverse Linked List
 *
 * Link:
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * looping though the linked list while replacing next with prev to reverse it
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

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;

  while (curr != nullptr) {
    ListNode* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

int main() {
  ListNode* N5 = new ListNode(5);
  ListNode* N4 = new ListNode(4, N5);
  ListNode* N3 = new ListNode(3, N4);
  ListNode* N2 = new ListNode(2, N3);
  ListNode* N1 = new ListNode(1, N2);
  ListNode* RN1 = reverseList(N1);
  ListNode* curr = RN1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }
  return 0;
}