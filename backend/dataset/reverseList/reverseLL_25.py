# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = Noneb=[]
class Solution:
    
    def reverseList(self, head: ListNode) -> ListNode:
    
        prev:ListNode = None #created an Empty Node
        curr = head # The Head Node is now current(curr) node
        while curr!= None: #Iterate until the Node is None
            nexttemp: ListNode = curr.next #created a temp Node to remember the next Node
            curr.next = prev # assigning the next Node of current as Prev (for first iteration it will be None)
            prev = curr # Now the prev become current
            curr = nexttemp # current become the node which we stored in the temp Node(nexttemp)
        return prev
            
