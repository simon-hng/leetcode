struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto findNextNode = [](ListNode* node) -> ListNode* {
      auto val{node->val};
      while (node && node->val == val) node = node->next;
      return node;
    };

    ListNode* root = new ListNode{0, head};
    auto current = root;

    while (current) {
      while (current->next && current->next->next &&
             current->next->val == current->next->next->val)
        current->next = findNextNode(current->next);

      current = current->next;
    }

    return root->next;
  }
};
