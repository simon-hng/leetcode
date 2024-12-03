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
  void helper(TreeNode *root, std::vector<int> &result) {
    if (!root) return;

    result.push_back(root->val);
    helper(root->left, result);
    helper(root->right, result);
  }

  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    helper(root, result);

    return result;
  }
};
