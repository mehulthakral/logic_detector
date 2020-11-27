class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        dictionary = {}
        while head:
            if head in dictionary: 
                return True
            else: 
                dictionary[head]= True
            head = head.next
        return False
