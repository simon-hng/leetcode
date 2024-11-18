#include <vector>

class Solution {
 public:
  std::vector<int> decrypt(std::vector<int>& code, int k) {
    std::vector<int> result(code.size(), 0);
    if (k == 0) return result;

    int left{1}, right{std::abs(k) + 1};
    int sum{0};
    for (auto i{1}; i <= std::abs(k); ++i) {
      sum += code[i];
    }

    while (left <= code.size()) {
      result[(k > 0 ? left - 1 : right) % code.size()] = sum;
      sum -= code[left++ % code.size()];
      sum += code[right++ % code.size()];
    }

    return result;
  };
};
