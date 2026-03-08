/**
 *
 * Source:    LC
 * Problem:   237. Delete Node in a Linked List
 *
 *
 * Link:
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *
 *
 * Time: O(1)
 * Space: O(1)
 *
 *
 * Approach:
 * in order to delete a node when we don't know the previous node, and all nodes
 * are unique, we can impersonate the next node and delete the next node, this
 * way next node takes place of target node and it gets remove effecitvly
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

void deleteNode(ListNode* node) {
  ListNode* nextNode = node->next;
  node->val = nextNode->val;
  node->next = nextNode->next;
  delete nextNode;
}

int main() {
  vector<int> num1 = {4, 5, 1, 9};
  ListNode* N1 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  ListNode* node = nullptr;
  curr = N1;
  while (curr) {
    if (curr->val == 5) {
      node = curr;
      break;
    }
    curr = curr->next;
  }
  deleteNode(node);

  curr = N1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}