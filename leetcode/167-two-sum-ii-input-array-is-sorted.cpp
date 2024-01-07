#include <unordered_map>
#include <vector>

class SolutionTwoPointer {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, const int target) {
    int left{0}, right{static_cast<int>(numbers.size() - 1)};

    while (left < right) {
      int current{numbers[left] + numbers[right]};
      if (current == target) {
        return {left + 1, right + 1};
      }
      if (current > target)
        right--;
      else
        left++;
    }

    // should not happen by assumption
    return {};
  }
};

class SolutionHashMap {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, const int target) {
    std::unordered_map<int, int> value_to_index{};

    for (int i{0}; i < numbers.size(); ++i) {
      if (value_to_index.contains(target - numbers[i])) {
        return {value_to_index[target - numbers[i]] + 1, i + 1};
      }
      value_to_index.insert({numbers[i], i});
    }

    // Should not happen by assumption.
    return {};
  }
};
