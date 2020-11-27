class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        curr = head        
        while curr.next:
            temp = curr.next
            curr.next = temp.next
            temp.next = head
            head = temp
            
        return head
