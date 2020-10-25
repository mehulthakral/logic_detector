class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        x_s = str(x)
        return x_s == x_s[::-1] 
