#include <vector>
class Solution {
 public:
  int climbStairs(const int n) {
    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[0] = 0;
    for (auto i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }
};
