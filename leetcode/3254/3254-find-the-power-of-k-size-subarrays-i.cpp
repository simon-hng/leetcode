#include <vector>

class Solution {
 public:
  std::vector<int> resultsArray(const std::vector<int>& nums, int k) {
    std::vector<int> result{};
    int consecutive{0};
    int prev{nums[0] - 1};

    auto const update = [&](int num) {
      if (prev == num - 1) {
        ++consecutive;
      } else {
        consecutive = 1;
      }
      prev = num;
    };

    for (auto i{0}; i < k - 1; ++i) {
      update(nums[i]);
    }

    for (auto i{k - 1}; i < nums.size(); ++i) {
      update(nums[i]);
      result.push_back(consecutive >= k ? nums[i] : -1);
    };

    return result;
  }
};
