#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> relocateMarbles(std::vector<int>& nums,
                                   const std::vector<int>& moveFrom,
                                   const std::vector<int>& moveTo) {
    std::unordered_set<int> occupied{nums.begin(), nums.end()};

    for (int i{0}; i < moveFrom.size(); ++i) {
      if (occupied.contains(moveFrom[i])) {
        occupied.erase(moveFrom[i]);
        occupied.emplace(moveTo[i]);
      }
    };

    std::vector<int> result = std::vector(occupied.begin(), occupied.end());
    std::sort(result.begin(), result.end());
    return result;
  }
};
