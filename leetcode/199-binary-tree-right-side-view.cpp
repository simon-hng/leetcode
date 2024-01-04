#include "../include/bits/stdc++.h"

// Definition for a binary tree node.
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
  std::vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) return {};

    std::vector<int> result{};
    std::vector<TreeNode *> level_nodes{root};

    while (!level_nodes.empty()) {
      result.push_back(level_nodes.back()->val);
      std::vector<TreeNode *> next_level_nodes{};

      for (auto node : level_nodes) {
        if (node->left != nullptr) next_level_nodes.push_back(node->left);
        if (node->right != nullptr) next_level_nodes.push_back(node->right);
      }
      level_nodes = next_level_nodes;
    };

    return result;
  }
};
