#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
 public:
  /*
  Merge two sorted linked lists and return it as a new list. The new list should
  be made by splicing together the nodes of the first two lists.

  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
  1 - 2 - 4 - 1 - 3 - 4
  1 - 1 - 4 - 2 - 3 - 4
  1 - 1 - 2 - 4 - 3 - 4
  1 - 1 - 2 - 3 - 4 - 4
  */

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    ListNode *final_ln = l1;
    ListNode *final_ln_tail = final_ln;
    while (final_ln_tail->next != nullptr) {
      final_ln_tail = final_ln_tail->next;
    }
    final_ln_tail->next = l2;
    ListNode *curr = final_ln, *prev = nullptr;
    while (curr != nullptr) {
      ListNode *swapping_point = curr->next;
      while (swapping_point != nullptr) {
        if (swapping_point->val < curr->val) {
          int curr_val_copy = curr->val;
          curr->val = swapping_point->val;
          swapping_point->val = curr_val_copy;
        }
        swapping_point = swapping_point->next;
      }
      curr = curr->next;
    }
    return final_ln;
  }
  void printList(ListNode *l) {
    bool first = true;
    while (l != nullptr) {
      if (!first) {
        cout << "->";
      }
      cout << l->val;
      first = false;
      l = l->next;
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
  ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
  s.printList(s.mergeTwoLists(l1, l2));
  //
}
