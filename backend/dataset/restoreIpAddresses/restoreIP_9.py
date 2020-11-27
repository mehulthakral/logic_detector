class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        
        def backtrack(idx, ip):
            if len(ip)==4 and idx==len(s):
                self.res.append(".".join(ip))
        
            elif len(ip)<4:
                if idx<=len(s)-1:
                    backtrack(idx+1, ip+[s[idx]])
                    
                if idx<=len(s)-2 and int(s[idx:idx+2])>=10:
                    backtrack(idx+2, ip+[s[idx:idx+2]])
                    
                if idx<=len(s)-3 and int(s[idx:idx+3])>=100 and int(s[idx:idx+3])<=255:
                    backtrack(idx+3, ip+[s[idx:idx+3]])
        
        
        self.res=[]
        backtrack(0, [])
        return(self.res)
