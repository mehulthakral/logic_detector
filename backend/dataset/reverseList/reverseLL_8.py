class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        node, prev = head, None
        
        while node:
            next, node.next = node.next, prev
            prev, node = node, next
            
        return prev
