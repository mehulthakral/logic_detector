class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return True
        if(num<1):
            return False
        n2 = num/self.maxd(num,2)
        if(n2 == 1):
            return True
        n3 = n2/self.maxd(num,3)
        if(n3 == 1):
            return True
        n5 = n3/self.maxd(num,5)
        if(n5 == 1):
            return True
        return False
        
        
        
    def maxd(self,num,n):
        count = 0
        while(num%n == 0):
            num = num/n
            count += 1
        return n**count
               
