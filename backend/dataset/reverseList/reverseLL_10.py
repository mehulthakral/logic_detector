class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        v_head = head
        prev = None
        while v_head:
            temp = v_head.next
            v_head.next = prev
            prev = v_head
            v_head = temp
        return prev
