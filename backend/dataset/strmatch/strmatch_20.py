class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        l1 = len(needle)
        l2 = len(haystack)
        if l1 > l2:
            return -1
        if l1 == 0 or l2 == 0:
            return 0
        if l1 == l2:
            if needle == haystack:
                return 0
        j = 0
        for i in range(l2-1):
            if haystack[i:l1+j] == needle:
                return i
            j+=1
        return -1