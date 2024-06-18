#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_to_index{};
    for (auto i{0}; i < nums.size(); ++i) {
      if (num_to_index.contains(target - nums[i])) {
        return {i, num_to_index[target - nums[i]]};
      }
      num_to_index.insert({nums[i], i});
    }

    return {};
  }
};
