#include <climits>;
#include <iostream>;
#include <string>;

class Solution {
 public:
  int myAtoi(std::string s) {
    size_t i = 0;
    while (s[i] == ' ') {
      s[i]++;
    }
    bool isNegative;
    if (s[i] == '+' || s[i] == '-') {
      isNegative = s[i] == '-';
      i++;
    }

    int result = 0;
    auto asd = s.length();
    while (i < s.length() - 1 && s[i] >= '0' && s[i] <= '9') {
      int digit = s[i] - '0';
      if (result > INT_MAX / 10 || result < INT_MAX / 10 && digit > 7) {
        return isNegative ? INT_MIN : INT_MAX;
      };
      result *= 10;
      result += digit;
      i++;
    }
  }
};

int main() {
  Solution solution;
  std::cout << solution.myAtoi("1234") << std::endl;
}