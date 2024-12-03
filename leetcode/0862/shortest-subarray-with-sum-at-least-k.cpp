#include <deque>
#include <vector>

class Solution {
 public:
  int shortestSubarray(const std::vector<int>& nums, const int k) {
    const int MAX_VALUE = nums.size() + 1;
    std::vector<long long> sums(nums.size() + 1, 0);

    for (int i = 1; i <= nums.size(); i++) {
      sums[i] = sums[i - 1] + nums[i - 1];
    }

    std::deque<int> dq{};
    int result = MAX_VALUE;

    for (int i = 0; i < sums.size(); ++i) {
      while (!dq.empty() && sums[i] - sums[dq.front()] >= k) {
        result = std::min(result, i - dq.front());
        dq.pop_front();
      }

      while (!dq.empty() && sums[i] <= sums[dq.back()]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    return result == MAX_VALUE ? -1 : result;
  }
};
