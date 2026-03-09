/**
 *
 * Source:    LC
 * Problem:   25. Reverse Nodes in k-Group
 *
 *
 * Link:
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * finding K+1th element as end and reversing all the nodes using two pointer
 * technique
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

ListNode* reverse(ListNode* head, int k) {
  if (!head) return nullptr;

  ListNode* start = head;
  ListNode* end = nullptr;
  ListNode* curr = start;
  ListNode* prev = nullptr;

  // finding end
  int temp = k;
  while (curr && temp) {
    curr = curr->next;
    temp--;
  }
  if (temp) return head;  // no k elements left
  end = curr;

  // reverse nodes
  temp = k;
  curr = start;
  prev = end;
  while (temp--) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  start = prev;

  return start;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode dummy(0);
  dummy.next = head;
  ListNode* prev = &dummy;
  ListNode* curr = dummy.next;

  while (curr) {
    int temp = k;
    curr = reverse(curr, k);
    prev->next = curr;

    while (curr && temp) {
      prev = curr;
      curr = curr->next;
      temp--;
    }
  }

  return dummy.next;
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

  N1 = reverseKGroup(N1, 2);

  curr = N1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}