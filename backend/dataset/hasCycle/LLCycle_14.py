class Solution:
    def hasCycle(self, head:ListNode)->bool:
        fast = head
        slow = head
        
        while(fast and fast.next):
            if fast.next == slow: return True 
            fast = fast.next.next                
            slow = slow.next
        
        return False
