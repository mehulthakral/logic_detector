class Solution:
    def reverseList(self, head: ListNode, prev=None) -> ListNode:
            if head is None or head.next is None:
                return head
            smallHead = self.reverseList(head.next)
            tail = head.next
            tail.next = head
            head.next = None
            return smallHead
