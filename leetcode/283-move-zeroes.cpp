#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    int badge_size{0};
    for (auto i{0}; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        badge_size++;
      } else if (badge_size > 0) {
        std::swap(nums[i], nums[i - badge_size]);
      }
    }
  }
};
