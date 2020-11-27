# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def hcHelper(head, rdict):
    
    if head in rdict:
        return True
    rdict[head] = True
    if head.next:
        return hcHelper(head.next, rdict)
    return False
        

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        return hcHelper(head, {})