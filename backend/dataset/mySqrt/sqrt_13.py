class Solution:
    def mySqrt(self, x: int) -> int:
        ## RC ##
        ## APPROACH : Binary Search ##
        #   1. Any number greater than 1, will have sqrt(n) less than n/2
        #   2. We can check i*i < n till n/2.
        #   3. Can be optimized with binary search, listing all nums till n/2 and check i*i < n
        if(x < 4): return 1 if (x!=0) else 0
            
        low = 2
        high = x//2 
        while(low <= high):
            mid = low + (high - low)//2
            if( mid**2 < x):
                low = mid + 1
            
            elif( mid**2 > x):
                high = mid - 1
            else:
                return mid
        return high
