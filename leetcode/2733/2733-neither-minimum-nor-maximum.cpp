#include <vector>

class Solution {
 public:
  int findNonMinOrMax(std::vector<int>& nums) {
    int max = nums[0], min = nums[0];

    for (auto num : nums) {
      max = std::max(max, num);
      min = std::min(min, num);
    }

    for (auto num : nums) {
      if (num != max && num != min) return num;
    }

    return -1;
  }
};
