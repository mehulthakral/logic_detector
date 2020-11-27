class Solution:
    def hasCycle(self, head: ListNode) -> bool:

        if head == None or head.next == None:
            return False
        fast = head.next
        slow = head
        while fast!= None and fast.next!=None:

            if slow == fast:
                return True
            
            slow = slow.next
            fast = fast.next.next
            
        return False
