class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        obj1 = {}
        obj2 = {}
        
        for i in s:
            if i not in obj1:
                obj1[i] = 1
            else:
                obj1[i] += 1
        
        for i in t:
            if i not in obj2:
                obj2[i] = 1
            else:
                obj2[i] += 1
                
        return obj1 == obj2    # In python you can compare dictionaries
