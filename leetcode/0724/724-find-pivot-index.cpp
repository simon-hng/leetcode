#include "../include/bits/stdc++.h"

class Solution {
 public:
  int pivotIndex(const std::vector<int>& nums) {
    auto sum = std::reduce(nums.begin(), nums.end());
    auto left_sum{0};

    for (auto i{0}; i < nums.size(); ++i) {
      if (sum - nums[i] - left_sum == left_sum) {
        return i;
      }

      left_sum += nums[i];
    }

    return -1;
  }
};
