#include "../include/bits/stdc++.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  constexpr int goodNodes(const TreeNode *root) {
    // Due to constraints lowest number is -10^4
    return goodNodes(root, -10000);
  }

  constexpr int goodNodes(const TreeNode *root, const int biggest) {
    if (!root) return 0;

    bool this_good = root->val >= biggest;
    int next_biggest = this_good ? root->val : biggest;

    return goodNodes(root->left, next_biggest) +
           goodNodes(root->right, next_biggest) + this_good;
  }
};
