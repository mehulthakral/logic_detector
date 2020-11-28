class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return(0)
        if haystack == needle:
            return(0)
        if needle in haystack:
            for i in range(len(haystack)+1):
                if needle in haystack[0:i]:
                    return(i - len(needle))
                # print(haystack[0:i])
        else:
            return(-1)
