/**
 *
 * Source:    LC
 * Problem:   141. Linked List Cycle
 *
 *
 * Link:
 * https://leetcode.com/problems/linked-list-cycle/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using flyod's cycle finding algorithm (tortise and hare), we run slow and
 * fast pointer from head of linked list, where slow move 1 node and fast move 2
 * node, if both of them intercets without reaching the nullptr (end) it means
 * cycle exist
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

bool hasCycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }

  return false;
}

int main() {
  vector<int> num1 = {3, 2, 0, 4};
  ListNode* N1 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  ListNode* temp = N1;
  while (temp) {
    if (temp->val == 2) {
      curr->next = temp;
      break;
    }
    temp = temp->next;
  }

  cout << hasCycle(N1);

  return 0;
}