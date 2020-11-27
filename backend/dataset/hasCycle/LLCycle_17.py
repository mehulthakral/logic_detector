class Solution:
    def hasCycle(self, H: ListNode) -> bool:
        S = set([id(H)])
        while H != None:
            if id(H.next) in S: return True
            H, _ = H.next, S.add(id(H.next))
        return False