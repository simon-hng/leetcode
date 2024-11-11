#include <vector>

class Solution {
 public:
  bool threeConsecutiveOdds(const std::vector<int>& arr) {
    auto consecutive{0};
    for (const auto& num : arr) {
      if (num % 2 == 0) {
        consecutive = 0;
      } else {
        consecutive++;
        if (consecutive == 3) {
          return true;
        }
      }
    }

    return false;
  }
};
