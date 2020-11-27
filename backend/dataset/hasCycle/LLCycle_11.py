class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        node_set = set()
        while head and head.next:
            slow, fast = head.next, head.next.next
            if (head, slow, fast) in node_set:
                return True
            else:
                node_set.add((head, slow, fast))
                head = slow
        return False
