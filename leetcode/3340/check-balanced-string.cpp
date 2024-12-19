#include <string>

class Solution {
 public:
  bool isBalanced(const std::string num) {
    auto result{0};
    for (int i{0}; i < num.size(); ++i) {
      if (i % 2 == 0) {
        result += num[i] - '0';
      } else {
        result -= num[i] - '0';
      }
    }

    return !result;
  }
};
