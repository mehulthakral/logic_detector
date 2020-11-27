class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4 or len(s) > 12:
            return []
        res = []
        self.dfs(s, 0, '', 0, res)
        return res
    
    def dfs(self, s, index, temp, count, res):
        if index == len(s) and count == 4:
            res.append(temp[:-1])
            return
        elif index == len(s) or count == 4:
            return
        else:
            self.dfs(s, index+1, temp+s[index]+'.', count+1, res)
            if index + 1 < len(s) and s[index] != '0': 
                self.dfs(s, index+2, temp+s[index]+s[index+1]+'.', count+1, res)
                if index + 2 < len(s) and int(s[index:index+3]) < 256:
                    self.dfs(s, index+3, temp+s[index:index+3]+'.', count+1, res)
