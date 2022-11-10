from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root = head
        node = root
        while(node != None):
            next = node.next

            while (True):
                if (next == None or node.val < next.val):
                    node.next = next; 
                    break;
                next = next.next

            node = node.next

        return root
        
