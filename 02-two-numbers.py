import math

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode()
        current = root
        carry: int = 0

        while(l1 != None || l2 != None || carry != 0):
            l1val = 0
            if (l1 != None):
                l1val = l1.val
                l1 = l1.next

            l2val = 0
            if (l2 != None):
                l2val = l2.val
                l2 = l2.next

            current.val = l1val + l2val + carry
            current.next = ListNode()
            current = current.next

        return root

def main():
    print(listToNum(numToList(342 + 465)))
    print(listToNum(numToList(708)))

if __name__ == "__main__":
    main()

