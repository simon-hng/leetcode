#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int all_product = 1;
    for (auto num : nums) all_product *= num;

    std::vector<int> result{};
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        result.push_back(all_product / nums[i]);
      } else {
        int product = 1;
        for (int j = 0; j < nums.size(); ++j)
          if (i != j) product *= nums[j];

        result.push_back(product);
      }
    }
    return result;
  }
};
