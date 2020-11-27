class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4 or len(s) > 12:
            return []
        
        res = []
        self.dfs(s, '', 0, res)
        return res
    
    def dfs(self, s, temp, count, res):
        if len(s) == 0 and count == 4:
            res.append(temp[:-1])
            return
        elif len(s) == 0 or count == 4:
            return
        else:
            self.dfs(s[1:], temp+s[0]+'.', count+1, res)
            if s[0] != '0' and len(s) > 1:
                self.dfs(s[2:], temp+s[0:2]+'.', count+1, res)
                if len(s) > 2 and int(s[0:3]) < 256:
                    self.dfs(s[3:], temp+s[0:3]+'.', count+1, res)
