class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        #n = (2**30)*(3**20)*(5**13) = 4570198050078720000000000000L
        return False if num < 1 or (4570198050078720000000000000L)%num != 0 else True
