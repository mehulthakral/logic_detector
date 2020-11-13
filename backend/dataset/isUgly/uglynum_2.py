class Solution:
    def isUgly(self, num: int) -> bool:
        if num==0:
            return False
        while num%2==0:
            num=num/2
        while num%3==0:
            num=num/3
        while num%5==0:
            num=num/5
        if num==1:
            return True
        return False
