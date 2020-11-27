class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        current = head
        previous = None
        nextNode = None

        while current:
            nextNode = current.next
            current.next = previous
            
            previous = current
            current = nextNode

        return previous