#include <vector>

class Solution {
 public:
  constexpr int findPeakElement(const std::vector<int>& nums) {
    auto max = std::max_element(nums.begin(), nums.end());
    return std::distance(nums.begin(), max);
  }
};
