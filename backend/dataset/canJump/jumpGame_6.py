class Solution:
    def canJump(self, A:List[int])->bool:
        last = len(A)-1
        if not last:
            return True
        i   = 0
        Lim = i + A[i]
        while i < Lim:
            i += 1
            Lim = max(Lim, i+A[i])
            if Lim>=last:
                return True
        return False
