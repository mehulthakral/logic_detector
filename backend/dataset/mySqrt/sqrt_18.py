# approach:
# (1) use left and right pointers to conduct a type of binary search
# (2) only difference is we maintain a refernce to the maximum number that has worked ...
# (3) ... as well as a reference the minimum number that has not worked
# (4) when those numbers are separated by one, we are done

class Solution:
    def mySqrt(self, x:int)->int:
        """
        :type x: int
        :rtype: int
        """
        # corner cases / bad inputs
        if x == 0:
            return 0

        if x < 0:
            return -2147483648

        l, r = 1, 1
        maximum, minimum = 0, x + 1
        while maximum < minimum - 1:
            if r * r <= x:
                maximum = r
                l = r
                r = min(2 * r, int((minimum + l) / 2))
            else:
                minimum = r
                r = int((l + r) / 2)

        return maximum
