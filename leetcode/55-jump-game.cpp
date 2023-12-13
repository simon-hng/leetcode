#include "../include/bits/stdc++.h"

class Solution {
 public:
  bool canJump(const std::vector<int>& nums) {
    int pos = nums.size() - 1;
    for (auto i = pos - 1; i >= 0; --i) {
      if (nums[i] >= (pos - i)) {
        pos = i;
      }
    }

    return pos == 0;
  }
};
