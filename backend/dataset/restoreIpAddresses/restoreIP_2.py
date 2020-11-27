class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def _solve(cur, rem, depth=0):
            
            if depth == 4:
                if len(cur) == len(s)+3:
                    sol.append(cur[:])
                return
            
            for i in range(1, min(len(rem)+1, 4)):
                new = rem[0:i]
                if 0 <= int(new) < 256 and not (int(new[0]) == 0 and len(new) > 1):
                    if not cur:
                        _solve(new, rem[i:], depth+1)
                    else:
                        _solve(cur + '.' + new, rem[i:], depth+1)
        
        sol = []
        _solve([], s)
        return sol
                
