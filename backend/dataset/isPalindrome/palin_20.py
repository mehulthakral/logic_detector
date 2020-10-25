class Solution:
    def isPalindrome(self, x: int) -> bool:
        return x >= 0 and x == int(f"{x}"[::-1])
