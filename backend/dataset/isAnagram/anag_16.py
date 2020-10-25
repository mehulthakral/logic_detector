class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        dicts = {}
        
        for i in s:
            if i in dicts:
                dicts[i] += 1
            else:
                dicts[i] = 1
        
        for i in t:
            if i in dicts:
                dicts[i] -= 1
            else:
                return False
        
        for value in dicts.values():
            if value != 0:
                return False
        
        return True
