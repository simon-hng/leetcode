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
  int maxLevelSum(TreeNode *root) {
    if (root == nullptr) return 0;

    // Start with the root node
    int level = 1;
    int result_level = 1;
    int max_sum = root->val;
    std::vector<TreeNode *> level_nodes{root};

    while (!level_nodes.empty()) {
      int level_sum = 0;
      for (auto node : level_nodes) level_sum += node->val;

      if (level_sum > max_sum) {
        max_sum = level_sum;
        result_level = level;
      }

      std::vector<TreeNode *> next_level_nodes{};
      for (auto node : level_nodes) {
        if (node->left != nullptr) next_level_nodes.push_back(node->left);
        if (node->right != nullptr) next_level_nodes.push_back(node->right);
      }
      level++;
      level_nodes = next_level_nodes;
    }

    return result_level;
  }
};
