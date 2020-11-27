class Solution:
    def mySqrt(self, x: int) -> int:

        if x == 1 or x == 0:
            return x

        lower = 0
        upper = x//2 if x > 4 else x
        middle = (lower + upper +1)//2

        while True:
            if (middle * middle <= x) and ((middle + 1) * (middle + 1) > x) :
                break
            elif middle * middle > x:
                upper = middle
            elif (middle+1) * (middle+1) <= x:
                lower = middle
            middle = (lower + upper +1)//2
        return middle
