class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        clone = head
        while clone:
            if clone.val == float('inf'):
                return True
            clone.val = float('inf')
            clone= head.next
        return False
