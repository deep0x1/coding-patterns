/**
 *
 * Source:    LC
 * Problem:   138. Copy List with Random Pointer
 *
 *
 * Link:
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * itterate though the linked list and make copy of it while creating a relation
 * map between old and new nodes, itterte over both linked list and map the
 * random values in new linked list
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node* copyRandomList(Node* head) {
  unordered_map<Node*, Node*> relationMap;
  Node dummy(0);
  Node* curr1 = head;
  Node* curr2 = &dummy;

  // list layer copy
  while (curr1) {
    Node* temp = new Node(curr1->val);
    relationMap[curr1] = temp;
    curr2->next = temp;

    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  // random layer copy
  curr1 = head;
  curr2 = dummy.next;
  while (curr1) {
    Node* random = nullptr;
    if (curr1->random) {
      random = relationMap[curr1->random];
    }
    curr2->random = random;

    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return dummy.next;
}

int main() {
  vector<int> num1 = {1, 2, 3, 4, 5};
  Node* N1 = new Node(0);
  Node* curr = nullptr;

  curr = N1;
  for (auto n : num1) {
    Node* temp = new Node(n);
    curr->next = temp;
    curr = curr->next;
  }
  N1 = N1->next;

  Node* R1 = copyRandomList(N1);
  curr = R1;
  while (curr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }

  return 0;
}