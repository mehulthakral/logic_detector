class Solution:
    def isPalindrome(self, x: int) -> bool:
        half = len(str(x))//2
        string = str(x)
        for i in range(0,half):
            if string[i] == string[-i-1]:
                continue
            else:
                return False
                break
        return True
