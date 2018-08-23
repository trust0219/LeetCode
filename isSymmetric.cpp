#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric_int_list(vector<int> &list) {
    // length of list is guaranteed to be even
    for (int i = 0; i < list.size() / 2; i++) {
      if (list[i] != list[list.size() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
  /*
  1
  2 2
  3 4 4 3
  1 2 3 4 4 3 2 1
  */
  bool isSymmetric(TreeNode *root) { return isMirror(root->left, root->right); }
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr)
      return true;
    else if (t1 == nullptr || t2 == nullptr)
      return false;
    else
      return (t1->val == t2->val) && isMirror(t1->left, t2->right) &&
             isMirror(t1->right, t2->left);
  }
};
