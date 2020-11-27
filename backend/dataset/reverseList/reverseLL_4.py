# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        curr_node = head
        
        next_node = head.next
        
        prev_node = None
        
        while True:
            
            curr_node.next = prev_node
            
            if next_node is None:
                head = curr_node
                break
            
            prev_node = curr_node
            
            curr_node = next_node
            
            next_node = next_node.next
            
        
        return head
