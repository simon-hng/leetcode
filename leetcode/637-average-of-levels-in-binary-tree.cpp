#include <vector>

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
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<TreeNode *> level_nodes{root};
    std::vector<double> result{};

    while (!level_nodes.empty()) {
      double level_sum{0};
      std::vector<TreeNode *> next_level_nodes{};

      for (auto node : level_nodes) {
        level_sum += node->val;

        if (node->left != nullptr) next_level_nodes.push_back(node->left);
        if (node->right != nullptr) next_level_nodes.push_back(node->right);
      };

      result.push_back(level_sum / static_cast<double>(level_nodes.size()));
      level_nodes = next_level_nodes;
    };

    return result;
  }
};
