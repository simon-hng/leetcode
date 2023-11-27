#include <vector>

#include "../include/bits/stdc++.h"
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    std::istringstream iss{s};
    std::vector<string> words;

    while (std::getline(iss, s, ' ')) {
      if (s.empty()) continue;
      words.push_back(s);
    }

    return std::accumulate(words.rbegin(), words.rend(), std::string(""),
                           [](const std::string& a, const std::string& b) {
                             return a.empty() ? b : a + ' ' + b;
                           });
  }
};
