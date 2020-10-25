class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return Solution.calc((1/x), -1 * n)
        else:
            return Solution.calc(x, n)
    
    @staticmethod
    def calc(x,y):
        if y == 0:
            return 1
        if y == 1:
            return x
        if y % 2:
            return x * Solution.calc(x, y-1)
        return Solution.calc(x*x, y//2)