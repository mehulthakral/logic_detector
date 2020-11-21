class Solution:
    def countPrimes(self, n: int) -> int:
        """
		1. Creating a list of consecutive integers
		2. Initializing p = 2 (First prime number)
		3. starting from p^2 and counting in increments of 2 while marking each number
		4. Finding an unmarked number greater than p and setting it as the new value of p
		""" 
		number_list = [False for i in range(n+1)]
        p = 2
        while p*p < n:
            if not number_list[p]:
                for i in range(p*p, n+1, p):
                    number_list[i] = True
            p += 1
        
        count= 0
        for p in range(2,n):
            if not number_list[p]:
                count += 1
        return count
