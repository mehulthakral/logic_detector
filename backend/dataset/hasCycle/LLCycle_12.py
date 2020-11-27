class Solution:
	def hasCycle(self, head:ListNode)->bool:
		if not head:
			return False 
		while head.next:
			if head.val is None:
				return True 
			head.val = None 
			head = head.next 

		return False 
