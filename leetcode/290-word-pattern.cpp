#include <unordered_map>

#include "../include/bits/stdc++.h"

class Solution {
 public:
  bool wordPattern(const std::string pattern, const std::string s) {
    std::stringstream ss{s};
    std::vector<std::string> words;

    std::string tmp;
    while (getline(ss, tmp, ' ')) words.push_back(tmp);

    if (words.size() != pattern.size()) return false;

    std::unordered_map<std::string, int> word_to_i{};
    std::unordered_map<char, int> char_to_i{};

    for (auto i = 0; i < words.size(); ++i) {
      if (word_to_i[words[i]] != char_to_i[pattern[i]]) {
        return false;
      }
      word_to_i[words[i]] = char_to_i[pattern[i]] = i + 1;
    }

    return true;
  };
};

int main() {
  std::string pattern{"aaaa"};
  std::string s{"aa aa aa ab"};

  Solution sol{};
  auto res = sol.wordPattern(pattern, s);
  std::cout << res << '\n';
  return 0;
}
