# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head:ListNode)->ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """
        node_values = []
        
        current_node = head
        
        while current_node is not None:
            node_values.insert(0, current_node.val)
            current_node = current_node.next
        
        c_n = head
        idx = 0
        
        while c_n is not None:
            c_n.val = node_values[idx]
            c_n = c_n.next
            idx+=1
                
        return head
