#include "../include/bits/stdc++.h"

class Solution {
 public:
  int largestAltitude(std::vector<int>& gain) {
    int result{0};
    int current_altitude = 0;

    for (auto current_gain : gain) {
      result = std::max(result, current_altitude += current_gain);
    }

    return result;
  }
};
