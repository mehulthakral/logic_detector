class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle=="": return 0
        x = len(haystack.split(needle)[0])
        return x if len(haystack)!=x else -1
