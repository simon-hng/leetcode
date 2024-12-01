#include "../include/bits/stdc++.h"

class Solution {
 public:
  void rotate(std::vector<int>& nums, const int k) {
    std::rotate(nums.rbegin(), nums.rbegin() + (k % nums.size()), nums.rend());
  }
};
