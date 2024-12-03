#include <vector>

class Solution {
 public:
  int minSubArrayLen(const int target, const std::vector<int>& nums) {
    const int MAX_VALUE = static_cast<int>(nums.size() + 1);

    int sum{0}, left{0};
    int result{MAX_VALUE};

    for (int right{0}; right < nums.size(); ++right) {
      sum += nums[right];
      if (sum >= target) {
        while (sum >= target) {
          result = std::min(result, right - left + 1);
          sum -= nums[left++];
        }
      }
    };

    return (result == MAX_VALUE) ? 0 : result;
  }
};
