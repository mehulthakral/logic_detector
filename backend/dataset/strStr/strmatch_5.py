class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
            if not needle:
                return 0
            else:
                try:
                    return haystack.index(needle)
                except:
                    return -1
