class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        count ={}
		# +1 for s and -1 for t. If the char from s not in count then assign 1 and if the char from t not in count , then assign -1. 
        for i in range(len(s)):
            if s[i] in count:
                count[s[i]] +=1
            else:
                count[s[i]] =1
            if t[i] in count:
                count[t[i]] -=1
            else:
                count[t[i]] = -1
        
        for key,value in count.items():
            if value !=0:
                return False
        return True
