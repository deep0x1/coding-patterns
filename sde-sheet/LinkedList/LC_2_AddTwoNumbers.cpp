/**
 *
 * Source:    LC
 * Problem:   2. Add Two Numbers
 *
 *
 * Link:
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 *
 * Time: O(N + M)
 * Space: O(1)
 *
 *
 * Approach:
 * looping though the lists while keeping track of carry, if any of list or
 * carry remains, we keep calculate the sum and add new node
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* curr = &dummy;
  int carry = 0;

  while (l1 || l2 || carry > 0) {
    int sum = carry;

    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
  }

  return dummy.next;
}

int main() {
  vector<int> num1 = {2, 4, 4};
  vector<int> num2 = {5, 6};
  ListNode* N1 = new ListNode(0);
  ListNode* N2 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  curr = N2;
  for (auto n : num2) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N2 = N2->next;

  ListNode* R1 = addTwoNumbers(N1, N2);

  curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}