class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '' :
            return 0
        
        if needle in haystack :
            l = len(needle)
            h = len(haystack)
            if l ==  h :
                return 0
            for x in range(0, h - l+1) :
                if haystack[x : l + x] == needle :
                    return x 
        else :
            return -1 
