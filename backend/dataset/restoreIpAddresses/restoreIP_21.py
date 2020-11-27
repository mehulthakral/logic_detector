class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        
        def backtrack(comb, s, level):
            if (level == 0) and (s == ""):
                res.append(comb[:-1])
            elif (level != 0):
                for i in range(1,min(3+1, len(s)+1)):
                    if (i > 1) and (s[0] == '0'): # cannot start with '0', i.e. '1.001.0.1'
                        continue
                    if ( 0<= int(s[0:i]) <=255 ) :
                        backtrack(comb+s[0:i]+'.', s[i:], level-1)
        
        backtrack("", s, 4)
        return res
