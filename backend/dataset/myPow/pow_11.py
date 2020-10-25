from math import inf
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if abs(x) == 1:
            return 1 if n % 2 == 0 else x
        
        memo = {1: x}
        isInverse = n < 0
        m = abs(n)
        result = 1
        
        while m > 0:
            # reached lang limits
            if result == 0.0:
                return result
            if result == inf:
                break
                
            if m in memo:
                result *= memo[m]
                break
            
            subRes = x
            progress = 1
			
			# equivalent to floor(log2(m))
            while progress * 2 <= m:
                subRes *= subRes
                progress *= 2
            
            memo[progress] = subRes
            result *= subRes
            m -= progress
            
        return 1 / result if isInverse else result
    
