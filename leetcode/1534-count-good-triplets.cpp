#include <vector>

class Solution {
 public:
  constexpr int countGoodTriplets(const std::vector<int>& arr, const int a,
                                  const int b, const int c) {
    auto result{0};

    for (auto i{0}; i < arr.size(); ++i) {
      for (auto j{i + 1}; j < arr.size(); ++j) {
        for (auto k{j + 1}; k < arr.size(); ++k) {
          if (std::abs(arr[i] - arr[j]) <= a &&
              std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c)
            ++result;
        }
      }
    }

    return result;
  }
};
