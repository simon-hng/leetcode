#include <optional>

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
  std::optional<int> traverse(TreeNode *root, int &k) {
    if (!root) return std::nullopt;
    if (auto result = traverse(root->left, k)) return result.value();
    if (!--k) return root->val;
    if (auto result = traverse(root->right, k)) return result.value();
    return std::nullopt;
  }

  int kthSmallest(TreeNode *root, int k) {
    return traverse(root, k).value_or(0);
  }
};
