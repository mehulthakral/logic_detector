class Solution:
    def strStr(self, haystack, needle):
        n, h = len(needle), len(haystack)
        hash_n = hash(needle)
        for i in range(h-n+1):
            if hash(haystack[i:i+n]) == hash_n:
                return i
        return -1
