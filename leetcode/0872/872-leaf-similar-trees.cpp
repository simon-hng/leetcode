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
  bool leafSimilar(const TreeNode *root1, const TreeNode *root2) {
    std::vector<int> leftLeafValues;
    std::vector<int> rightLeafValues;

    getLeafValues(root1, leftLeafValues);
    getLeafValues(root2, rightLeafValues);

    return leftLeafValues == rightLeafValues;
  }

  void getLeafValues(const TreeNode *root, std::vector<int> &result) {
    if (!root) return;

    if (!root->left && !root->right) {
      result.push_back(root->val);
    }

    getLeafValues(root->left, result);
    getLeafValues(root->right, result);
  }
};
