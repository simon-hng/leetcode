#include "../include/bits/stdc++.h"

using namespace std;

class Solution {
  unordered_map<int, int> memo;

 public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;

    if (memo.contains(n)) return memo[n];

    auto result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    memo[n] = result;

    return result;
  }
};
