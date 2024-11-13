#include <vector>

class Solution {
 public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());

    long long result{0};
    int left = nums.size() - 1, right = nums.size() - 1;

    for (auto i{0}; i < nums.size(); ++i) {
      right = std::max(right, i);
      while (right > i && nums[i] + nums[right] > upper) {
        --right;
      }

      left = std::max(left, i);
      while (left > i && nums[i] + nums[left] >= lower) {
        --left;
      }
      result += (right - left);
    }

    return result;
  }
};
