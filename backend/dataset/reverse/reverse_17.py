class Solution:
    def reverse(self, x: int) -> int:
        x, digit= str(x), str()
        if int(x) < 0:
            x += "-"
            x = x[1:]
        for i in reversed(x): digit += i
        if int(digit)<(-2**31) or int(digit)>((2**31)-1): return 0
        else: return int(digit)
