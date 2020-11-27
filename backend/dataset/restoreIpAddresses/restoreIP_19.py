class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if s == "":
            return []
        self.rs = []
        self.ln = len(s)
        self.s = s
        self.helper(0, 0, "")
        
        return self.rs

    # part tell which part I am filling now, I have to fill 4 parts between three dots
    # idx tells which index of s I am currently at
    def helper(self, part, idx, tmp):
        if part < 4 and idx < self.ln:
            for i in range(idx, min(idx+3, self.ln)):
                nm = self.s[idx: i+1]
                if 0 <= int(nm) <= 255 and (i == idx or nm[0] != '0'):
                    self.helper(part+1, i+1, tmp + nm + ".")
        elif part == 4 and idx == self.ln:
            self.rs.append(tmp[:-1]) #remove extra dot