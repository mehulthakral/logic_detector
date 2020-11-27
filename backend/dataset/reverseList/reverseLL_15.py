class Solution:
    def reverseList(self, head: ListNode, prev=None) -> ListNode:
            prev , curr = None , head
            while curr is not None:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
            
            head = prev
            return head
