class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head:
            v_head = head        
            while v_head.next:
                temp = v_head.next
                v_head.next = v_head.next.next
                temp.next = head
                head = temp
            return head
