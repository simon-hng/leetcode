#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool containsNearbyDuplicate(const std::vector<int>& nums, const int k) {
    std::unordered_map<int, int> num_to_index;
    for (int i{0}; i < nums.size(); ++i) {
      if (num_to_index.contains(nums[i]) && i - num_to_index.at(nums[i]) <= k)
        return true;

      num_to_index[nums[i]] = i;
    }

    return false;
  }
};
