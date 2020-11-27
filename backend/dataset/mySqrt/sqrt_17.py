class Solution:
    def mySqrt(self, x:int)->int:
        """
        :type x: int
        :rtype: int
        """
        if x < 2:
            return x

        min_val = 0
        max_val = x
        new_x = x // 2

        while new_x != min_val:
            if x < new_x ** 2:
                max_val = new_x
            elif x > new_x ** 2:
                min_val = new_x
            else:
                return new_x
            new_x = (min_val + max_val) // 2
        return new_x
