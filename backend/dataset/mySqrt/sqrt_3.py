class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        half = x//2
        index = x - half
        while True:
            if index*index == x:
                return index
            elif (index*index < x) and ((index+1)*(index+1) > x):
                return index
            elif (index*index > x) and ((index-1)*(index-1) < x):
                return (index-1)
            elif index*index > x:
                half = max(half//2, half%2)
                index -= half
            elif index*index < x:
                half = max(half//2, half%2)
                index += half
