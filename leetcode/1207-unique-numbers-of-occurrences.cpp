#include <unordered_set>
class Solution {
 public:
  bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> num_to_occurrence{};

    for (auto item : arr) {
      num_to_occurrence[item]++;
    }

    std::unordered_set<int> occurences;
    for (auto [key, value] : num_to_occurrence) {
      if (occurences.contains(value)) return false;
      occurences.insert(value);
    }

    return true;
  }
};
