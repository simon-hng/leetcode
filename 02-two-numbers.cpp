#include <iostream>

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root = new ListNode();
    ListNode* current = root;
    int carry = 0;
    while (l1 || l2 || carry) {
      int l1val = l1 ? l1->val : 0;
      int l2val = l2 ? l2->val : 0;

      int val = l1val + l2val + carry;
      carry = 0;
      if (val >= 10) {
        carry = val / 10;
        val %= 10;
      }

      current->next = new ListNode(val);
      current = current->next;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    return root->next;
  }
};

int main() {
  auto l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  auto l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  Solution solution;

  auto sol = solution.addTwoNumbers(l1, l2);
  std::cout << sol << std::endl;
}