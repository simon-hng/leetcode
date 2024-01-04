#include "../include/bits/stdc++.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    int size = get_size(head);
    if (size <= 1) return nullptr;

    int middle = size / 2;
    ListNode* current = head;
    for (int i = 0; i < middle - 1; ++i) current = current->next;
    current->next = current->next->next;

    return head;
  }

  constexpr int get_size(const ListNode* head) {
    if (!head) return 0;
    return 1 + get_size(head->next);
  }
};
