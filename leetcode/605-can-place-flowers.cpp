#include "../include/bits/stdc++.h"
using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size(); ++i) {
      if (n == 0) return true;
      auto left{(i == 0) ? 0 : flowerbed[i - 1]};
      auto right{(i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1]};

      if (!left && !right && !flowerbed[i]) {
        flowerbed[i] = 1;
        --n;
      }
    }

    return n == 0;
  }
};

int main() {
  Solution sol{};
  auto input = std::vector<int>{1, 0, 0, 0, 1, 0, 0};
  cout << sol.canPlaceFlowers(input, 1) << endl;
}
