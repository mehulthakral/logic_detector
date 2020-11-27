class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        length = len(s)
        nums = set(map(str, range(256)))
        def dfs(start: int, prefix: List[int]):
            if prefix and prefix[-1] not in nums:
                return
            if len(prefix) == 4:
                if start == length:
                    yield '.'.join(prefix)
                return
            for i in range(1, min(4, length-start+1)):
                yield from dfs(start + i, prefix + [s[start:start+i]])
        return list(dfs(0, []))
