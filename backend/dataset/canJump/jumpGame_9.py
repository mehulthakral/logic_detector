class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        ## RC ##
        ## APPROACH : DP ##
        ## LOGIC : At each index we calculate maximum reacheable distance found till now and more forward, if we go to index where it is not in range of recheable distance we return False ##
        
        # dp = [True] + [False] * (len(nums) - 1)                     # dp not required actually
        
        maxDistReacheable = nums[0]
        for i in range(1,len(nums)):
            if(i > maxDistReacheable):
                return False
            # dp[i] = True
            maxDistReacheable = max( maxDistReacheable, i + nums[i] )
        # return dp[-1]
        return True
