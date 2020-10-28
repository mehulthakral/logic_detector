class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count={}
        for i in s:
            if i in count:
                count[i] +=1
            else:
                count[i]=1
        for i in t:
            if i in count:
                count[i] -=1
            else:
                count[i]=1
        for k in count:
            if count[k]!=0:
                return False
        return True