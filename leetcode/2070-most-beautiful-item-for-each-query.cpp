#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items,
                                 const std::vector<int>& queries) {
    std::sort(items.begin(), items.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
              });

    std::vector<int> prices, maxBeauty;
    int currMaxBeauty = 0;
    for (const auto& item : items) {
      int price = item[0], beauty = item[1];
      currMaxBeauty = std::max(currMaxBeauty, beauty);
      // Avoid duplicates by only adding new price points
      if (prices.empty() || prices.back() != price) {
        prices.push_back(price);
        maxBeauty.push_back(currMaxBeauty);
      } else {
        maxBeauty.back() = currMaxBeauty;
      }
    }

    std::vector<int> results;
    for (int query : queries) {
      auto it = std::upper_bound(prices.begin(), prices.end(), query);
      if (it == prices.begin()) {
        results.push_back(0);  // No price <= query
      } else {
        --it;
        int index = std::distance(prices.begin(), it);
        results.push_back(maxBeauty[index]);
      }
    }

    return results;
  }
};
