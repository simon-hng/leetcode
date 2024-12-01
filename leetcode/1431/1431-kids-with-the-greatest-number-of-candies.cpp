#include <algorithm>

#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<bool> kidsWithCandies(std::vector<int>& candies,
                                    int extraCandies) {
    int max = *std::max_element(candies.begin(), candies.end());

    std::vector<bool> result{};

    for (auto& candy : candies) {
      result.push_back(candy + extraCandies >= max);
    }

    return result;
  }
};

int main() {}
