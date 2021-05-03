from dataset_server import ListNode
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        pre = None

        while head:
            next_node = head.next
            head.next = pre
            pre = head
            head = next_node
        return pre
