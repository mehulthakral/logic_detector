 class Solution:
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num==1:
            return True
        if num<1:
            return False
        while num>1:
            change=False
            for i in [2,3,5]:
                if not num%i:
                    num/=i
                    change=True
            if not change:
                return False
        return num==1