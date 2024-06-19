#include "../include/bits/stdc++.h"

class Solution {
 public:
  bool areOccurrencesEqual(const std::string s) {
    std::vector<int> char_to_count(26, 0);

    for (auto &c : s) {
      char_to_count[c - 'a']++;
    }

    int value = char_to_count[s[0] - 'a'];
    for (auto &i : char_to_count) {
      if (i != value && i != 0) {
        return false;
      }
    }

    return true;
  }
};
