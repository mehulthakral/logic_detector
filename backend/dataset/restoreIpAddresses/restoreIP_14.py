class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        ans = []
        
        for i in range(1, min(n-2, 4)):
            for j in range(i+1, min(i+1+3,n-1)):
                for k in range(j+1, min(j+1+3,n)):
                    
                    if int(s[:i]) < 256 and int(s[i:j]) < 256 and int(s[j:k]) < 256 and int(s[k:]) < 256:
                        
                        if (s[:i]=="0" or s[:i][0] != "0") and (s[i:j]=="0" or s[i:j][0] != "0") and (s[j:k]=="0" or s[j:k][0] != "0") and (s[k:]=="0" or s[k:][0] != "0"):
                            
                            ans.append( s[:i] + "." +s[i:j] + "." + s[j:k] + "." + s[k:] )
        
        return ans