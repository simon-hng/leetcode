
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Floyds Cycle detection algorithm
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    auto fast{head}, slow{head};

    while (fast != nullptr && fast->next != nullptr &&
           fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) return true;
    }

    return false;
  }
};
