class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if not 4 <= len(s) <= 12:
            return []
        res = []
        self.backtrack(s, 0, '', res, 0)
        return res

    def backtrack(self, s, start, path, res, count):
        if count == 4:
            if start == len(s):
                res.append(path[1:])
            return

        for end in [start + 1, start + 2, start + 3]:
			# number between 0 and 255 and does not start with 0
            if end <= len(s) and 0 <= int(s[start: end]) <= 255 and str(int(s[start: end])) == s[start: end]:
                self.backtrack(s, end, path + '.' + s[start: end], res, count + 1)
