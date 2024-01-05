#include <vector>

class Solution {
 public:
  double findMaxAverage(std::vector<int>& nums, int k) {
    int current_sum{0};
    for (int i = 0; i < k; ++i) current_sum += nums[i];

    int result{current_sum};
    for (int i = 1; i < nums.size() - k + 1; ++i) {
      current_sum = current_sum - nums[i - 1] + nums[i + k - 1];
      result = std::max(result, current_sum);
    }

    return result / static_cast<double>(k);
  }
};
