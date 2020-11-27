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
		
		# if sll is empty or ends after one
        if head is None or head.next is None:
		    #then return
            return head
        
		#previous node is set to none
		#current node is set to head
		#next node is set to current.next
        p_node, c_node, n_node = None, head, head.next
        
		#while next node is not equal to none
        while n_node is not None:
		
		    # current nodes pointer is set to the previous node
            c_node.next = p_node
			# previous node is set to current node
            p_node = c_node
			#current node is now set to next node
            c_node = n_node
			#next node is set to current node .next
            n_node = c_node.next
           
		#finish final iteration by redirecting last pointer
        c_node.next = p_node
		#declare new head
        head = c_node
		
		#return head of sll
        return head
