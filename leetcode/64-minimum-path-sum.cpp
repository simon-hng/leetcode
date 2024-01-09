#include <algorithm>
#include <vector>

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int m{static_cast<int>(grid.size())};
    int n{static_cast<int>(grid.at(0).size())};

    for (int i{m - 2}; i >= 0; --i) grid[i][n - 1] += grid[i + 1][n - 1];
    for (int j{n - 2}; j >= 0; --j) grid[m - 1][j] += grid[m - 1][j + 1];

    for (int i{m - 2}; i >= 0; --i)
      for (int j{n - 2}; j >= 0; --j)
        grid[i][j] += std::min(grid[i + 1][j], grid[i][j + 1]);

    return grid[0][0];
  }
};
