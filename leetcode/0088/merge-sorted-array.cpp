#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int> result{};

    auto i{0}, j{0};
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        result.push_back(nums1[i++]);
      } else {
        result.push_back(nums2[j++]);
      }
    }

    if (i < m) {
      std::copy(std::begin(nums1) + i, std::begin(nums1) + m,
                std::back_inserter(result));
    } else {
      std::copy(std::begin(nums2) + j, std::begin(nums2) + n,
                std::back_inserter(result));
    }

    std::copy(std::begin(result), std::end(result), std::begin(nums1));
  }
};
