/**
 *
 * Source:    LC
 * Problem:   19. Remove Nth Node From End of List

 *
 * Link:
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using two pointers to create a gap and then moving both at same time, once
 our fast pointer reach the end our slow will be exactly target steps behind
 which we can edit to delete the node
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy(0);
  dummy.next = head;
  ListNode* slow = &dummy;
  ListNode* fast = &dummy;

  for (int i = 0; i <= n; i++) {
    fast = fast->next;
  }

  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }

  ListNode* nodeToDelete = slow->next;
  slow->next = slow->next->next;
  delete nodeToDelete;

  return dummy.next;
}

int main() {
  ListNode* N15 = new ListNode(5);
  ListNode* N14 = new ListNode(4, N15);
  ListNode* N13 = new ListNode(3, N14);
  ListNode* N12 = new ListNode(2, N13);
  ListNode* N11 = new ListNode(1, N12);
  int target = 2;

  ListNode* R1 = removeNthFromEnd(N11, target);
  ListNode* curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}