#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimizedMaximum(int n, const std::vector<int>& quantities) {
    const auto calcServed = [&quantities](int x) {
      auto served{0};
      for (const auto& quantity : quantities) {
        auto currentServing = quantity / x;
        if (quantity % x != 0) {
          ++currentServing;
        }
        served += currentServing;
      }

      return served;
    };

    int low = 1, high = *std::max_element(quantities.begin(), quantities.end());
    while (low <= high) {
      auto mid = (low + high) / 2;
      if (calcServed(mid) <= n) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
