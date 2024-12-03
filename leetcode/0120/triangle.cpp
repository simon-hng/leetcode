#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * Recursive solution.
 */
/**
class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle,
                   std::pair<int, int> indexes) {
    auto [row, column] = indexes;

    auto current_value{triangle[row][column]};
    if (row == triangle.size() - 1) return current_value;

    return current_value +
           std::min(minimumTotal(triangle, {row + 1, column}),
                    minimumTotal(triangle, {row + 1, column + 1}));
  }

  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    return minimumTotal(triangle, {0, 0});
  }
};
**/

/**
 * Recursive with memo solution.
 */
/*
class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle,
                   std::pair<int, int> indexes,
                   std::vector<std::vector<int>>& memo) {
    auto [row, column] = indexes;
    auto current_value{triangle[row][column]};

    if (row == triangle.size() - 1) return current_value;
    if (memo[row][column] != -1) return memo[row][column];

    memo[row][column] =
        current_value +
        std::min(minimumTotal(triangle, {row + 1, column}, memo),
                 minimumTotal(triangle, {row + 1, column + 1}, memo));
    return memo[row][column];
  }

  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    std::vector<std::vector<int>> memo(triangle.size(),
                                       std::vector<int>(triangle.size(), -1));
    return minimumTotal(triangle, {0, 0}, memo);
  }
};
*/

/*
 * DP Bottom-up approach
 */
class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    for (int i{static_cast<int>(triangle.size() - 2)}; i >= 0; --i) {
      for (int j{0}; j <= i; ++j)
        triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }

    return triangle[0][0];
  }
};

int main() {
  Solution sol{};
  std::vector<std::vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

  std::cout << sol.minimumTotal(triangle) << '\n';
}
