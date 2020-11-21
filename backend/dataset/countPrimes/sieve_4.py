
class Solution(object):
    def countPrimes(self, n:int)->int:
	
        if n < 2:
            return 0
			
        k = [1] * n
        k[0] = 0
        k[1] = 0
        for i in range(2, int(n**0.5)+1):
            if  k[i] != 0:
                k[i*i:n:i] = [0] * ((n-1-i*i)//i + 1)

        return sum(k)

