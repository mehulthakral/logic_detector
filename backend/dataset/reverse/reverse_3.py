class Solution:
    def reverse(self, x: int) -> int:
        
        d=abs(x)
        newNum=0
    
        while d>0:
            d,m=divmod(d,10)
            newNum=(newNum*10)+m
        
        if newNum>=(2**31)-1:
            return 0
        return newNum if x>0 else newNum*-1
