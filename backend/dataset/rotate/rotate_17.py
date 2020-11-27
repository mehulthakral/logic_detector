class Solution:
    def rotate(self, a: List[int], k: int) -> None:
        n = len(a)
        c = 1
        if k != 0:
            if k != 1:
                c = gcd(n, k)
            for i in range(c):
                j = (i + k)%n
                b = a[i]
                while j != i:
                    d = a[j]
                    a[j] = b
                    b = d
                    j = (j+k)%n
                a[j] = b

    def gcd(m, n):
        if m % n == 0:
            return n
        else:
            gcd(n, m%n)
