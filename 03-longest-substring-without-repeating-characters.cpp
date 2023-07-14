#include <iostream>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.length() == 0) {
      return 0;
    }

    std::unordered_map<char, int> map;
    int max = 0;

    for (int i = 0, j = 0; i < s.length(); ++i) {
      if (map.find(s[i]) != map.end()) {
        j = std::max(j, map.find(s[i])->second + 1);
      }
      map.insert_or_assign(s[i], i);
      max = std::max(max, i - j + 1);
    }

    return max;
  }
};

int main() {
  Solution solution;
  std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
}
