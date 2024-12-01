#include "../include/bits/stdc++.h"

class Solution {
 public:
  int uniquePathsWithObstacles(
      const std::vector<std::vector<int>>& obstacleGrid) {
    int m{static_cast<int>(obstacleGrid.size())},
        n{static_cast<int>(obstacleGrid.at(0).size())};
    std::vector<std::vector<uint>> dp(m, std::vector<uint>(n));

    // X marks the target
    dp[m - 1][n - 1] = 1;

    for (auto i{m - 1}; i >= 0; --i) {
      for (auto j{n - 1}; j >= 0; --j) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        };

        if (i != m - 1) dp[i][j] += dp[i + 1][j];
        if (j != n - 1) dp[i][j] += dp[i][j + 1];
      }
    }

    return dp[0][0];
  };
};
