class Solution:
    def restoreIpAddresses(self, s:str, parts=4)->List[str]:
        
        if s == '':
            return []
        
        if parts == 1:
            if int(s) <= 255 and str(int(s)) == s:
                return [s]
            else:
                return []
            
        combs = []
        
        for section in [1, 2, 3]:
            if s[0:section] == str(int(s[0:section])) and int(s[0:section]) <= 255:
                for i in self.restoreIpAddresses(s[section:], parts - 1):
                    combs.append(s[0:section] + "." + i)
            
            
        return combs
