class Solution:
    def reverse(self, x: int) -> int:
        s = -1 if x < 0 else 1
        x_ = str(x)[-1::-1] if s == 1 else str(x)[-1:0:-1]
        ans = s*int(x_)
        return ans if abs(ans) < 2**31 else 0
