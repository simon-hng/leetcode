struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * The idea is to link the end and the start of the list, creating a loop and
 * then going to the intended end/start and changing their next values
 */
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return 0;

    int size{1};
    auto end{head};
    while (end->next) {
      end = end->next;
      ++size;
    };

    end->next = head;

    auto newEnd{head};
    for (int i{1}; i < (size - (k % size)); ++i) {
      newEnd = newEnd->next;
    }
    auto newHead = newEnd->next;

    newEnd->next = nullptr;

    return newHead;
  }
};
