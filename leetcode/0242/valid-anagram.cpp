#include <string>

class Solution {
 public:
  bool isAnagram(const std::string s, const std::string t) {
    std::unordered_map<char, int> char_to_count;

    for (auto c : s) char_to_count[c]++;
    for (auto c : t) {
      if (!char_to_count[c]) return false;
      char_to_count[c]--;
      if (char_to_count[c] == 0) char_to_count.erase(c);
    }

    return char_to_count.empty();
  }
};
