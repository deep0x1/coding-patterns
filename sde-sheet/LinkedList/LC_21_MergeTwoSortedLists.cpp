/**
 *
 * Source:    LC
 * Problem:   21. Merge Two Sorted Lists
 *
 * Link:
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 *
 * Time: O(N + M)
 * Space: O(1)
 *
 *
 * Approach:
 * creating a dummy head then looping and comparing both list to decide ->next
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* head = new ListNode(0);
  ListNode* curr = head;

  while (list1 && list2) {
    if (list1->val > list2->val) {
      curr->next = list2;
      curr = list2;
      list2 = list2->next;
    } else {
      curr->next = list1;
      curr = list1;
      list1 = list1->next;
    }
  }

  if (list1) curr->next = list1;
  if (list2) curr->next = list2;

  return head->next;
}

int main() {
  ListNode* N16 = new ListNode(12);
  ListNode* N15 = new ListNode(11, N16);
  ListNode* N14 = new ListNode(9, N15);
  ListNode* N13 = new ListNode(5, N14);
  ListNode* N12 = new ListNode(3, N13);
  ListNode* N11 = new ListNode(1, N12);

  ListNode* N26 = new ListNode(16);
  ListNode* N25 = new ListNode(10, N26);
  ListNode* N24 = new ListNode(8, N25);
  ListNode* N23 = new ListNode(7, N24);
  ListNode* N22 = new ListNode(4, N23);
  ListNode* N21 = new ListNode(2, N22);

  ListNode* R1 = mergeTwoLists(N11, N21);
  ListNode* curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}