class Solution:
    def numTrees(self, n: int) -> int:
                
        # G(n) = solutions for n elements
        # F(i,n) = element i as root, n elements
        
        
        # Pseudo Code
        #G(n) = Sum of all F(i,n)
        #F(i,n) = G(i-1)*G(n-i)
        
        
        # Example
        # n = 3
        
        # base cases
        # G(0) = 1
        # G(1) = 1
        
        # G(3) = F(1,3)+F(2,3)+F(3,3)
        
        
        # F(1,3) = G(0)*G(2) = 2
        # Explanation 
        # Ex: G(0) = no elements on the left branch
        # Ex: G(2) = 2 elements on the right branch
        
        # F(2,3) = G(1)*G(1) = 1
        # Explanation
        # Ex: G(1) = 1 element on the left branch
        # Ex: G(1) = 1 element on the right branch
        
        # F(3,3) = G(2)*G(0) = 2
        # Explanation 
        # Ex: G(2) = 2 elements on the left branch
        # Ex: G(0) = no elements on the right branch
        

        g_array = [1,1]
        
        for j in range(2,n+1):
            sum_g = 0
            for i in range(1,j+1):
                f_i = g_array[i-1]*g_array[j-i]
                sum_g += f_i
            g_array.append(sum_g)
                        
        return g_array[n]
        
