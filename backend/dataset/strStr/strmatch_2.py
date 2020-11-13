class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle or haystack == needle:
            return 0
        len_needle, len_haystack = len(needle), len(haystack)
        if len_needle > len_haystack:
            return -1
        for i in range(len_haystack):
            index = 0
            for j in range(i, i + len_needle):
                if j >= len_haystack:
                    return -1
                if haystack[j] == needle[index]:
                    index += 1
                    continue
                else:
                    break
            if index == len_needle:
                return i
        return -1
