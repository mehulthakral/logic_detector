class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        path = []
        result = []
        self.dfs(s, path, result)
        return result
    
    def dfs(self, s: str, path: List, result: List):
        
        if not s and len(path) == 4:
            s = '.'.join(path[::-1])
            result.append(s)
            return
        elif len(path) == 4: return 
        else:
            for i in range(1, min(3, len(s))+1):
                if int(s[:i]) >= 0 and int(s[:i]) <= 255:
                    if i > 1 and s[0]=='0': continue
                    else: self.dfs(s[i:], [s[:i]]+path, result)
            return
