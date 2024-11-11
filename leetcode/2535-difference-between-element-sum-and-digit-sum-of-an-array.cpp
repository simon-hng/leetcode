#include <vector>

class Solution {
 public:
  int differenceOfSum(const std::vector<int>& nums) {
    auto sum{0};
    auto digitSum{0};

    for (auto num : nums) {
      sum += num;

      while (num > 0) {
        auto digit = num % 10;
        digitSum += digit;
        num /= 10;
      }
    }

    return std::abs(sum - digitSum);
  }
};
