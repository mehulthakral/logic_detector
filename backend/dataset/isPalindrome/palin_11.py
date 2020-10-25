class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
		# always false if negative
        if x < 0:
            return False
        arr = []
        while x != 0:
            x, r = divmod(x, 10) # Divide by 10, see the remainder
            arr.append(r)
        return arr==arr[::-1]