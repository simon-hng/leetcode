#include <unordered_map>
#include <vector>

class Solution {
 public:
  long long maximumSubarraySum(std::vector<int>& nums, int k) {
    long long result{0};
    long long sum{0};
    int distinct = 0;
    std::unordered_map<int, int> count;

    for (auto i{0}; i < nums.size(); ++i) {
      sum += nums[i];

      if (++count[nums[i]] == 1) {
        ++distinct;
      }

      if (i >= k) {
        if (--count[nums[i - k]] == 0) --distinct;
        sum -= nums[i - k];
      }

      if (i >= k - 1 && distinct == k) result = std::max(result, sum);
    }

    return result;
  }
};
