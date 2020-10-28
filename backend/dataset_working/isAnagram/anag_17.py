class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic_s, dic_t = {}, {}
        for letter in s:
            if letter not in dic_s:
                dic_s[letter] = 1
            else:
                dic_s[letter] += 1
        for letter in t:
            if letter not in dic_t:
                dic_t[letter] = 1
            else:
                dic_t[letter] += 1
        return dic_t == dic_s
