class Solution:
    def reverse(self, x: int) -> int:
        res=str(x)
        if (x<0):
            res=int("-" + res[1:][::-1] )
            return res if -2147483648 < res else 0    
        else:
            res=int(res[::-1])
            return res if res < 2147483647 else 0
