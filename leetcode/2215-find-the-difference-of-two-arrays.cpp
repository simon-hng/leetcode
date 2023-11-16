#include <algorithm>
#include <iterator>

#include "../include/bits/stdc++.h"

class Solution {
 public:
  std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
                                               std::vector<int>& nums2) {
    std::set<int> set1{nums1.begin(), nums1.end()};
    std::set<int> set2{nums2.begin(), nums2.end()};

    std::set<int> answer1{}, answer2{};

    for (int num : nums1) {
      if (!set2.contains(num)) {
        answer1.insert(num);
      }
    }

    for (int num : nums2) {
      if (!set1.contains(num)) {
        answer2.insert(num);
      }
    }

    return std::vector{std::vector<int>{answer1.begin(), answer1.end()},
                       std::vector<int>{answer2.begin(), answer2.end()}};
  }
};

class SolutionCool {
 public:
  std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
                                               std::vector<int>& nums2) {
    std::vector<int> answer1, answer2;
    std::set<int> s1{nums1.begin(), nums1.end()},
        s2{nums2.begin(), nums2.end()};
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::back_inserter(answer1));
    std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
                        std::back_inserter(answer1));
    return {answer1, answer2};
  }
};

int main() {
  Solution solution;
  std::vector<int> nums1 = {1, 2, 3, 3};
  std::vector<int> nums2 = {1, 1, 2, 2};
  std::vector<std::vector<int>> result = solution.findDifference(nums1, nums2);

  // Print the result
  for (const auto& vec : result) {
    for (int num : vec) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
