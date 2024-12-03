#include "../include/bits/stdc++.h"

class Solution {
 public:
  int compress(std::vector<char>& chars) {
    auto j{0};
    for (auto i{0}; i < chars.size(); ++i) {
      int count{1};
      for (; i < chars.size() - 1 && chars[i] == chars[i + 1]; ++i) {
        ++count;
      }
      chars[j++] = chars[i];

      if (count > 1) {
        for (auto count_char : std::to_string(count)) {
          chars[j++] = count_char;
        }
      }
    }

    return j;
  };
};
