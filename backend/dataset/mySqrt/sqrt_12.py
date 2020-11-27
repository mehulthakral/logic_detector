class Solution:
    def mySqrt(self, x:int)->int:        
        eps = 1
        x_i = 1
        while(abs(self.newton(x_i, x) - x_i) > eps):
            x_i = self.newton(x_i, x) 
        
        if int(x_i) * int(x_i) > x:
            return int(x_i) - 1
        
        return int(x_i)
        
    
    def newton(self, x_i, a):
        return 0.5 * (x_i + a / x_i)
