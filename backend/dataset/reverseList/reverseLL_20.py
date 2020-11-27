class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        ## RC ##
        ## APPROACH : ITERATIVE ##
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(1) ##
        
        prev = None             # None
        curr = head             # curr always holds elements left to be reversed, (initially it is all elements i.e head)
        while(curr):
            temp = curr.next    # copy all expect 1st element 
            curr.next = prev    # replace all with previous, makes list reversed.
            prev = curr         # copy current reversed list into prev. prev( always holds reversed previous linked list)
            curr = temp
        return prev
        
        ## APPROACH : RECURSIVE ##
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##

        def helper(prev, curr):
            if not curr:
                return prev
            temp = curr.next
            curr.next = prev
            return helper(curr, temp)
        return helper(None, head)
