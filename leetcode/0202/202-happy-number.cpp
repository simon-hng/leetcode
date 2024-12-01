#include <unordered_set>

class Solution {
 public:
  bool isHappy(int n) {
    if (n == 1) return true;
    if (not_happy.contains(n)) return false;
    not_happy.insert(n);

    int sum{0};
    while (n != 0) {
      int digit{n % 10};
      sum += digit * digit;
      n = n / 10;
    }

    return isHappy(sum);
  }

 private:
  std::unordered_set<int> not_happy;
};
