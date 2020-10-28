class Solution:
    def isAnagram(self, s, t):
        h = {}
        for i in s:
            if i not in h:
                h[i] = 0
            h[i] += 1
                
        for j in t:
            if j not in h:
                h[j] = 0
            h[j] -= 1
        
        for key in h.keys():
            if h[key] != 0:
                return False
            
        return True