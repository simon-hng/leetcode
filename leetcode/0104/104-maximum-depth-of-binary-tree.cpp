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
  constexpr int maxDepth(const TreeNode *root) {
    if (root == nullptr) return 0;
    auto leftValue = maxDepth(root->left) + 1;
    auto rightValue = maxDepth(root->right) + 1;
    return std::max(leftValue, rightValue);
  }
};
