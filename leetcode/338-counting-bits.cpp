#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<int> countBits(const int n) {
    std::vector<int> result(n + 1);

    for (int i{1}; i <= n; ++i) {
      result[i] = result[i / 2] + i % 2;
    }

    return result;
  }
};
