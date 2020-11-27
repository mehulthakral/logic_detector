class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # corner case
        if not head: return False
        
        i = 0
        while i <= 10000:
            head = head.next
            if head == None:
                return False
            i += 1
        return True
