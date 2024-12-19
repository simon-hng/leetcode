#include <optional>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    memo = std::vector<std::optional<int>>(nums.size(), std::nullopt);
    return rob(nums, 0);
  }

  int rob(std::vector<int>& nums, int i) {
    if (i >= nums.size()) return 0;

    if (memo[i].has_value()) {
      return memo[i].value();
    }

    int with_rob = nums[i] + rob(nums, i + 2);
    int without_rob = rob(nums, i + 1);
    memo[i] = std::optional(std::max(with_rob, without_rob));

    return memo[i].value();
  }

 private:
  std::vector<std::optional<int>> memo;
};
