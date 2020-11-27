class Solution:
    def reverse(self, x: int) -> int:
        isneg = x<0
        x = abs(x)
        rev = 0
        while(x>0):
            rem = x%10
            rev = rev*10+rem
            x = x//10
        
        if rev >= 2** 31 -1 or rev <= -2** 31:
            return 0

        elif isneg:
            return 0-rev
        else:
            return rev 
