#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxEqualRowsAfterFlips(const std::vector<std::vector<int>>& matrix) {
    std::unordered_map<std::string, int> keyToCount{};
    for (auto row : matrix) {
      std::string key{row.begin(), row.end()};

      if (key[0] == 1) {
        for (auto& c : key) c ^= 1;
      }

      keyToCount[key]++;
    }

    int result{0};
    for (auto [_, count] : keyToCount) {
      result = std::max(result, count);
    }

    return result;
  }
};
