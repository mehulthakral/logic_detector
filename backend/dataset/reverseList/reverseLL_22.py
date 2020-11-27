class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        current = head
        while current is not None:
            n = current.next
            current.next = prev
            prev = current
            current = n
        head = prev
        return head
