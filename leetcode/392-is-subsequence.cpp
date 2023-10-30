#include <iostream>
#include <string>

class Solution {
 public:
  bool isSubsequence(std::string s, std::string t) {
    int t_pointer = 0;

    for (int s_pointer = 0; s_pointer < s.length(); s_pointer++) {
      for (; s[s_pointer] != t[t_pointer]; t_pointer++) {
        if (t_pointer >= t.length()) {
          return false;
        }
      }
      t_pointer++;
    }

    return true;
  }
};

int main() {
  Solution sol = Solution();
  sol.isSubsequence("abc", "ahbgdc");
}
