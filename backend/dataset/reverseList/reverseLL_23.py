class Solution:
	def reverseList(self, head: ListNode) -> ListNode:
		if not head:
			return None
		node = None
		while head:
			n = ListNode(head.val)
			n.next = node
			node = n
			head = head.next
		return node
