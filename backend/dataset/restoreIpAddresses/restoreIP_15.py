class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def backtracking(tmpList: [int], start: int):
            if len(tmpList) == 4:
                if start != l: return # not ending with s
                res.append([x for x in tmpList])
            else:
                for i in range(start, start+lenIP):
                    # avoid out of range / less than 256 / '0*' can't pass
                    if i >= l or int(s[start: i+1]) > rangeIP or (s[start] == '0' and i > start): break # filter
                    tmpList.append(s[start: i+1])
                    backtracking(tmpList, i+1)
                    tmpList.pop()
        
        res = []
        l = len(s)
        lenIP = 3
        rangeIP = 255
        lenAddress = 4

        # special case
        if l < lenAddress: return []

        backtracking([], 0)

        return list(map(lambda x: '.'.join(x), res))
