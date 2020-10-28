from collections import deque
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        d=deque(str(x))
        while d:
            l=d.popleft()
            if d: #For odd cases like 121,422 
                r=d.pop()
                if int(l)!=int(r):
                    return False
        return True
