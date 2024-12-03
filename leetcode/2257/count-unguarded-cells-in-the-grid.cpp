#include <vector>

class Solution {
  enum GridType { UNGUARDED, GUARDED, GUARD, WALL };

 public:
  int countUnguarded(const int m, const int n,
                     const std::vector<std::vector<int>>& guards,
                     const std::vector<std::vector<int>>& walls) {
    std::vector<std::vector<GridType>> grid(
        m, std::vector<GridType>(n, UNGUARDED));

    for (auto& wall : walls) grid[wall[0]][wall[1]] = WALL;
    for (auto& guard : guards) grid[guard[0]][guard[1]] = GUARD;

    const auto setCovered = [&grid](int row, int col) -> bool {
      switch (grid[row][col]) {
        case GUARD:
          return false;
        case WALL:
          return false;
        case GUARDED:
          return true;
        case UNGUARDED:
          grid[row][col] = GUARDED;
          return true;
      }
    };

    for (auto& guard : guards) {
      for (int row{guard[0] + 1}; row < m; ++row)
        if (!setCovered(row, guard[1])) break;
      for (int row{guard[0] - 1}; row >= 0; --row)
        if (!setCovered(row, guard[1])) break;
      for (int col{guard[1] + 1}; col < n; ++col)
        if (!setCovered(guard[0], col)) break;
      for (int col{guard[1] - 1}; col >= 0; --col)
        if (!setCovered(guard[0], col)) break;
    };

    auto result{0};
    for (auto& row : grid)
      for (auto& cell : row)
        if (cell == UNGUARDED) ++result;

    return result;
  }
};
