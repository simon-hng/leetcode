#include <cmath>
#include <iostream>

class Solution {
 public:
  std::string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }

    int numDigits = std::log10(n + 1);
    for (int i = 0; i < numDigits; i++) {
      int digit = n / (numDigits - i);
    };

    return "0";
  }
};

int main() {}
