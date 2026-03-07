/**
 *
 * Source:    LC
 * Problem:   876. Middle of the Linked List
 *
 * Link:
 * https://leetcode.com/problems/middle-of-the-linked-list/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using fast runner and slow runner approach, where our fast runner moves 2
 * points and slow runner moves 1 at a time, once our fast runner reach the end
 * our slow runner would have travelled half distance only
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

ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main() {
  ListNode* N6 = new ListNode(6);
  ListNode* N5 = new ListNode(5, N6);
  ListNode* N4 = new ListNode(4, N5);
  ListNode* N3 = new ListNode(3, N4);
  ListNode* N2 = new ListNode(2, N3);
  ListNode* N1 = new ListNode(1, N2);
  ListNode* RN1 = middleNode(N1);
  ListNode* curr = RN1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }
  return 0;
}