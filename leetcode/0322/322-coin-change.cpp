#include <unordered_map>
#include <vector>

/**
 * Recursion + Memoization
 */
class Solution {
 public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    if (memo.contains(amount)) return memo.at(amount);

    std::vector<int> options{};
    for (auto& coin : coins) {
      auto option = coinChange(coins, amount - coin);
      if (option >= 0) options.push_back(option + 1);
    }

    if (options.empty()) {
      memo.insert({amount, -1});
      return -1;
    };

    memo.insert({amount, *std::min_element(options.begin(), options.end())});
    return memo.at(amount);
  }

 private:
  std::unordered_map<int, int> memo;
};

/**
 * Dynamic Programming
 */

/**
class Solution {
 public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    std::vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i{1}; i <= amount; ++i) {
      std::vector<int> options{};

      for (auto& coin : coins) {
        if (i - coin >= 0 && dp[i - coin] != -1)
          options.push_back(dp[i - coin] + 1);

        if (!options.empty())
          dp[i] = *std::min_element(options.begin(), options.end());
      }
    }

    return dp[amount];
  }
};
**/
