#include "../include/bits/stdc++.h"

class Solution {
 public:
  int hIndex(const std::vector<int>& citations) {
    std::vector<int> h_to_count(citations.size() + 1);

    for (auto citation : citations) {
      h_to_count[std::min(citation, static_cast<int>(citations.size()))]++;
    }

    int count_higher{0};
    for (auto h = citations.size(); h >= 0; h--) {
      count_higher += h_to_count[h];
      if (h <= (count_higher)) return h;
    }

    return 0;
  }
};

int main() {
  Solution sol{};
  const std::vector<int> citations{4, 4, 0, 0};
  auto result = sol.hIndex(citations);

  std::cout << result << '\n';
}
