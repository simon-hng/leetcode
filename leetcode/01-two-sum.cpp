#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> valToIndex = {};

    for (int i = 0; i < nums.size(); ++i) {
      if (auto j = valToIndex.find(target - nums[i]); j != valToIndex.end()) {
        return {j->second, i};
      }
      valToIndex.insert({nums[i], i});
    }
    return {};
  }
};

int main() {}
