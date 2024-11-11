#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
 private:
  constexpr auto numToBits(int num) -> std::vector<int> {
    std::vector<int> result(32, 0);
    for (auto i{0}; i < result.size(); ++i) {
      result[i] = num & 1;
      num = num >> 1;
    }
    return result;
  }

  constexpr auto bitsToNum(const std::vector<int>& bits) -> int {
    int result{0};
    for (auto i{0}; i < bits.size(); ++i) {
      if (bits[i] != 0) {
        result += (1 << i);
      }
    }
    return result;
  }

 public:
  int minimumSubarrayLength(const std::vector<int>& nums, const int k) {
    std::vector<int> bitCounts(32, 0);
    int result = nums.size() + 1;
    int left{0};

    auto addBits = [&](int num, int diff) {
      auto bits = numToBits(num);
      for (int i{0}; i < bitCounts.size(); ++i) {
        if (bits[i] == 1) {
          bitCounts[i] += diff;
        }
      }
    };

    for (int right{0}; right < nums.size(); ++right) {
      addBits(nums[right], +1);
      while (left <= right && bitsToNum(bitCounts) >= k) {
        result = std::min(result, right - left + 1);
        addBits(nums[left], -1);
        ++left;
      }
    }

    return result == nums.size() + 1 ? -1 : result;
  }
};
