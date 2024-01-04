#include "../include/bits/stdc++.h"
using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'};

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      while (left < right && !vowels.contains(s[left])) ++left;
      while (left < right && !vowels.contains(s[right])) --right;
      std::swap(s[left++], s[right--]);
    }

    return s;
  }
};

int main() {
  Solution sol;
  std::cout << sol.reverseVowels("a.") << "\n";
}
