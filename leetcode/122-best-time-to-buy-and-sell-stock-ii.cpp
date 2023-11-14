#include "../include/bits/stdc++.h"

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += std::max(prices[i] - prices[i - 1], 0);
    };
    return profit;
  }
};
