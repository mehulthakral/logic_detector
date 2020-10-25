class Solution:
    def isPalindrome(self, x: int) -> bool:
        if not x:
            return True
        elif x < 0:
            return False
        
        old_x = x
        new_x = 0
        
        while old_x:
            (t, r) = divmod(old_x, 10)
            new_x = new_x * 10 + r
            old_x = t

        return new_x == x
