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
  TreeNode *helper(const std::vector<int> &nums,
                   const std::pair<int, int> boundaries) {
    auto &[left, right] = boundaries;
    auto middle = left + ((right - left) / 2);
    if (right - left == 0) return nullptr;

    TreeNode *root = new TreeNode(nums[middle]);
    root->left = helper(nums, {left, middle});
    root->right = helper(nums, {middle + 1, right});

    return root;
  }

  TreeNode *sortedArrayToBST(const std::vector<int> &nums) {
    return helper(nums, {0, nums.size()});
  }
};
