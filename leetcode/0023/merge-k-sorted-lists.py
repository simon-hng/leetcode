from typing import Optional, List
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def merge(self, a: Optional[ListNode], b: Optional[ListNode]):
        node = ListNode()
        root = node

        while a and b:
            if a.val < b.val:
                node.next = a
                a = a.next
            else:
                node.next = b
                b = b.next

            node = node.next

        rest = a if a else b
        node.next = rest

        return root.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        result = lists[0]

        for i in range(1, len(lists)):
            result = self.merge(result, lists[i])

        return result
