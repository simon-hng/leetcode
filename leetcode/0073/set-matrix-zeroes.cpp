#include "../include/bits/stdc++.h"

/**
 * TODO: This solution is not very smart/efficient
 * https://leetcode.com/problems/set-matrix-zeroes/solutions/
 */
class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix,
                 std::vector<std::vector<bool>>& swapped,
                 std::pair<int, int> coords) {
    auto [x, y] = coords;

    for (int i{0}; i < matrix.size(); ++i) {
      if (matrix[i][y] != 0) {
        matrix[i][y] = 0;
        swapped[i][y] = true;
      }
    }

    for (int j{0}; j < matrix.at(0).size(); ++j) {
      if (matrix[x][j] != 0) {
        matrix[x][j] = 0;
        swapped[x][j] = true;
      }
    }
  }

  void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<bool>> swapped = std::vector<std::vector<bool>>(
        matrix.size(), std::vector<bool>(matrix.at(0).size(), false));

    for (auto i{0}; i < matrix.size(); ++i) {
      for (auto j{0}; j < matrix.at(0).size(); ++j) {
        if (matrix[i][j] == 0 && !swapped[i][j])
          setZeroes(matrix, swapped, {i, j});
      }
    }
  }
};

int main() {
  Solution sol{};
  std::vector<std::vector<int>> matrix{{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}};
  sol.setZeroes(matrix);
}
