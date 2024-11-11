#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    auto i{1};
    std::vector<int> critical;

    for (auto current{head}; current->next->next; current = current->next) {
      auto first = current;
      auto second = first->next;
      auto third = second->next;

      if (first < second && third < second ||
          first > second && third > second) {
        critical.push_back(i);
      }

      ++i;
    }

    int minDistance{-1};
    int maxDistance{-1};

    for (auto i{0}; i < critical.size() - 1; ++i) {
      minDistance = std::min(minDistance, critical[i + 1] - critical[i]);
    }
    if (critical.size() >= 2) {
      maxDistance = critical.back() - critical.front();
    }

    return {minDistance, maxDistance};
  }
};
