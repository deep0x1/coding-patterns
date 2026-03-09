/**
 *
 * Source:    LC
 * Problem:   61. Rotate List
 *
 *
 * Link:
 * https://leetcode.com/problems/rotate-list/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * connecting tail to the head to create a cycle and then looping size - k times
 * to find new tail and head
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

ListNode* rotateRight(ListNode* head, int k) {
  if (!head || !head->next || k == 0) return head;

  ListNode* tail = head;
  int size = 1;

  // find size and tail
  while (tail->next) {
    size++;
    tail = tail->next;
  }

  // re-calculate k
  k = k % size;
  if (k == 0) return head;

  // create cycle
  tail->next = head;

  // find new tail
  ListNode* newTail = head;
  for (int i = 1; i < size - k; i++) {
    newTail = newTail->next;
  }

  // find new head
  ListNode* newHead = newTail->next;
  newTail->next = nullptr;

  return newHead;
}

int main() {
  vector<int> num1 = {1, 2, 3, 4, 5};
  ListNode* N1 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  ListNode* R1 = rotateRight(N1, 1);
  curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}