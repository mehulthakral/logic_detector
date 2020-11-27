class Solution:
    def reverse(self, x: int) -> int:
        if not x:
            return x
        x = list(str(x))
        while x[-1] == '0' and len(x) > 1:
            x.pop()
        left,right = 0,len(x)-1
        if x[left] == '-':
            left += 1
        while left < right:
            x[left],x[right] = x[right],x[left]
            left += 1
            right -= 1
        x = "".join(x)
        return 0 if int(x).bit_length() > 31 else int(x)
