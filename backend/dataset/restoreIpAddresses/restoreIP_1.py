from typing import List
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:        
        def backtrack(ip, num_of_addr=4):
            if len(ip) < num_of_addr * 1 or len(ip) > num_of_addr * 3:
                return []
            
            if num_of_addr == 1:
                if (len(ip) == 1) or (len(ip) == 2 and ip[0] != '0') or \
                    (len(ip) == 3 and ip[0] != '0' and int(ip) <= 255):
                    return [ip]
                
                return []
            
            res = []
            for i in range(1, 3+1):
                init = backtrack(ip[:i], 1)
                if init:
                    after = backtrack(ip[i:], num_of_addr-1)
                    if after:
                        res.append(init + after)
            
            new_res = []
            for i in range(len(res)):
                for j in range(1, len(res[i])):
                    new_res.append(res[i][0] + '.' + res[i][j])
            
            return new_res
                    

        return backtrack(s)
