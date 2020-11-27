class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        while head:
            if head.val == 'LeetCode':
                return True
            head.val = 'LeetCode'
            head = head.next
        return False
