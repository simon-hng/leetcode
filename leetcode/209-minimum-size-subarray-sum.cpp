#include <cmath>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(const int target, const std::vector<int>& nums) {
    const int MAX_VALUE = static_cast<int>(std::pow(10, 5) + 1);
    int sum{0}, left{0}, right{0};
    int result{MAX_VALUE};

    for (; right < nums.size(); ++right) {
      sum += nums[right];
      if (sum >= target) {
        while (sum >= target) {
          result = std::min(result, right - left + 1);
          sum -= nums[left++];
        }
      }
    };

    if (result == MAX_VALUE) return 0;
    return result;
  }
};
