#include "../include/bits/stdc++.h"

class Solution {
 public:
  int numUniqueEmails(const std::vector<std::string>& emails) {
    std::unordered_set<std::string> seen{};

    for (const auto& email : emails) {
      auto isInLocalname{true};
      auto ignoring{false};
      std::string current{""};

      for (const auto& c : email) {
        if (c == '@') {
          isInLocalname = false;
        }

        if (isInLocalname) {
          if (c == '.' || ignoring) {
            continue;
          };
          if (c == '+') {
            ignoring = true;
            continue;
          };
        }

        current += c;
      }

      seen.insert(current);
    }

    return seen.size();
  }
};
