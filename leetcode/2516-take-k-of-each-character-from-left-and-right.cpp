#include <array>
#include <string>

class Solution {
 public:
  int takeCharacters(const std::string s, const int k) {
    if (k == 0) return 0;
    if (s.size() < 3 * k) return -1;

    std::array<int, 3> rightFreq{0};
    for (const char& c : s) ++rightFreq[c - 'a'];
    for (const auto& c : {'a', 'b', 'c'})
      if (rightFreq[c - 'a'] < k) return -1;

    std::array<int, 3> leftFreq{0};
    int result{static_cast<int>(s.size())};
    for (int left{0}, right{0}; left < s.size(); ++left) {
      while (right < s.size() &&
             (left > right ||
              (leftFreq[s[right] - 'a'] + rightFreq[s[right] - 'a']) > k)) {
        --rightFreq[s[right] - 'a'];

        ++right;
        result = std::min(result, left + static_cast<int>(s.size()) - right);
      }

      ++leftFreq[s[left] - 'a'];
    }

    return result;
  }
};
