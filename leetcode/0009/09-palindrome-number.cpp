#include <cmath>
#include <iostream>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    auto length = (ceil(log10(static_cast<long>(x) + 1)));
    if (length < 2) {
      return true;
    }
    if (length == 2.0) {
      return x % 10 == x / 10 % 10;
    }

    for (size_t i = 0; i <= std::ceil(length / 2); ++i) {
      auto right = static_cast<int>(x / std::pow(10, i)) % 10;
      auto left = static_cast<int>(x / std::pow(10, length - i - 1)) % 10;

      if (left != right) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution solution;
  int input1 = 2147483647;
  bool result1 = solution.isPalindrome(input1);
  std::cout << "Input: " << input1 << ", is palindrome:" << result1
            << std::endl;
}
