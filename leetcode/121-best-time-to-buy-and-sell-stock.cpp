#include "../include/bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cheapest_stock = *std::max_element(prices.begin(), prices.end());
    int result = 0;

    for (int price : prices) {
      cheapest_stock = std::min(cheapest_stock, price);
      result = std::max(price - cheapest_stock, result);
    }

    return result;
  }
};
