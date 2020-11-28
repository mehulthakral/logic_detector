class Solution:
    def strStr(self, haystack, needle):
        if haystack == needle: return 0
        if len(haystack) < len(needle): return -1
        
        for i in range(len(haystack) - len(needle) + 1):
            foundIt = True
            for j, patternChar in enumerate(needle):
                if haystack[i + j] != patternChar:
                    foundIt = False
                    break
            if foundIt: return i
        return -1
                
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """  