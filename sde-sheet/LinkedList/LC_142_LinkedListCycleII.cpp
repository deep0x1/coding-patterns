/**
 *
 * Source:    LC
 * Problem:   142. Linked List Cycle II
 *
 *
 * Link:
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * applying flyod's cycle finding algorithm (tortise and hare)
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

ListNode* detectCycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  bool hasCycle = false;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      hasCycle = true;
      break;
    }
  }

  // edge case + no cycle
  if (!hasCycle) return nullptr;

  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}

int main() {
  vector<int> num1 = {3, 2, 0, -4};
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

  ListNode* R1 = detectCycle(N1);
  if (R1)
    cout << R1->val;
  else
    cout << "No Cycle";

  return 0;
}