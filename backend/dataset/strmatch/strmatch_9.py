class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if haystack == needle:
            return 0
        
        if not needle:
            return 0
        
        len_needle = len(needle)
        len_haystack = len(haystack)

        dp = self.kmp_algo(needle)
        
        i = 0
        j = 0
        
        while i < len_haystack:
            while j > 0 and haystack[i] != needle[j]:
                j = dp[j-1]

            if haystack[i] == needle[j]:
                j += 1            
            i += 1

            if j == len_needle:
                return i - j

        return -1
    
    def kmp_algo(self, needle):
        len_needle = len(needle)
        dp = [0] * len(needle)
        
        i = 1
        j = 0
        
        while i < len_needle:
            while j > 0 and needle[j] != needle[i]:
                j = dp[j-1]
            if needle[i] == needle[j]:
                j += 1
                dp[i] = j

            i += 1
        return dp
                    
