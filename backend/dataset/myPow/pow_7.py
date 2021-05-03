class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return self.calc((1/x), -1 * n)
        else:
            return self.calc(x, n)
    
    def calc(self,x,y):
        if y == 0:
            return 1
        if y == 1:
            return x
        if y % 2:
            return x * self.calc(x, y-1)
        return self.calc(x*x, y//2)