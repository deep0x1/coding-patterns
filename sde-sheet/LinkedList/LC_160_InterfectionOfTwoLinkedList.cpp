/**
 *
 * Source:    LC
 * Problem:   160. Intersection of Two Linked Lists
 *
 *
 * Link:
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 *
 * Time: O(M+N)
 * Space: O(1)
 *
 *
 * Approach:
 * loop untill we find currA equals to currB, we are using track swap technique
 * to make sure both runners meet at some point, if they meet at nullptr that
 * means there is no merge and if they meeat at some node that node is our
 * answer
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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  if (!headA || !headB) return nullptr;

  ListNode* currA = headA;
  ListNode* currB = headB;

  while (currA != currB) {
    if (!currA) {
      currA = headB;
    } else {
      currA = currA->next;
    }

    if (!currB) {
      currB = headA;
    } else {
      currB = currB->next;
    }
  }

  return currA;
}

int main() {
  vector<int> common = {8, 4, 5};
  vector<int> num1 = {4, 1};
  vector<int> num2 = {5, 6, 1};
  ListNode* C1 = new ListNode(0);
  ListNode* N1 = new ListNode(0);
  ListNode* N2 = new ListNode(0);
  ListNode* curr = nullptr;

  curr = C1;
  for (auto n : common) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  C1 = C1->next;

  curr = N1;
  for (auto n : num1) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  curr->next = C1;
  N1 = N1->next;

  curr = N2;
  for (auto n : num2) {
    ListNode* temp = new ListNode(n);
    curr->next = temp;
    curr = curr->next;
  }
  curr->next = C1;
  N2 = N2->next;

  ListNode* R1 = getIntersectionNode(N1, N2);

  curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}