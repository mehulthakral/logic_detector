class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        ## RC ##
        ## APPROACH : 2 POINTER ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(1) ##
        
        slow = fast = head
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
            if(slow == fast):
                return True
        return False
