#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result{{1}};

    for (auto i{1}; i < numRows; ++i) {
      result.push_back({});
      for (auto j{0}; j <= i; ++j) {
        if (j == 0 || j == i) {
          result[i].push_back(1);
        } else {
          result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
    }
    return result;
  }
};
