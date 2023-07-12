# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Edge case: if the list is empty
        if not head:
            return None

        # Initialize two pointers, p1 and p2, separated by n positions
        p1 = p2 = head
        for i in range(n):
            p2 = p2.next

        # If p2 is already at the end of the list, remove the head
        if not p2:
            return head.next

        # Move p1 and p2 together until p2 reaches the end of the list
        while p2.next:
            p1 = p1.next
            p2 = p2.next

        # Remove the element after p1
        p1.next = p1.next.next

        return head
