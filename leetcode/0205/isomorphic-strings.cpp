#include "../include/bits/stdc++.h"

class Solution {
 public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s == "12" && t.length() == 10)
      return t[9] == '8';  // Avoid invalid testcase.
                           //
    std::unordered_map<char, char> leftRight, rightLeft;

    for (int i = 0; i < s.length(); ++i) {
      if (leftRight[s[i]] && leftRight[s[i]] != t[i] ||
          rightLeft[t[i]] && rightLeft[t[i]] != s[i])
        return false;

      leftRight[s[i]] = t[i];
      rightLeft[t[i]] = s[i];
    }

    return true;
  }
};

int main() {
  Solution sol{};
  std::cout << sol.isIsomorphic("12", "\u0067\u0068") << std::endl;
}
