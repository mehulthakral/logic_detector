class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        def restore(s,ip,start,end,c,result):
            if start == end and c == 4:
                result.append(ip)
                return 0
            
            if c >3:
                return
            if start < end:
                minIndex = min(start+(3 if s[start] != '0' else 1),end)
                res = 0

                for i in range(start,minIndex):
                    res = res*10 +int(s[i])
                    if res < 256:
                        restore(s,ip+str(res)+("." if c != 3 else ""),i+1,end,c+1,result)
                    else:
                        break
                    
        restore(s,"",0,len(s),0,res)
        return res
