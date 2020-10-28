class Solution:
    def isAnagram(self, s, t):
        dictionary = {}
        
        for i in s:
            if i in dictionary:
                dictionary[i] += 1
            else:
                dictionary[i] = 1

        for i in t:
            if i in dictionary:
                dictionary[i] -= 1
            else:
                return False

        for val in dictionary.values():
            if val != 0:
                return False
        
        return True
