#include "../include/bits/stdc++.h"
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  vector<int> nums;

  int i = 0;
  int input;
  while (std::cin >> input && i < 4) {
    nums.push_back(input);
  }

  std::cout << *max_element(nums.begin(), nums.end()) << std::endl;

  return 0;
}
