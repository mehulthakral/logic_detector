## LOGIC : At each index we check maximum reacheable distance found till now and more forward, if we go to index where it is not in range of recheable distance we return False ##
class Solution:
    def canJump(self, nums: List[int]) -> bool:        
        maxDistReacheable = nums[0]
        for i in range(1,len(nums)):
            if(i > maxDistReacheable):
                return False
            maxDistReacheable = max( maxDistReacheable, i + nums[i] )
        return True
