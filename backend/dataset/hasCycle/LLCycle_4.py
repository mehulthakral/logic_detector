class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        while head != None:
            if(head.val == 'a'):
                return True
            else:
                head.val = 'a'
            head = head.next
        return False
