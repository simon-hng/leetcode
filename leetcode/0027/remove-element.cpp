#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    auto removed{0};

    for (auto i{0}; i < nums.size(); ++i) {
      if (nums[i] == val) {
        ++removed;
      } else {
        nums[i - removed] = nums[i];
      }
    }

    return nums.size() - removed;
  }
};
