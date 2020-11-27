class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None :
            return head 
        if head.next is not None:
            last = None
            point = head
			
            while point is not None:
                point.next, point, last = last, point.next, point
                
            return last
	
