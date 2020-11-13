class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        ind=0
        if needle=="":
            return 0
        elif haystack=="":
            return -1
        elif needle in haystack:
            for index in range(0, len(haystack)):
                if haystack[index]==needle[0]:
                    ind, ind1=0, index
                    while True: 
                        if ind>=len(needle):
                            return index
                        elif haystack[ind1] != needle[ind]:
                            break
                        ind1 += 1
                        ind += 1
        else:
             return -1
