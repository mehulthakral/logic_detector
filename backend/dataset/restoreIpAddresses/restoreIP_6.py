class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
            
            self.res = []
            
            self.buildIp(s, '', 0)
            
            return self.res
        
        def buildIp(self, s: str, prefix: str, integers: int) -> None:
            
            if not s:
                if integers == 4: self.res.append(prefix)
                return
            
            if integers > 3:
                return
            
            period = '.' if integers < 3 else ''
            
            self.buildIp(s[1:], prefix + s[0] + period, integers + 1)
                
            if 9 < int(s[0:2]) < 100:
                self.buildIp(s[2:], prefix + s[0:2] + period, integers + 1)
            
            if 99 < int(s[0:3]) < 256:
                self.buildIp(s[3:], prefix + s[0:3] +  period, integers + 1)
