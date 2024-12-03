#include "../include/bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int num : nums) {
      if (i < 2 || num > nums[i - 2]) nums[i++] = num;
    }

    return i;
  }
};

int main() {
  vector input = {1, 1, 1, 2, 2, 3};
  Solution sol{};

  auto result = sol.removeDuplicates(input);

  for (int i = 0; i < result; ++i) {
    cout << input[i] << endl;
  }
}
