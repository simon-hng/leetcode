#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
    std::vector<std::string> result;

    size_t start = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if ((i == nums.size() - 1) || !(nums[i + 1] == nums[i] + 1)) {
        result.push_back(std::to_string(nums[start]) +
                         (start == i ? "" : "->" + std::to_string(nums[i])));
        start = i + 1;
      }
    }

    return result;
  }
};
