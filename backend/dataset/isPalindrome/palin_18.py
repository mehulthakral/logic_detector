class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        n=str(x)
        i,j=0,len(n)-1
        while j>=i:
            if n[i]==n[j]:
                i+=1
                j-=1
            else:
                return False
        return True
