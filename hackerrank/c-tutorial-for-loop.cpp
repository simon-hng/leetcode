#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

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
