#include <vector>

class Solution {
 public:
  int countPairs(std::vector<int>& nums, const int target) {
    std::sort(nums.begin(), nums.end());
    int result{0};
    int right = nums.size() - 1;

    for (auto i{0}; i < nums.size(); ++i) {
      right = std::max(i, right);

      while (right > i && nums[i] + nums[right] >= target) {
        --right;
      }
      result += right - i;
    }

    return result;
  }
};
