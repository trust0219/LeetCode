#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int max(int a, int b) {
    if (a > b)
      return a;
    else
      return b;
  }
  int maxDepth(TreeNode *root) {
    if (root != nullptr) {
      return 1 + max(maxDepth(root->left), maxDepth(root->right));
    } else {
      return 0;
    }
    //
  }
};
