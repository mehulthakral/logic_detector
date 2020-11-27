class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        nums = []
        curr = head
        while curr:
            nums.append(curr.val)
            curr = curr.next
            
        nums[:] = nums[::-1]
        head = ListNode()
        curr = head
        for x in nums:
            curr.next = ListNode(x)
            curr = curr.next
            
        return head.next
