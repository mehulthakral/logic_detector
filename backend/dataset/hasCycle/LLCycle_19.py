class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head==None:
            return False
        if head.next==None:
            return False
        slow=head
        fast=head
        while fast!=None and fast.next!=None:
            fast=fast.next.next
            slow=slow.next
            if slow==fast:
                return True
        return False
