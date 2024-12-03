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
  void inOrderTraversal(const TreeNode *root, std::vector<int> &result) {
    if (!root) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->val);
    inOrderTraversal(root->right, result);
  }

  int getMinimumDifference(const TreeNode *root) {
    std::vector<int> values{};
    inOrderTraversal(root, values);

    int result{INT_MAX};
    for (int i{0}; i < values.size() - 1; ++i)
      result = std::min(values[i + 1] - values[i], result);

    return result;
  }
};
