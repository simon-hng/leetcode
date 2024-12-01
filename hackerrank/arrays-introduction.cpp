#include "../include/bits/stdc++.h"
using namespace std;

int main() {
  int size;
  std::cin >> size;

  int *numbers = int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> numbers[i];
  }

  for (int i = size - 1; i >= 0; --i) {
    std::cout << numbers[i] << std::endl;
  }
  return 0;
}
