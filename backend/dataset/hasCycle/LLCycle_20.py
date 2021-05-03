from dataset_server import ListNode
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        l={}
        while head:
            if(head in l):
                return True
            else:
                l[head]=True
            head=head.next
        return False
