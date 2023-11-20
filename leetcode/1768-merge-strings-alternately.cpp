#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::string mergeAlternately(std::string word1, std::string word2) {
    std::stringstream result;

    int i = 0;
    for (; i < std::min(word1.length(), word2.length()); ++i) {
      result << word1[i] << word2[i];
    }

    std::string rest = (word1.length() > word2.length()) ? word1 : word2;

    for (; i < rest.length(); ++i) {
      result << rest[i];
    }

    return result.str();
  }
};
