#include "../include/bits/stdc++.h"

using namespace std;
int main() {
  std::vector<std::string> numToText = {"one", "two",   "three", "four", "five",
                                        "six", "seven", "eight", "nine"};

  int a, b;
  std::cin >> a;
  std::cin >> b;

  for (int i = a; i <= b; i++) {
    if (0 <= i && i <= 9) {
      std::cout << numToText[i - 1] << std::endl;
    } else {
      std::cout << (i % 2 == 0 ? "even" : "odd") << std::endl;
    }
  }

  return 0;
}
