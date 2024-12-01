#include <string>
#include <vector>

class Solution {
 public:
  bool wordBreak(const std::string s,
                 const std::vector<std::string>& wordDict) {
    std::vector<bool> dp(s.size() + 1, false);
    // This is one position right to the end of s.
    // Meaning that we succesfully broke down the entire word
    dp[s.size()] = true;

    // Go from the end in reverse order and check if we can break the word at
    // starting from position i
    for (int i = s.size() - 1; i >= 0; --i) {
      for (std::string word : wordDict) {
        // If the current word can be broken down from i.
        // Check if the next part was also able to be broken down.
        if (s.substr(i, word.size()) == word) dp[i] = dp[i + word.size()];
        // Don't check other words if this position is positive
        if (dp[i]) break;
      }
    }

    // Return if starting from index 0 the entire word can be broken down
    return dp[0];
  }
};
