#include <vector>
class Solution {
 public:
  void dfs(std::vector<std::vector<char>>& grid, std::pair<int, int> cords) {
    // Out of bounds
    if (cords.first < 0 || cords.second < 0 || cords.first >= grid.size() ||
        cords.second >= grid.at(0).size())
      return;

    if (grid[cords.first][cords.second] == '0') return;
    grid[cords.first][cords.second] = '0';
    dfs(grid, {cords.first + 1, cords.second});
    dfs(grid, {cords.first - 1, cords.second});
    dfs(grid, {cords.first, cords.second + 1});
    dfs(grid, {cords.first, cords.second - 1});
  }

  int numIslands(std::vector<std::vector<char>>& grid) {
    int result{0};

    for (auto i{0}; i < grid.size(); ++i) {
      for (auto j{0}; j < grid.at(0).size(); ++j) {
        if (grid[i][j] == '1') {
          result++;
          dfs(grid, {i, j});
        }
      }
    }

    return result;
  }
};
