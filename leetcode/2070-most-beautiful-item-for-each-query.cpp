#include <map>
#include <vector>

class Solution {
 public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items,
                                 const std::vector<int>& queries) {
    std::sort(items.begin(), items.end());

    std::map<int, int> itemToBeauty{};
    auto maxBeauty{0};
    for (const auto& item : items) {
      maxBeauty = std::max(item[1], maxBeauty);
      itemToBeauty[item[0]] = maxBeauty;
    }

    std::vector<int> result{};
    for (const auto& query : queries) {
      auto it = itemToBeauty.upper_bound(query);
      result.push_back(it != itemToBeauty.begin() ? (--it)->second : 0);
    }

    return result;
  }
};
