class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def reverse(node: ListNode, prev: ListNode = None) -> ListNode:
            
            if not node:
                return prev
            
            next, node.next = node.next, prev
            
            return reverse(next,node)
            
        return reverse(head)
