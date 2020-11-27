class Solution:
    def reverse(self, x: int) -> int:
        
        result = 0
        limit = 2147483647 if x>=0 else -2147483648
        sign = 1 if x>=0 else -1

        for i, s in enumerate(str(abs(x))):
            if x > 0:
                if result+int(s)*pow(10, i) > limit:
                    return 0
                
            elif x < 0:
                if result-int(s)*pow(10, i) < limit:
                    return 0
            
			# Addition is guaranteed to be in the range: [-2147483648,  2147483647]
            result = result + sign*int(s)*pow(10, i)
            
        return result
