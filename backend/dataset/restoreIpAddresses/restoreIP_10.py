class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
        dp = [[] for _ in s]
        
        for i in range(1, len(s) + 1):
            for j in range(max(0, i - 3), i):
                ip = (s[j:i])
                if  0 <= int(ip) <= 255:
                    if str(int(ip)) == ip:
                        if j == 0 and i != len(s):
                            dp[i-1].append([ip])    
                        else:
                            if i != len(s):
                                for ips in dp[j-1]:
                                    if len(ips) < 3:
                                        dp[i-1].append(ips + [ip])
                            else:
                                for ips in dp[j-1]:
                                    if len(ips) == 3:
                                        dp[i-1].append(ips + [ip])
      
        return [".".join(ips) for ips in dp[len(s) -1]]
