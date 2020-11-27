class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def split(l, r, n):    # try to split s[l:r] in half
            if n == 1:         # when we cannot further split
                t = s[l:r]
                # check if the string is a valid element of an IP address
                return [] if int(t) > 255 or len(t) > 1 and t.startswith('0') else [[t]]
            L, n = r - l, n >> 1
            # further split the string at index `i` such that n <= len(s[l:i]) <= 3*n and n <= len(s[i:r]) <= 3*n
            return [a+b for i in range(max(n, L-3*n), min(3*n, L-n)+1) for a, b in itertools.product(split(l, l+i, n), split(l+i, r, n))]
        return ('.'.join(addr) for addr in split(0, len(s), 4))
