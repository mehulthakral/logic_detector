class Solution:
    def reverse(self, x: int) -> int:
            minLimit = -2**31
            maxLimit = 2**31
            
            numStr = str(x) #Conversion
            numStr = numStr[::-1] #Reverse digits
            
            if numStr.endswith("-"):
                numStr = "-" + numStr[:-1] #Remove "-" sign from the end and add it to the beginning

            number = int(numStr)
            if number not in range(minLimit,maxLimit): #Overflow
                return 0
            
            return number
