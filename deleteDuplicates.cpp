#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *after) : val(x), next(after) {}
};

class Solution {
public:
  bool compare_curr_and_next(ListNode *curr_ln, ListNode *next_ln) {
    //
    if (curr_ln->val == next_ln->val) {
      return true;
    } else {
      return false;
    }
  }

  void sever_and_connect(ListNode *curr_ln) {
    ListNode *to_be_deleted = curr_ln->next;
    curr_ln->next = curr_ln->next->next;
    delete (to_be_deleted);
  }

  /*
  Input: 1->1->2
  Output: 1->2

  Input: 1->1->2->3->3
  Output: 1->2->3
  */
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr && curr->next != nullptr) {
      if (curr->val == curr->next->val) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
  void println(ListNode *ln) {
    while (ln != nullptr) {
      cout << ln->val;
      if (ln->next != nullptr) {
        cout << "->";
      }
      ln = ln->next;
    }
    cout << endl;
  }
};

int main() {
  //
  Solution s;
  ListNode *ln = new ListNode(1, new ListNode(1, new ListNode(2, nullptr)));
  s.println(ln);
  ListNode *after = s.deleteDuplicates(ln);
  s.println(after);
  ln = new ListNode(
      1, new ListNode(
             1, new ListNode(2, new ListNode(3, new ListNode(3, nullptr)))));
  cout << "1 1 2 3 3" << endl;
  after = s.deleteDuplicates(ln);
  cout << "1 1" << endl;
  ln = new ListNode(1, new ListNode(1, nullptr));
  after = s.deleteDuplicates(ln);
  s.println(after);
}
