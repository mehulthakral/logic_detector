class Solution:
    def mySqrt(self, x: int) -> int:
        '''
        Using the iterative method developed for EDSAC to calculate sqrt(x)
        https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#A_two-variable_iterative_method
        
        valid for 0 < x < 3
        let a_0 = x, c_0 = x-1
        then:
        a_n+1 = a_n-(a_n*c_n)/2
        c_n+1 = c_n^2*(c_n-3)/4
        
        for all n, x*(1+c_n) = a_n^2
        so as c_n -> 0, a_n -> sqrt(x)
        '''
        
        # eliminate trivial cases
        if x == 0 or x == 1:
            return x
        
        # floor(sqrt(x)) == floor(sqrt(x+k)) for 0 <= k < 1, so aim for the middle of that interval, x + 1/2
        x += 0.5
        
        # initialise a = x and c = x-1, but method only valid for 0 < x < 3 with fastest convergence around x = 1
        # so divide by 4 until 1/2 <= x < 2
        a = x
        factors_of_4 = 0
        while a >= 2:
            a /= 4
            factors_of_4 += 1
        c = a-1
        
        # iterate until error term less than 1/x^2, always gets suitably close
        error = 1/x**2
        while abs(c) > error:
            a -= a*c/2
            c = c*c*(c-3)/4
        
        # a = sqrt(x), but divided x by 4 many times earlier, so multiply a by 2 that many times for final answer
        return int(a*2**factors_of_4)
		
