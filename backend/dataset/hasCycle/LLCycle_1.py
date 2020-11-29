# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode)->bool:
        if head == None or head.next == None:
            return False
        p = head
        q = head.next
        while q and q.next:
            if p == q:
                break
            p = p.next
            q = q.next.next
        if p != q:
            return False
        return True
